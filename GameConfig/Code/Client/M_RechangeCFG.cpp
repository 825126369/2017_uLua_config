#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_RechangeCFG.h"
std::auto_ptr<M_RechangeCFG> M_RechangeCFG::msSingleton(nullptr);

int M_RechangeCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_RechangeCFGData* M_RechangeCFG::GetData(int ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_RechangeCFGData>& M_RechangeCFG::GetMapData()
{
	return mMapData;
}

void M_RechangeCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_RechangeCFG.xml");
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
		M_RechangeCFGData data;
		data.mID = element->IntAttribute("ID");
		data.mName = element->Attribute("Name");
		data.mDesc = element->Attribute("Desc");
		data.mNameIcon = element->Attribute("NameIcon");
		data.mIcon = element->Attribute("Icon");
		data.mPayType = element->IntAttribute("PayType");
		data.mType = element->IntAttribute("Type");
		data.mPrice = element->IntAttribute("Price");
		data.mGold = element->IntAttribute("Gold");
		data.mFirstGold = element->IntAttribute("FirstGold");
		data.mGiveGold = element->IntAttribute("GiveGold");
		data.mGiveTicket = element->IntAttribute("GiveTicket");
		data.mVIPExp = element->IntAttribute("VIPExp");
		data.mIndex = element->IntAttribute("Index");
		data.mShopType = element->IntAttribute("ShopType");
		data.mFlag = element->BoolAttribute("Flag");
		data.mAppStoreID = element->Attribute("AppStoreID");
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_RechangeCFG Loaded. Load Data:%u", mMapData.size());
}

void M_RechangeCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_RechangeCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_RechangeCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_RechangeCFGData data;
		LuaCfgHelper::readInt(L, "ID", data.mID);
		LuaCfgHelper::readString(L, "Name", data.mName);
		LuaCfgHelper::readString(L, "Desc", data.mDesc);
		LuaCfgHelper::readString(L, "NameIcon", data.mNameIcon);
		LuaCfgHelper::readString(L, "Icon", data.mIcon);
		LuaCfgHelper::readInt(L, "PayType", data.mPayType);
		LuaCfgHelper::readInt(L, "Type", data.mType);
		LuaCfgHelper::readInt(L, "Price", data.mPrice);
		LuaCfgHelper::readInt(L, "Gold", data.mGold);
		LuaCfgHelper::readInt(L, "FirstGold", data.mFirstGold);
		LuaCfgHelper::readInt(L, "GiveGold", data.mGiveGold);
		LuaCfgHelper::readInt(L, "GiveTicket", data.mGiveTicket);
		LuaCfgHelper::readInt(L, "VIPExp", data.mVIPExp);
		LuaCfgHelper::readInt(L, "Index", data.mIndex);
		LuaCfgHelper::readInt(L, "ShopType", data.mShopType);
		LuaCfgHelper::readBool(L, "Flag", data.mFlag);
		LuaCfgHelper::readString(L, "AppStoreID", data.mAppStoreID);
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_RechangeCFG Loaded. Load Data:%u", mMapData.size());
}

void M_RechangeCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_RechangeCFG* M_RechangeCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_RechangeCFG());
	}
	return msSingleton.get();
}

void M_RechangeCFG::Release()
{
	msSingleton.reset(nullptr);
}
