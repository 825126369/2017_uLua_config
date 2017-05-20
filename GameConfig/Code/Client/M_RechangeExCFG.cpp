#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_RechangeExCFG.h"
std::auto_ptr<M_RechangeExCFG> M_RechangeExCFG::msSingleton(nullptr);

int M_RechangeExCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_RechangeExCFGData* M_RechangeExCFG::GetData(int ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_RechangeExCFGData>& M_RechangeExCFG::GetMapData()
{
	return mMapData;
}

void M_RechangeExCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_RechangeExCFG.xml");
	auto result = xmlDoc.Parse(content.c_str(), content.length());
	if (result != tinyxml2::XML_SUCCESS)
	{
		CCLOGERROR("Result:%d", result);
		CCASSERT(false, "result != tinyxml2::XML_SUCCESS");
		return;
	}
	auto root = xmlDoc.RootElement();
	if (root == NULL)
	{
		CCASSERT(false, "root == NULL");
		return;
	}
	auto element = root->FirstChildElement("Data");
	while (element != NULL)
	{
		M_RechangeExCFGData data;
		data.mID = element->IntAttribute("ID");
		{
			const char* PayCodes = element->Attribute("PayCodes");
			std::vector<std::string> vecPayCodes;
			boost::split(vecPayCodes, PayCodes, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecPayCodes.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecPayCodes[i].c_str(), &temp))
				{
					data.mPayCodes.push_back(temp);
				}
			}
		}
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_RechangeExCFG Loaded. Load Data:%u", mMapData.size());
}

void M_RechangeExCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_RechangeExCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_RechangeExCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_RechangeExCFGData data;
		LuaCfgHelper::readInt(L, "ID", data.mID);
		LuaCfgHelper::readVectorInt(L, "PayCodes", data.mPayCodes);
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_RechangeExCFG Loaded. Load Data:%u", mMapData.size());
}

void M_RechangeExCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_RechangeExCFG* M_RechangeExCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_RechangeExCFG());
	}
	return msSingleton.get();
}

void M_RechangeExCFG::Release()
{
	msSingleton.reset(nullptr);
}
