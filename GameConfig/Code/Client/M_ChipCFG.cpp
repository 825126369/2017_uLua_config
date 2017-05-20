#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_ChipCFG.h"
std::auto_ptr<M_ChipCFG> M_ChipCFG::msSingleton(nullptr);

int M_ChipCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_ChipCFGData* M_ChipCFG::GetData(int ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_ChipCFGData>& M_ChipCFG::GetMapData()
{
	return mMapData;
}

void M_ChipCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_ChipCFG.xml");
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
		M_ChipCFGData data;
		data.mID = element->IntAttribute("ID");
		data.mCount = element->IntAttribute("Count");
		data.mIcon = element->Attribute("Icon");
		data.mIsCheck = element->BoolAttribute("IsCheck");
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_ChipCFG Loaded. Load Data:%u", mMapData.size());
}

void M_ChipCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_ChipCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_ChipCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_ChipCFGData data;
		LuaCfgHelper::readInt(L, "ID", data.mID);
		LuaCfgHelper::readInt(L, "Count", data.mCount);
		LuaCfgHelper::readString(L, "Icon", data.mIcon);
		LuaCfgHelper::readBool(L, "IsCheck", data.mIsCheck);
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_ChipCFG Loaded. Load Data:%u", mMapData.size());
}

void M_ChipCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_ChipCFG* M_ChipCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_ChipCFG());
	}
	return msSingleton.get();
}

void M_ChipCFG::Release()
{
	msSingleton.reset(nullptr);
}
