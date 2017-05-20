#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_OnlineRewardCFG.h"
std::auto_ptr<M_OnlineRewardCFG> M_OnlineRewardCFG::msSingleton(nullptr);

int M_OnlineRewardCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_OnlineRewardCFGData* M_OnlineRewardCFG::GetData(int ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_OnlineRewardCFGData>& M_OnlineRewardCFG::GetMapData()
{
	return mMapData;
}

void M_OnlineRewardCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_OnlineRewardCFG.xml");
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
		M_OnlineRewardCFGData data;
		data.mID = element->IntAttribute("ID");
		data.mStartTime = element->Attribute("StartTime");
		data.mEndTime = element->Attribute("EndTime");
		data.mConditionVip = element->IntAttribute("ConditionVip");
		data.mRewardCoin = element->IntAttribute("RewardCoin");
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_OnlineRewardCFG Loaded. Load Data:%u", mMapData.size());
}

void M_OnlineRewardCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_OnlineRewardCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_OnlineRewardCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_OnlineRewardCFGData data;
		LuaCfgHelper::readInt(L, "ID", data.mID);
		LuaCfgHelper::readString(L, "StartTime", data.mStartTime);
		LuaCfgHelper::readString(L, "EndTime", data.mEndTime);
		LuaCfgHelper::readInt(L, "ConditionVip", data.mConditionVip);
		LuaCfgHelper::readInt(L, "RewardCoin", data.mRewardCoin);
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_OnlineRewardCFG Loaded. Load Data:%u", mMapData.size());
}

void M_OnlineRewardCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_OnlineRewardCFG* M_OnlineRewardCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_OnlineRewardCFG());
	}
	return msSingleton.get();
}

void M_OnlineRewardCFG::Release()
{
	msSingleton.reset(nullptr);
}
