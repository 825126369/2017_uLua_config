#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_VIPProfitCFG.h"
std::auto_ptr<M_VIPProfitCFG> M_VIPProfitCFG::msSingleton(nullptr);

int M_VIPProfitCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_VIPProfitCFGData* M_VIPProfitCFG::GetData(int VipLv)
{
	auto it = mMapData.find(VipLv);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_VIPProfitCFGData>& M_VIPProfitCFG::GetMapData()
{
	return mMapData;
}

void M_VIPProfitCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_VIPProfitCFG.xml");
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
		M_VIPProfitCFGData data;
		data.mVipLv = element->IntAttribute("VipLv");
		data.mVipExp = element->IntAttribute("VipExp");
		data.mOnlineReward = element->IntAttribute("OnlineReward");
		data.mMaxGiftslimit = element->Int64Attribute("MaxGiftslimit");
		{
			const char* GiftUnlock = element->Attribute("GiftUnlock");
			std::vector<std::string> vecGiftUnlock;
			boost::split(vecGiftUnlock, GiftUnlock, boost::is_any_of(","));
			for (unsigned int i = 0; i < vecGiftUnlock.size(); i++)
			{
				data.mGiftUnlock.push_back(vecGiftUnlock[i]);
			}
		}
		{
			const char* RoomUnlock = element->Attribute("RoomUnlock");
			std::vector<std::string> vecRoomUnlock;
			boost::split(vecRoomUnlock, RoomUnlock, boost::is_any_of(","));
			for (unsigned int i = 0; i < vecRoomUnlock.size(); i++)
			{
				data.mRoomUnlock.push_back(vecRoomUnlock[i]);
			}
		}
		{
			const char* FishItemUnlock = element->Attribute("FishItemUnlock");
			std::vector<std::string> vecFishItemUnlock;
			boost::split(vecFishItemUnlock, FishItemUnlock, boost::is_any_of(","));
			for (unsigned int i = 0; i < vecFishItemUnlock.size(); i++)
			{
				data.mFishItemUnlock.push_back(vecFishItemUnlock[i]);
			}
		}
		data.mVipName = element->IntAttribute("VipName");
		data.mGiveTicket = element->IntAttribute("GiveTicket");
		data.mDailyLottery = element->IntAttribute("DailyLottery");
		if (mMapData.find(data.mVipLv) != mMapData.end())std::cout <<"data refind:" << data.mVipLv << std::endl;
		CCASSERT(mMapData.find(data.mVipLv) == mMapData.end(), "data.mVipLv is exists");
		mMapData.insert(std::make_pair(data.mVipLv, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_VIPProfitCFG Loaded. Load Data:%u", mMapData.size());
}

void M_VIPProfitCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_VIPProfitCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_VIPProfitCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_VIPProfitCFGData data;
		LuaCfgHelper::readInt(L, "VipLv", data.mVipLv);
		LuaCfgHelper::readInt(L, "VipExp", data.mVipExp);
		LuaCfgHelper::readInt(L, "OnlineReward", data.mOnlineReward);
		LuaCfgHelper::readInt64(L, "MaxGiftslimit", data.mMaxGiftslimit);
		LuaCfgHelper::readVectorString(L, "GiftUnlock", data.mGiftUnlock);
		LuaCfgHelper::readVectorString(L, "RoomUnlock", data.mRoomUnlock);
		LuaCfgHelper::readVectorString(L, "FishItemUnlock", data.mFishItemUnlock);
		LuaCfgHelper::readInt(L, "VipName", data.mVipName);
		LuaCfgHelper::readInt(L, "GiveTicket", data.mGiveTicket);
		LuaCfgHelper::readInt(L, "DailyLottery", data.mDailyLottery);
		if (mMapData.find(data.mVipLv) != mMapData.end())std::cout <<"data refind:" << data.mVipLv << std::endl;
		CCASSERT(mMapData.find(data.mVipLv) == mMapData.end(), "data.mVipLv is exists");
		mMapData.insert(std::make_pair(data.mVipLv, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_VIPProfitCFG Loaded. Load Data:%u", mMapData.size());
}

void M_VIPProfitCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_VIPProfitCFG* M_VIPProfitCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_VIPProfitCFG());
	}
	return msSingleton.get();
}

void M_VIPProfitCFG::Release()
{
	msSingleton.reset(nullptr);
}
