#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_FishRoomCFG.h"
std::auto_ptr<M_FishRoomCFG> M_FishRoomCFG::msSingleton(nullptr);

int M_FishRoomCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_FishRoomCFGData* M_FishRoomCFG::GetData(int RoomID)
{
	auto it = mMapData.find(RoomID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_FishRoomCFGData>& M_FishRoomCFG::GetMapData()
{
	return mMapData;
}

void M_FishRoomCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_FishRoomCFG.xml");
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
		M_FishRoomCFGData data;
		data.mRoomID = element->IntAttribute("RoomID");
		data.mRoomName = element->Attribute("RoomName");
		data.mRoomImage = element->Attribute("RoomImage");
		data.mArmatureName = element->Attribute("ArmatureName");
		data.mArmaturePath = element->Attribute("ArmaturePath");
		data.mGoldCondition = element->IntAttribute("GoldCondition");
		data.mVipCondition = element->IntAttribute("VipCondition");
		data.mTicketCondition = element->IntAttribute("TicketCondition");
		data.mLevelCondition = element->IntAttribute("LevelCondition");
		data.mMinRate = element->IntAttribute("MinRate");
		data.mMaxRate = element->IntAttribute("MaxRate");
		data.mStepRate = element->IntAttribute("StepRate");
		data.mTableCount = element->IntAttribute("TableCount");
		data.mIsOpen = element->BoolAttribute("IsOpen");
		data.mPowerParam = element->IntAttribute("PowerParam");
		data.mBuyPowerCost = element->IntAttribute("BuyPowerCost");
		data.mMissileCost = element->IntAttribute("MissileCost");
		data.mOpenProtect = element->BoolAttribute("OpenProtect");
		data.mCanGetExp = element->BoolAttribute("CanGetExp");
		data.mCheckOpenRate = element->BoolAttribute("CheckOpenRate");
		data.mFreeItem = element->BoolAttribute("FreeItem");
		if (mMapData.find(data.mRoomID) != mMapData.end())std::cout <<"data refind:" << data.mRoomID << std::endl;
		CCASSERT(mMapData.find(data.mRoomID) == mMapData.end(), "data.mRoomID is exists");
		mMapData.insert(std::make_pair(data.mRoomID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_FishRoomCFG Loaded. Load Data:%u", mMapData.size());
}

void M_FishRoomCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_FishRoomCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_FishRoomCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_FishRoomCFGData data;
		LuaCfgHelper::readInt(L, "RoomID", data.mRoomID);
		LuaCfgHelper::readString(L, "RoomName", data.mRoomName);
		LuaCfgHelper::readString(L, "RoomImage", data.mRoomImage);
		LuaCfgHelper::readString(L, "ArmatureName", data.mArmatureName);
		LuaCfgHelper::readString(L, "ArmaturePath", data.mArmaturePath);
		LuaCfgHelper::readInt(L, "GoldCondition", data.mGoldCondition);
		LuaCfgHelper::readInt(L, "VipCondition", data.mVipCondition);
		LuaCfgHelper::readInt(L, "TicketCondition", data.mTicketCondition);
		LuaCfgHelper::readInt(L, "LevelCondition", data.mLevelCondition);
		LuaCfgHelper::readInt(L, "MinRate", data.mMinRate);
		LuaCfgHelper::readInt(L, "MaxRate", data.mMaxRate);
		LuaCfgHelper::readInt(L, "StepRate", data.mStepRate);
		LuaCfgHelper::readInt(L, "TableCount", data.mTableCount);
		LuaCfgHelper::readBool(L, "IsOpen", data.mIsOpen);
		LuaCfgHelper::readInt(L, "PowerParam", data.mPowerParam);
		LuaCfgHelper::readInt(L, "BuyPowerCost", data.mBuyPowerCost);
		LuaCfgHelper::readInt(L, "MissileCost", data.mMissileCost);
		LuaCfgHelper::readBool(L, "OpenProtect", data.mOpenProtect);
		LuaCfgHelper::readBool(L, "CanGetExp", data.mCanGetExp);
		LuaCfgHelper::readBool(L, "CheckOpenRate", data.mCheckOpenRate);
		LuaCfgHelper::readBool(L, "FreeItem", data.mFreeItem);
		if (mMapData.find(data.mRoomID) != mMapData.end())std::cout <<"data refind:" << data.mRoomID << std::endl;
		CCASSERT(mMapData.find(data.mRoomID) == mMapData.end(), "data.mRoomID is exists");
		mMapData.insert(std::make_pair(data.mRoomID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_FishRoomCFG Loaded. Load Data:%u", mMapData.size());
}

void M_FishRoomCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_FishRoomCFG* M_FishRoomCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_FishRoomCFG());
	}
	return msSingleton.get();
}

void M_FishRoomCFG::Release()
{
	msSingleton.reset(nullptr);
}
