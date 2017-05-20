#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_ExchangeCFG.h"
std::auto_ptr<M_ExchangeCFG> M_ExchangeCFG::msSingleton(nullptr);

int M_ExchangeCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_ExchangeCFGData* M_ExchangeCFG::GetData(int ChangeId)
{
	auto it = mMapData.find(ChangeId);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_ExchangeCFGData>& M_ExchangeCFG::GetMapData()
{
	return mMapData;
}

void M_ExchangeCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_ExchangeCFG.xml");
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
		M_ExchangeCFGData data;
		data.mChangeId = element->IntAttribute("ChangeId");
		data.mCostTicket = element->IntAttribute("CostTicket");
		data.mItemId = element->IntAttribute("ItemId");
		data.mVip = element->IntAttribute("Vip");
		data.mItemIcon = element->Attribute("ItemIcon");
		data.mItemName = element->Attribute("ItemName");
		data.mItemCount = element->IntAttribute("ItemCount");
		if (mMapData.find(data.mChangeId) != mMapData.end())std::cout <<"data refind:" << data.mChangeId << std::endl;
		CCASSERT(mMapData.find(data.mChangeId) == mMapData.end(), "data.mChangeId is exists");
		mMapData.insert(std::make_pair(data.mChangeId, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_ExchangeCFG Loaded. Load Data:%u", mMapData.size());
}

void M_ExchangeCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_ExchangeCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_ExchangeCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_ExchangeCFGData data;
		LuaCfgHelper::readInt(L, "ChangeId", data.mChangeId);
		LuaCfgHelper::readInt(L, "CostTicket", data.mCostTicket);
		LuaCfgHelper::readInt(L, "ItemId", data.mItemId);
		LuaCfgHelper::readInt(L, "Vip", data.mVip);
		LuaCfgHelper::readString(L, "ItemIcon", data.mItemIcon);
		LuaCfgHelper::readString(L, "ItemName", data.mItemName);
		LuaCfgHelper::readInt(L, "ItemCount", data.mItemCount);
		if (mMapData.find(data.mChangeId) != mMapData.end())std::cout <<"data refind:" << data.mChangeId << std::endl;
		CCASSERT(mMapData.find(data.mChangeId) == mMapData.end(), "data.mChangeId is exists");
		mMapData.insert(std::make_pair(data.mChangeId, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_ExchangeCFG Loaded. Load Data:%u", mMapData.size());
}

void M_ExchangeCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_ExchangeCFG* M_ExchangeCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_ExchangeCFG());
	}
	return msSingleton.get();
}

void M_ExchangeCFG::Release()
{
	msSingleton.reset(nullptr);
}
