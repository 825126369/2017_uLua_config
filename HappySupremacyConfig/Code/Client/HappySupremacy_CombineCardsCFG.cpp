#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "HappySupremacy_CombineCardsCFG.h"
std::auto_ptr<HappySupremacy_CombineCardsCFG> HappySupremacy_CombineCardsCFG::msSingleton(nullptr);

int HappySupremacy_CombineCardsCFG::GetCount()
{
	return (int)mMapData.size();
}

const HappySupremacy_CombineCardsCFGData* HappySupremacy_CombineCardsCFG::GetData(int CombineCardID)
{
	auto it = mMapData.find(CombineCardID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, HappySupremacy_CombineCardsCFGData>& HappySupremacy_CombineCardsCFG::GetMapData()
{
	return mMapData;
}

void HappySupremacy_CombineCardsCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/HappySupremacy_CombineCardsCFG.xml");
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
		HappySupremacy_CombineCardsCFGData data;
		data.mCombineCardID = element->IntAttribute("CombineCardID");
		data.mCombineCardsName = element->Attribute("CombineCardsName");
		if (mMapData.find(data.mCombineCardID) != mMapData.end())std::cout <<"data refind:" << data.mCombineCardID << std::endl;
		CCASSERT(mMapData.find(data.mCombineCardID) == mMapData.end(), "data.mCombineCardID is exists");
		mMapData.insert(std::make_pair(data.mCombineCardID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("HappySupremacy_CombineCardsCFG Loaded. Load Data:%u", mMapData.size());
}

void HappySupremacy_CombineCardsCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("Config/HappySupremacy_CombineCardsCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "HappySupremacy_CombineCardsCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		HappySupremacy_CombineCardsCFGData data;
		LuaCfgHelper::readInt(L, "CombineCardID", data.mCombineCardID);
		LuaCfgHelper::readString(L, "CombineCardsName", data.mCombineCardsName);
		if (mMapData.find(data.mCombineCardID) != mMapData.end())std::cout <<"data refind:" << data.mCombineCardID << std::endl;
		CCASSERT(mMapData.find(data.mCombineCardID) == mMapData.end(), "data.mCombineCardID is exists");
		mMapData.insert(std::make_pair(data.mCombineCardID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("HappySupremacy_CombineCardsCFG Loaded. Load Data:%u", mMapData.size());
}

void HappySupremacy_CombineCardsCFG::Reload()
{
	mMapData.clear();
	Load();
}

HappySupremacy_CombineCardsCFG* HappySupremacy_CombineCardsCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new HappySupremacy_CombineCardsCFG());
	}
	return msSingleton.get();
}
