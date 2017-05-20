#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_ThirdPluginCFG.h"
std::auto_ptr<M_ThirdPluginCFG> M_ThirdPluginCFG::msSingleton(nullptr);

int M_ThirdPluginCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_ThirdPluginCFGData* M_ThirdPluginCFG::GetData(std::string ChannelID)
{
	auto it = mMapData.find(ChannelID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<std::string, M_ThirdPluginCFGData>& M_ThirdPluginCFG::GetMapData()
{
	return mMapData;
}

void M_ThirdPluginCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_ThirdPluginCFG.xml");
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
		M_ThirdPluginCFGData data;
		data.mChannelID = element->Attribute("ChannelID");
		data.mPlatform = element->Attribute("Platform");
		data.mLuaFilePath = element->Attribute("LuaFilePath");
		data.mRemark = element->Attribute("Remark");
		if (mMapData.find(data.mChannelID) != mMapData.end())std::cout <<"data refind:" << data.mChannelID << std::endl;
		CCASSERT(mMapData.find(data.mChannelID) == mMapData.end(), "data.mChannelID is exists");
		mMapData.insert(std::make_pair(data.mChannelID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_ThirdPluginCFG Loaded. Load Data:%u", mMapData.size());
}

void M_ThirdPluginCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_ThirdPluginCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_ThirdPluginCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_ThirdPluginCFGData data;
		LuaCfgHelper::readString(L, "ChannelID", data.mChannelID);
		LuaCfgHelper::readString(L, "Platform", data.mPlatform);
		LuaCfgHelper::readString(L, "LuaFilePath", data.mLuaFilePath);
		LuaCfgHelper::readString(L, "Remark", data.mRemark);
		if (mMapData.find(data.mChannelID) != mMapData.end())std::cout <<"data refind:" << data.mChannelID << std::endl;
		CCASSERT(mMapData.find(data.mChannelID) == mMapData.end(), "data.mChannelID is exists");
		mMapData.insert(std::make_pair(data.mChannelID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_ThirdPluginCFG Loaded. Load Data:%u", mMapData.size());
}

void M_ThirdPluginCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_ThirdPluginCFG* M_ThirdPluginCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_ThirdPluginCFG());
	}
	return msSingleton.get();
}

void M_ThirdPluginCFG::Release()
{
	msSingleton.reset(nullptr);
}
