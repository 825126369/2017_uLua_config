#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "HappySupremacy_RobCFG.h"
std::auto_ptr<HappySupremacy_RobCFG> HappySupremacy_RobCFG::msSingleton(nullptr);

int HappySupremacy_RobCFG::GetCount()
{
	return (int)mMapData.size();
}

const HappySupremacy_RobCFGData* HappySupremacy_RobCFG::GetData(int ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, HappySupremacy_RobCFGData>& HappySupremacy_RobCFG::GetMapData()
{
	return mMapData;
}

void HappySupremacy_RobCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/HappySupremacy_RobCFG.xml");
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
		HappySupremacy_RobCFGData data;
		data.mID = element->IntAttribute("ID");
		data.mName = element->Attribute("Name");
		data.mGoldMin = element->IntAttribute("GoldMin");
		data.mGoldMax = element->IntAttribute("GoldMax");
		data.mVipMin = element->IntAttribute("VipMin");
		data.mVipMax = element->IntAttribute("VipMax");
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("HappySupremacy_RobCFG Loaded. Load Data:%u", mMapData.size());
}

void HappySupremacy_RobCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("Config/HappySupremacy_RobCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "HappySupremacy_RobCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		HappySupremacy_RobCFGData data;
		LuaCfgHelper::readInt(L, "ID", data.mID);
		LuaCfgHelper::readString(L, "Name", data.mName);
		LuaCfgHelper::readInt(L, "GoldMin", data.mGoldMin);
		LuaCfgHelper::readInt(L, "GoldMax", data.mGoldMax);
		LuaCfgHelper::readInt(L, "VipMin", data.mVipMin);
		LuaCfgHelper::readInt(L, "VipMax", data.mVipMax);
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("HappySupremacy_RobCFG Loaded. Load Data:%u", mMapData.size());
}

void HappySupremacy_RobCFG::Reload()
{
	mMapData.clear();
	Load();
}

HappySupremacy_RobCFG* HappySupremacy_RobCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new HappySupremacy_RobCFG());
	}
	return msSingleton.get();
}
