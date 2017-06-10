#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_RobotHeadIconCFG.h"
std::auto_ptr<M_RobotHeadIconCFG> M_RobotHeadIconCFG::msSingleton(nullptr);

int M_RobotHeadIconCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_RobotHeadIconCFGData* M_RobotHeadIconCFG::GetData(int Index)
{
	auto it = mMapData.find(Index);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_RobotHeadIconCFGData>& M_RobotHeadIconCFG::GetMapData()
{
	return mMapData;
}

void M_RobotHeadIconCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_RobotHeadIconCFG.xml");
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
		M_RobotHeadIconCFGData data;
		data.mIndex = element->IntAttribute("Index");
		data.mboyIcon_MinIndex = element->IntAttribute("boyIcon_MinIndex");
		data.mgirlIcon = element->IntAttribute("girlIcon");
		if (mMapData.find(data.mIndex) != mMapData.end())std::cout <<"data refind:" << data.mIndex << std::endl;
		CCASSERT(mMapData.find(data.mIndex) == mMapData.end(), "data.mIndex is exists");
		mMapData.insert(std::make_pair(data.mIndex, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_RobotHeadIconCFG Loaded. Load Data:%u", mMapData.size());
}

void M_RobotHeadIconCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_RobotHeadIconCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_RobotHeadIconCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_RobotHeadIconCFGData data;
		LuaCfgHelper::readInt(L, "Index", data.mIndex);
		LuaCfgHelper::readInt(L, "boyIcon_MinIndex", data.mboyIcon_MinIndex);
		LuaCfgHelper::readInt(L, "girlIcon", data.mgirlIcon);
		if (mMapData.find(data.mIndex) != mMapData.end())std::cout <<"data refind:" << data.mIndex << std::endl;
		CCASSERT(mMapData.find(data.mIndex) == mMapData.end(), "data.mIndex is exists");
		mMapData.insert(std::make_pair(data.mIndex, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_RobotHeadIconCFG Loaded. Load Data:%u", mMapData.size());
}

void M_RobotHeadIconCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_RobotHeadIconCFG* M_RobotHeadIconCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_RobotHeadIconCFG());
	}
	return msSingleton.get();
}

void M_RobotHeadIconCFG::Release()
{
	msSingleton.reset(nullptr);
}
