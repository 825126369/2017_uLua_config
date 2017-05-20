#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_BaseInfoCFG.h"
std::auto_ptr<M_BaseInfoCFG> M_BaseInfoCFG::msSingleton(nullptr);

int M_BaseInfoCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_BaseInfoCFGData* M_BaseInfoCFG::GetData(std::string Key)
{
	auto it = mMapData.find(Key);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<std::string, M_BaseInfoCFGData>& M_BaseInfoCFG::GetMapData()
{
	return mMapData;
}

void M_BaseInfoCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_BaseInfoCFG.xml");
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
		M_BaseInfoCFGData data;
		data.mKey = element->Attribute("Key");
		data.mValue = element->IntAttribute("Value");
		if (mMapData.find(data.mKey) != mMapData.end())std::cout <<"data refind:" << data.mKey << std::endl;
		CCASSERT(mMapData.find(data.mKey) == mMapData.end(), "data.mKey is exists");
		mMapData.insert(std::make_pair(data.mKey, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_BaseInfoCFG Loaded. Load Data:%u", mMapData.size());
}

void M_BaseInfoCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_BaseInfoCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_BaseInfoCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_BaseInfoCFGData data;
		LuaCfgHelper::readString(L, "Key", data.mKey);
		LuaCfgHelper::readInt(L, "Value", data.mValue);
		if (mMapData.find(data.mKey) != mMapData.end())std::cout <<"data refind:" << data.mKey << std::endl;
		CCASSERT(mMapData.find(data.mKey) == mMapData.end(), "data.mKey is exists");
		mMapData.insert(std::make_pair(data.mKey, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_BaseInfoCFG Loaded. Load Data:%u", mMapData.size());
}

void M_BaseInfoCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_BaseInfoCFG* M_BaseInfoCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_BaseInfoCFG());
	}
	return msSingleton.get();
}

void M_BaseInfoCFG::Release()
{
	msSingleton.reset(nullptr);
}
