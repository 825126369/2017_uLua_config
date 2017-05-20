#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_ActivityMultiLanguageCFG.h"
std::auto_ptr<M_ActivityMultiLanguageCFG> M_ActivityMultiLanguageCFG::msSingleton(nullptr);

int M_ActivityMultiLanguageCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_ActivityMultiLanguageCFGData* M_ActivityMultiLanguageCFG::GetData(std::string ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<std::string, M_ActivityMultiLanguageCFGData>& M_ActivityMultiLanguageCFG::GetMapData()
{
	return mMapData;
}

void M_ActivityMultiLanguageCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_ActivityMultiLanguageCFG.xml");
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
		M_ActivityMultiLanguageCFGData data;
		data.mID = element->Attribute("ID");
		data.mName = element->Attribute("Name");
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_ActivityMultiLanguageCFG Loaded. Load Data:%u", mMapData.size());
}

void M_ActivityMultiLanguageCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_ActivityMultiLanguageCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_ActivityMultiLanguageCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_ActivityMultiLanguageCFGData data;
		LuaCfgHelper::readString(L, "ID", data.mID);
		LuaCfgHelper::readString(L, "Name", data.mName);
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_ActivityMultiLanguageCFG Loaded. Load Data:%u", mMapData.size());
}

void M_ActivityMultiLanguageCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_ActivityMultiLanguageCFG* M_ActivityMultiLanguageCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_ActivityMultiLanguageCFG());
	}
	return msSingleton.get();
}

void M_ActivityMultiLanguageCFG::Release()
{
	msSingleton.reset(nullptr);
}
