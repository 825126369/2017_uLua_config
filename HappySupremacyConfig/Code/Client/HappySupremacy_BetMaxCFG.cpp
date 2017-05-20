#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "HappySupremacy_BetMaxCFG.h"
std::auto_ptr<HappySupremacy_BetMaxCFG> HappySupremacy_BetMaxCFG::msSingleton(nullptr);

int HappySupremacy_BetMaxCFG::GetCount()
{
	return (int)mMapData.size();
}

const HappySupremacy_BetMaxCFGData* HappySupremacy_BetMaxCFG::GetData(int ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, HappySupremacy_BetMaxCFGData>& HappySupremacy_BetMaxCFG::GetMapData()
{
	return mMapData;
}

void HappySupremacy_BetMaxCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/HappySupremacy_BetMaxCFG.xml");
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
		HappySupremacy_BetMaxCFGData data;
		data.mID = element->IntAttribute("ID");
		data.mGoldCount = element->IntAttribute("GoldCount");
		data.mBetMax = element->IntAttribute("BetMax");
		{
			const char* CanUseWeight = element->Attribute("CanUseWeight");
			std::vector<std::string> vecCanUseWeight;
			boost::split(vecCanUseWeight, CanUseWeight, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecCanUseWeight.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecCanUseWeight[i].c_str(), &temp))
				{
					data.mCanUseWeight.push_back(temp);
				}
			}
		}
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("HappySupremacy_BetMaxCFG Loaded. Load Data:%u", mMapData.size());
}

void HappySupremacy_BetMaxCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("Config/HappySupremacy_BetMaxCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "HappySupremacy_BetMaxCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		HappySupremacy_BetMaxCFGData data;
		LuaCfgHelper::readInt(L, "ID", data.mID);
		LuaCfgHelper::readInt(L, "GoldCount", data.mGoldCount);
		LuaCfgHelper::readInt(L, "BetMax", data.mBetMax);
		LuaCfgHelper::readVectorInt(L, "CanUseWeight", data.mCanUseWeight);
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("HappySupremacy_BetMaxCFG Loaded. Load Data:%u", mMapData.size());
}

void HappySupremacy_BetMaxCFG::Reload()
{
	mMapData.clear();
	Load();
}

HappySupremacy_BetMaxCFG* HappySupremacy_BetMaxCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new HappySupremacy_BetMaxCFG());
	}
	return msSingleton.get();
}
