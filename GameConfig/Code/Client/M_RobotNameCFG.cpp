#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_RobotNameCFG.h"
std::auto_ptr<M_RobotNameCFG> M_RobotNameCFG::msSingleton(nullptr);

int M_RobotNameCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_RobotNameCFGData* M_RobotNameCFG::GetData(int Index)
{
	auto it = mMapData.find(Index);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_RobotNameCFGData>& M_RobotNameCFG::GetMapData()
{
	return mMapData;
}

void M_RobotNameCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_RobotNameCFG.xml");
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
		M_RobotNameCFGData data;
		data.mIndex = element->IntAttribute("Index");
		data.mNickName = element->Attribute("NickName");
		if (mMapData.find(data.mIndex) != mMapData.end())std::cout <<"data refind:" << data.mIndex << std::endl;
		CCASSERT(mMapData.find(data.mIndex) == mMapData.end(), "data.mIndex is exists");
		mMapData.insert(std::make_pair(data.mIndex, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_RobotNameCFG Loaded. Load Data:%u", mMapData.size());
}

void M_RobotNameCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_RobotNameCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_RobotNameCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_RobotNameCFGData data;
		LuaCfgHelper::readInt(L, "Index", data.mIndex);
		LuaCfgHelper::readString(L, "NickName", data.mNickName);
		if (mMapData.find(data.mIndex) != mMapData.end())std::cout <<"data refind:" << data.mIndex << std::endl;
		CCASSERT(mMapData.find(data.mIndex) == mMapData.end(), "data.mIndex is exists");
		mMapData.insert(std::make_pair(data.mIndex, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_RobotNameCFG Loaded. Load Data:%u", mMapData.size());
}

void M_RobotNameCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_RobotNameCFG* M_RobotNameCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_RobotNameCFG());
	}
	return msSingleton.get();
}

void M_RobotNameCFG::Release()
{
	msSingleton.reset(nullptr);
}
