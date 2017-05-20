#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "HappySupremacy_RateCFG.h"
std::auto_ptr<HappySupremacy_RateCFG> HappySupremacy_RateCFG::msSingleton(nullptr);

int HappySupremacy_RateCFG::GetCount()
{
	return (int)mMapData.size();
}

const HappySupremacy_RateCFGData* HappySupremacy_RateCFG::GetData(int Key)
{
	auto it = mMapData.find(Key);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, HappySupremacy_RateCFGData>& HappySupremacy_RateCFG::GetMapData()
{
	return mMapData;
}

void HappySupremacy_RateCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/HappySupremacy_RateCFG.xml");
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
		HappySupremacy_RateCFGData data;
		data.mKey = element->IntAttribute("Key");
		data.mName = element->Attribute("Name");
		data.mRate1 = element->IntAttribute("Rate1");
		data.mRate2 = element->IntAttribute("Rate2");
		if (mMapData.find(data.mKey) != mMapData.end())std::cout <<"data refind:" << data.mKey << std::endl;
		CCASSERT(mMapData.find(data.mKey) == mMapData.end(), "data.mKey is exists");
		mMapData.insert(std::make_pair(data.mKey, data));
		element = element->NextSiblingElement();
	}
	CCLOG("HappySupremacy_RateCFG Loaded. Load Data:%u", mMapData.size());
}

void HappySupremacy_RateCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("Config/HappySupremacy_RateCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "HappySupremacy_RateCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		HappySupremacy_RateCFGData data;
		LuaCfgHelper::readInt(L, "Key", data.mKey);
		LuaCfgHelper::readString(L, "Name", data.mName);
		LuaCfgHelper::readInt(L, "Rate1", data.mRate1);
		LuaCfgHelper::readInt(L, "Rate2", data.mRate2);
		if (mMapData.find(data.mKey) != mMapData.end())std::cout <<"data refind:" << data.mKey << std::endl;
		CCASSERT(mMapData.find(data.mKey) == mMapData.end(), "data.mKey is exists");
		mMapData.insert(std::make_pair(data.mKey, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("HappySupremacy_RateCFG Loaded. Load Data:%u", mMapData.size());
}

void HappySupremacy_RateCFG::Reload()
{
	mMapData.clear();
	Load();
}

HappySupremacy_RateCFG* HappySupremacy_RateCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new HappySupremacy_RateCFG());
	}
	return msSingleton.get();
}
