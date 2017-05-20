#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_StarLotteryCFG.h"
std::auto_ptr<M_StarLotteryCFG> M_StarLotteryCFG::msSingleton(nullptr);

int M_StarLotteryCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_StarLotteryCFGData* M_StarLotteryCFG::GetData(int Index)
{
	auto it = mMapData.find(Index);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_StarLotteryCFGData>& M_StarLotteryCFG::GetMapData()
{
	return mMapData;
}

void M_StarLotteryCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_StarLotteryCFG.xml");
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
		M_StarLotteryCFGData data;
		data.mIndex = element->IntAttribute("Index");
		data.mStarLvl = element->IntAttribute("StarLvl");
		data.mItemType = element->IntAttribute("ItemType");
		data.mItemCount = element->IntAttribute("ItemCount");
		data.mRate1 = element->IntAttribute("Rate1");
		data.mRate2 = element->IntAttribute("Rate2");
		data.mRate3 = element->IntAttribute("Rate3");
		data.mRate4 = element->IntAttribute("Rate4");
		if (mMapData.find(data.mIndex) != mMapData.end())std::cout <<"data refind:" << data.mIndex << std::endl;
		CCASSERT(mMapData.find(data.mIndex) == mMapData.end(), "data.mIndex is exists");
		mMapData.insert(std::make_pair(data.mIndex, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_StarLotteryCFG Loaded. Load Data:%u", mMapData.size());
}

void M_StarLotteryCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_StarLotteryCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_StarLotteryCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_StarLotteryCFGData data;
		LuaCfgHelper::readInt(L, "Index", data.mIndex);
		LuaCfgHelper::readInt(L, "StarLvl", data.mStarLvl);
		LuaCfgHelper::readInt(L, "ItemType", data.mItemType);
		LuaCfgHelper::readInt(L, "ItemCount", data.mItemCount);
		LuaCfgHelper::readInt(L, "Rate1", data.mRate1);
		LuaCfgHelper::readInt(L, "Rate2", data.mRate2);
		LuaCfgHelper::readInt(L, "Rate3", data.mRate3);
		LuaCfgHelper::readInt(L, "Rate4", data.mRate4);
		if (mMapData.find(data.mIndex) != mMapData.end())std::cout <<"data refind:" << data.mIndex << std::endl;
		CCASSERT(mMapData.find(data.mIndex) == mMapData.end(), "data.mIndex is exists");
		mMapData.insert(std::make_pair(data.mIndex, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_StarLotteryCFG Loaded. Load Data:%u", mMapData.size());
}

void M_StarLotteryCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_StarLotteryCFG* M_StarLotteryCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_StarLotteryCFG());
	}
	return msSingleton.get();
}

void M_StarLotteryCFG::Release()
{
	msSingleton.reset(nullptr);
}
