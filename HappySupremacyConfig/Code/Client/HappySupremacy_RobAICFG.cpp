#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "HappySupremacy_RobAICFG.h"
std::auto_ptr<HappySupremacy_RobAICFG> HappySupremacy_RobAICFG::msSingleton(nullptr);

int HappySupremacy_RobAICFG::GetCount()
{
	return (int)mMapData.size();
}

const HappySupremacy_RobAICFGData* HappySupremacy_RobAICFG::GetData(int ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, HappySupremacy_RobAICFGData>& HappySupremacy_RobAICFG::GetMapData()
{
	return mMapData;
}

void HappySupremacy_RobAICFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/HappySupremacy_RobAICFG.xml");
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
		HappySupremacy_RobAICFGData data;
		data.mID = element->IntAttribute("ID");
		data.mBetName = element->Attribute("BetName");
		{
			const char* BetRate = element->Attribute("BetRate");
			std::vector<std::string> vecBetRate;
			boost::split(vecBetRate, BetRate, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecBetRate.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecBetRate[i].c_str(), &temp))
				{
					data.mBetRate.push_back(temp);
				}
			}
		}
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("HappySupremacy_RobAICFG Loaded. Load Data:%u", mMapData.size());
}

void HappySupremacy_RobAICFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("Config/HappySupremacy_RobAICFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "HappySupremacy_RobAICFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		HappySupremacy_RobAICFGData data;
		LuaCfgHelper::readInt(L, "ID", data.mID);
		LuaCfgHelper::readString(L, "BetName", data.mBetName);
		LuaCfgHelper::readVectorInt(L, "BetRate", data.mBetRate);
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("HappySupremacy_RobAICFG Loaded. Load Data:%u", mMapData.size());
}

void HappySupremacy_RobAICFG::Reload()
{
	mMapData.clear();
	Load();
}

HappySupremacy_RobAICFG* HappySupremacy_RobAICFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new HappySupremacy_RobAICFG());
	}
	return msSingleton.get();
}
