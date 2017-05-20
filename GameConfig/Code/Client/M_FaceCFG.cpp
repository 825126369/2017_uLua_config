#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_FaceCFG.h"
std::auto_ptr<M_FaceCFG> M_FaceCFG::msSingleton(nullptr);

int M_FaceCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_FaceCFGData* M_FaceCFG::GetData(int ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_FaceCFGData>& M_FaceCFG::GetMapData()
{
	return mMapData;
}

void M_FaceCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_FaceCFG.xml");
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
		M_FaceCFGData data;
		data.mID = element->IntAttribute("ID");
		data.mName = element->Attribute("Name");
		data.mIcon = element->Attribute("Icon");
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_FaceCFG Loaded. Load Data:%u", mMapData.size());
}

void M_FaceCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_FaceCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_FaceCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_FaceCFGData data;
		LuaCfgHelper::readInt(L, "ID", data.mID);
		LuaCfgHelper::readString(L, "Name", data.mName);
		LuaCfgHelper::readString(L, "Icon", data.mIcon);
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_FaceCFG Loaded. Load Data:%u", mMapData.size());
}

void M_FaceCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_FaceCFG* M_FaceCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_FaceCFG());
	}
	return msSingleton.get();
}

void M_FaceCFG::Release()
{
	msSingleton.reset(nullptr);
}
