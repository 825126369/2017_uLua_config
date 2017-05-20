#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_RechangeLotteryCFG.h"
std::auto_ptr<M_RechangeLotteryCFG> M_RechangeLotteryCFG::msSingleton(nullptr);

int M_RechangeLotteryCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_RechangeLotteryCFGData* M_RechangeLotteryCFG::GetData(int Much)
{
	auto it = mMapData.find(Much);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_RechangeLotteryCFGData>& M_RechangeLotteryCFG::GetMapData()
{
	return mMapData;
}

void M_RechangeLotteryCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_RechangeLotteryCFG.xml");
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
		M_RechangeLotteryCFGData data;
		data.mMuch = element->IntAttribute("Much");
		data.mFirstRate = element->IntAttribute("FirstRate");
		data.mDefaultRate = element->IntAttribute("DefaultRate");
		if (mMapData.find(data.mMuch) != mMapData.end())std::cout <<"data refind:" << data.mMuch << std::endl;
		CCASSERT(mMapData.find(data.mMuch) == mMapData.end(), "data.mMuch is exists");
		mMapData.insert(std::make_pair(data.mMuch, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_RechangeLotteryCFG Loaded. Load Data:%u", mMapData.size());
}

void M_RechangeLotteryCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_RechangeLotteryCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_RechangeLotteryCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_RechangeLotteryCFGData data;
		LuaCfgHelper::readInt(L, "Much", data.mMuch);
		LuaCfgHelper::readInt(L, "FirstRate", data.mFirstRate);
		LuaCfgHelper::readInt(L, "DefaultRate", data.mDefaultRate);
		if (mMapData.find(data.mMuch) != mMapData.end())std::cout <<"data refind:" << data.mMuch << std::endl;
		CCASSERT(mMapData.find(data.mMuch) == mMapData.end(), "data.mMuch is exists");
		mMapData.insert(std::make_pair(data.mMuch, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_RechangeLotteryCFG Loaded. Load Data:%u", mMapData.size());
}

void M_RechangeLotteryCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_RechangeLotteryCFG* M_RechangeLotteryCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_RechangeLotteryCFG());
	}
	return msSingleton.get();
}

void M_RechangeLotteryCFG::Release()
{
	msSingleton.reset(nullptr);
}
