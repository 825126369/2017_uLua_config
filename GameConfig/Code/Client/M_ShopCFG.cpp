#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_ShopCFG.h"
std::auto_ptr<M_ShopCFG> M_ShopCFG::msSingleton(nullptr);

int M_ShopCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_ShopCFGData* M_ShopCFG::GetData(int ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_ShopCFGData>& M_ShopCFG::GetMapData()
{
	return mMapData;
}

void M_ShopCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_ShopCFG.xml");
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
		M_ShopCFGData data;
		data.mID = element->IntAttribute("ID");
		data.mName = element->Attribute("Name");
		data.mDesc = element->Attribute("Desc");
		data.mNameIcon = element->Attribute("NameIcon");
		data.mIcon = element->Attribute("Icon");
		data.mType = element->IntAttribute("Type");
		data.mPrice = element->IntAttribute("Price");
		data.mGold = element->IntAttribute("Gold");
		data.mIndex = element->IntAttribute("Index");
		data.mShopType = element->IntAttribute("ShopType");
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_ShopCFG Loaded. Load Data:%u", mMapData.size());
}

void M_ShopCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_ShopCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_ShopCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_ShopCFGData data;
		LuaCfgHelper::readInt(L, "ID", data.mID);
		LuaCfgHelper::readString(L, "Name", data.mName);
		LuaCfgHelper::readString(L, "Desc", data.mDesc);
		LuaCfgHelper::readString(L, "NameIcon", data.mNameIcon);
		LuaCfgHelper::readString(L, "Icon", data.mIcon);
		LuaCfgHelper::readInt(L, "Type", data.mType);
		LuaCfgHelper::readInt(L, "Price", data.mPrice);
		LuaCfgHelper::readInt(L, "Gold", data.mGold);
		LuaCfgHelper::readInt(L, "Index", data.mIndex);
		LuaCfgHelper::readInt(L, "ShopType", data.mShopType);
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_ShopCFG Loaded. Load Data:%u", mMapData.size());
}

void M_ShopCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_ShopCFG* M_ShopCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_ShopCFG());
	}
	return msSingleton.get();
}

void M_ShopCFG::Release()
{
	msSingleton.reset(nullptr);
}
