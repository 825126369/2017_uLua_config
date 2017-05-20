#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_ItemCFG.h"
std::auto_ptr<M_ItemCFG> M_ItemCFG::msSingleton(nullptr);

int M_ItemCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_ItemCFGData* M_ItemCFG::GetData(int ItemId)
{
	auto it = mMapData.find(ItemId);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_ItemCFGData>& M_ItemCFG::GetMapData()
{
	return mMapData;
}

void M_ItemCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_ItemCFG.xml");
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
		M_ItemCFGData data;
		data.mItemId = element->IntAttribute("ItemId");
		data.mItemName = element->Attribute("ItemName");
		data.mItemDesc = element->Attribute("ItemDesc");
		data.mIcon = element->Attribute("Icon");
		data.mItemCategory = element->IntAttribute("ItemCategory");
		data.mItemValue = element->IntAttribute("ItemValue");
		if (mMapData.find(data.mItemId) != mMapData.end())std::cout <<"data refind:" << data.mItemId << std::endl;
		CCASSERT(mMapData.find(data.mItemId) == mMapData.end(), "data.mItemId is exists");
		mMapData.insert(std::make_pair(data.mItemId, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_ItemCFG Loaded. Load Data:%u", mMapData.size());
}

void M_ItemCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_ItemCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_ItemCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_ItemCFGData data;
		LuaCfgHelper::readInt(L, "ItemId", data.mItemId);
		LuaCfgHelper::readString(L, "ItemName", data.mItemName);
		LuaCfgHelper::readString(L, "ItemDesc", data.mItemDesc);
		LuaCfgHelper::readString(L, "Icon", data.mIcon);
		LuaCfgHelper::readInt(L, "ItemCategory", data.mItemCategory);
		LuaCfgHelper::readInt(L, "ItemValue", data.mItemValue);
		if (mMapData.find(data.mItemId) != mMapData.end())std::cout <<"data refind:" << data.mItemId << std::endl;
		CCASSERT(mMapData.find(data.mItemId) == mMapData.end(), "data.mItemId is exists");
		mMapData.insert(std::make_pair(data.mItemId, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_ItemCFG Loaded. Load Data:%u", mMapData.size());
}

void M_ItemCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_ItemCFG* M_ItemCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_ItemCFG());
	}
	return msSingleton.get();
}

void M_ItemCFG::Release()
{
	msSingleton.reset(nullptr);
}
