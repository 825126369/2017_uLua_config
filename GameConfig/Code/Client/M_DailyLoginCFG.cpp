#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_DailyLoginCFG.h"
std::auto_ptr<M_DailyLoginCFG> M_DailyLoginCFG::msSingleton(nullptr);

int M_DailyLoginCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_DailyLoginCFGData* M_DailyLoginCFG::GetData(int ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_DailyLoginCFGData>& M_DailyLoginCFG::GetMapData()
{
	return mMapData;
}

void M_DailyLoginCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_DailyLoginCFG.xml");
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
		M_DailyLoginCFGData data;
		data.mID = element->IntAttribute("ID");
		data.mName = element->Attribute("Name");
		data.mTpye = element->IntAttribute("Tpye");
		data.mCount = element->IntAttribute("Count");
		data.mIcon = element->Attribute("Icon");
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_DailyLoginCFG Loaded. Load Data:%u", mMapData.size());
}

void M_DailyLoginCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_DailyLoginCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_DailyLoginCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_DailyLoginCFGData data;
		LuaCfgHelper::readInt(L, "ID", data.mID);
		LuaCfgHelper::readString(L, "Name", data.mName);
		LuaCfgHelper::readInt(L, "Tpye", data.mTpye);
		LuaCfgHelper::readInt(L, "Count", data.mCount);
		LuaCfgHelper::readString(L, "Icon", data.mIcon);
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_DailyLoginCFG Loaded. Load Data:%u", mMapData.size());
}

void M_DailyLoginCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_DailyLoginCFG* M_DailyLoginCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_DailyLoginCFG());
	}
	return msSingleton.get();
}

void M_DailyLoginCFG::Release()
{
	msSingleton.reset(nullptr);
}
