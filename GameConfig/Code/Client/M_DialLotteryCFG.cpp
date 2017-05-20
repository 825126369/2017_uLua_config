#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_DialLotteryCFG.h"
std::auto_ptr<M_DialLotteryCFG> M_DialLotteryCFG::msSingleton(nullptr);

int M_DialLotteryCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_DialLotteryCFGData* M_DialLotteryCFG::GetData(int ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_DialLotteryCFGData>& M_DialLotteryCFG::GetMapData()
{
	return mMapData;
}

void M_DialLotteryCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_DialLotteryCFG.xml");
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
		M_DialLotteryCFGData data;
		data.mID = element->IntAttribute("ID");
		data.mRewardCoin = element->IntAttribute("RewardCoin");
		data.mRewardType = element->IntAttribute("RewardType");
		data.mScale = element->FloatAttribute("Scale");
		data.mIcon = element->Attribute("Icon");
		data.mProbability = element->IntAttribute("Probability");
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_DialLotteryCFG Loaded. Load Data:%u", mMapData.size());
}

void M_DialLotteryCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_DialLotteryCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_DialLotteryCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_DialLotteryCFGData data;
		LuaCfgHelper::readInt(L, "ID", data.mID);
		LuaCfgHelper::readInt(L, "RewardCoin", data.mRewardCoin);
		LuaCfgHelper::readInt(L, "RewardType", data.mRewardType);
		LuaCfgHelper::readFloat(L, "Scale", data.mScale);
		LuaCfgHelper::readString(L, "Icon", data.mIcon);
		LuaCfgHelper::readInt(L, "Probability", data.mProbability);
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_DialLotteryCFG Loaded. Load Data:%u", mMapData.size());
}

void M_DialLotteryCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_DialLotteryCFG* M_DialLotteryCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_DialLotteryCFG());
	}
	return msSingleton.get();
}

void M_DialLotteryCFG::Release()
{
	msSingleton.reset(nullptr);
}
