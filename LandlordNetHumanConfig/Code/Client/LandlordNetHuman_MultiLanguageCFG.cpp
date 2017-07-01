#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "LandlordNetHuman_MultiLanguageCFG.h"
std::auto_ptr<LandlordNetHuman_MultiLanguageCFG> LandlordNetHuman_MultiLanguageCFG::msSingleton(nullptr);

int LandlordNetHuman_MultiLanguageCFG::GetCount()
{
	return (int)mMapData.size();
}

const LandlordNetHuman_MultiLanguageCFGData* LandlordNetHuman_MultiLanguageCFG::GetData(std::string ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<std::string, LandlordNetHuman_MultiLanguageCFGData>& LandlordNetHuman_MultiLanguageCFG::GetMapData()
{
	return mMapData;
}

void LandlordNetHuman_MultiLanguageCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/LandlordNetHuman_MultiLanguageCFG.xml");
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
		LandlordNetHuman_MultiLanguageCFGData data;
		data.mID = element->Attribute("ID");
		data.mName = element->Attribute("Name");
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("LandlordNetHuman_MultiLanguageCFG Loaded. Load Data:%u", mMapData.size());
}

void LandlordNetHuman_MultiLanguageCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("Config/LandlordNetHuman_MultiLanguageCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "LandlordNetHuman_MultiLanguageCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		LandlordNetHuman_MultiLanguageCFGData data;
		LuaCfgHelper::readString(L, "ID", data.mID);
		LuaCfgHelper::readString(L, "Name", data.mName);
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("LandlordNetHuman_MultiLanguageCFG Loaded. Load Data:%u", mMapData.size());
}

void LandlordNetHuman_MultiLanguageCFG::Reload()
{
	mMapData.clear();
	Load();
}

LandlordNetHuman_MultiLanguageCFG* LandlordNetHuman_MultiLanguageCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new LandlordNetHuman_MultiLanguageCFG());
	}
	return msSingleton.get();
}
