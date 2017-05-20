#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_GiftCFG.h"
std::auto_ptr<M_GiftCFG> M_GiftCFG::msSingleton(nullptr);

int M_GiftCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_GiftCFGData* M_GiftCFG::GetData(int GiftId)
{
	auto it = mMapData.find(GiftId);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_GiftCFGData>& M_GiftCFG::GetMapData()
{
	return mMapData;
}

void M_GiftCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_GiftCFG.xml");
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
		M_GiftCFGData data;
		data.mGiftId = element->IntAttribute("GiftId");
		data.mCoin = element->IntAttribute("Coin");
		data.misShow = element->IntAttribute("isShow");
		data.mPercent = element->FloatAttribute("Percent");
		data.mVip = element->IntAttribute("Vip");
		data.mAction = element->Attribute("Action");
		data.mTextIcon = element->Attribute("TextIcon");
		if (mMapData.find(data.mGiftId) != mMapData.end())std::cout <<"data refind:" << data.mGiftId << std::endl;
		CCASSERT(mMapData.find(data.mGiftId) == mMapData.end(), "data.mGiftId is exists");
		mMapData.insert(std::make_pair(data.mGiftId, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_GiftCFG Loaded. Load Data:%u", mMapData.size());
}

void M_GiftCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_GiftCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_GiftCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_GiftCFGData data;
		LuaCfgHelper::readInt(L, "GiftId", data.mGiftId);
		LuaCfgHelper::readInt(L, "Coin", data.mCoin);
		LuaCfgHelper::readInt(L, "isShow", data.misShow);
		LuaCfgHelper::readFloat(L, "Percent", data.mPercent);
		LuaCfgHelper::readInt(L, "Vip", data.mVip);
		LuaCfgHelper::readString(L, "Action", data.mAction);
		LuaCfgHelper::readString(L, "TextIcon", data.mTextIcon);
		if (mMapData.find(data.mGiftId) != mMapData.end())std::cout <<"data refind:" << data.mGiftId << std::endl;
		CCASSERT(mMapData.find(data.mGiftId) == mMapData.end(), "data.mGiftId is exists");
		mMapData.insert(std::make_pair(data.mGiftId, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_GiftCFG Loaded. Load Data:%u", mMapData.size());
}

void M_GiftCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_GiftCFG* M_GiftCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_GiftCFG());
	}
	return msSingleton.get();
}

void M_GiftCFG::Release()
{
	msSingleton.reset(nullptr);
}
