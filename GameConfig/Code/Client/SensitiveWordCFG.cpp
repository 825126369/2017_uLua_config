#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "SensitiveWordCFG.h"
std::auto_ptr<SensitiveWordCFG> SensitiveWordCFG::msSingleton(nullptr);

int SensitiveWordCFG::GetCount()
{
	return (int)mMapData.size();
}

const SensitiveWordCFGData* SensitiveWordCFG::GetData(int ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, SensitiveWordCFGData>& SensitiveWordCFG::GetMapData()
{
	return mMapData;
}

void SensitiveWordCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/SensitiveWordCFG.xml");
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
		SensitiveWordCFGData data;
		data.mID = element->IntAttribute("ID");
		data.mSensitiveWord = element->Attribute("SensitiveWord");
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("SensitiveWordCFG Loaded. Load Data:%u", mMapData.size());
}

void SensitiveWordCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/SensitiveWordCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "SensitiveWordCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		SensitiveWordCFGData data;
		LuaCfgHelper::readInt(L, "ID", data.mID);
		LuaCfgHelper::readString(L, "SensitiveWord", data.mSensitiveWord);
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("SensitiveWordCFG Loaded. Load Data:%u", mMapData.size());
}

void SensitiveWordCFG::Reload()
{
	mMapData.clear();
	Load();
}

SensitiveWordCFG* SensitiveWordCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new SensitiveWordCFG());
	}
	return msSingleton.get();
}

void SensitiveWordCFG::Release()
{
	msSingleton.reset(nullptr);
}
