#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "HappySupremacy_RoomCFG.h"
std::auto_ptr<HappySupremacy_RoomCFG> HappySupremacy_RoomCFG::msSingleton(nullptr);

int HappySupremacy_RoomCFG::GetCount()
{
	return (int)mMapData.size();
}

const HappySupremacy_RoomCFGData* HappySupremacy_RoomCFG::GetData(int RoomID)
{
	auto it = mMapData.find(RoomID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, HappySupremacy_RoomCFGData>& HappySupremacy_RoomCFG::GetMapData()
{
	return mMapData;
}

void HappySupremacy_RoomCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/HappySupremacy_RoomCFG.xml");
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
		HappySupremacy_RoomCFGData data;
		data.mRoomID = element->IntAttribute("RoomID");
		data.mRoomName = element->Attribute("RoomName");
		{
			const char* WeightList = element->Attribute("WeightList");
			std::vector<std::string> vecWeightList;
			boost::split(vecWeightList, WeightList, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecWeightList.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecWeightList[i].c_str(), &temp))
				{
					data.mWeightList.push_back(temp);
				}
			}
		}
		data.mIsOpen = element->BoolAttribute("IsOpen");
		data.mBankerCondition = element->IntAttribute("BankerCondition");
		data.mFirstBankerCost = element->IntAttribute("FirstBankerCost");
		data.mAddBankerCost = element->IntAttribute("AddBankerCost");
		data.mLeaveBankerCost = element->IntAttribute("LeaveBankerCost");
		data.mAutoLeaveBanker = element->IntAttribute("AutoLeaveBanker");
		data.mPlayerMaxCount = element->IntAttribute("PlayerMaxCount");
		{
			const char* RobTag = element->Attribute("RobTag");
			std::vector<std::string> vecRobTag;
			boost::split(vecRobTag, RobTag, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecRobTag.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecRobTag[i].c_str(), &temp))
				{
					data.mRobTag.push_back(temp);
				}
			}
		}
		{
			const char* CreateProb = element->Attribute("CreateProb");
			std::vector<std::string> vecCreateProb;
			boost::split(vecCreateProb, CreateProb, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecCreateProb.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecCreateProb[i].c_str(), &temp))
				{
					data.mCreateProb.push_back(temp);
				}
			}
		}
		data.mRoomImage = element->Attribute("RoomImage");
		data.mVipCondition = element->IntAttribute("VipCondition");
		data.mGoldCondition = element->IntAttribute("GoldCondition");
		data.mBetMax = element->IntAttribute("BetMax");
		data.mRobCount = element->IntAttribute("RobCount");
		if (mMapData.find(data.mRoomID) != mMapData.end())std::cout <<"data refind:" << data.mRoomID << std::endl;
		CCASSERT(mMapData.find(data.mRoomID) == mMapData.end(), "data.mRoomID is exists");
		mMapData.insert(std::make_pair(data.mRoomID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("HappySupremacy_RoomCFG Loaded. Load Data:%u", mMapData.size());
}

void HappySupremacy_RoomCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("Config/HappySupremacy_RoomCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "HappySupremacy_RoomCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		HappySupremacy_RoomCFGData data;
		LuaCfgHelper::readInt(L, "RoomID", data.mRoomID);
		LuaCfgHelper::readString(L, "RoomName", data.mRoomName);
		LuaCfgHelper::readVectorInt(L, "WeightList", data.mWeightList);
		LuaCfgHelper::readBool(L, "IsOpen", data.mIsOpen);
		LuaCfgHelper::readInt(L, "BankerCondition", data.mBankerCondition);
		LuaCfgHelper::readInt(L, "FirstBankerCost", data.mFirstBankerCost);
		LuaCfgHelper::readInt(L, "AddBankerCost", data.mAddBankerCost);
		LuaCfgHelper::readInt(L, "LeaveBankerCost", data.mLeaveBankerCost);
		LuaCfgHelper::readInt(L, "AutoLeaveBanker", data.mAutoLeaveBanker);
		LuaCfgHelper::readInt(L, "PlayerMaxCount", data.mPlayerMaxCount);
		LuaCfgHelper::readVectorInt(L, "RobTag", data.mRobTag);
		LuaCfgHelper::readVectorInt(L, "CreateProb", data.mCreateProb);
		LuaCfgHelper::readString(L, "RoomImage", data.mRoomImage);
		LuaCfgHelper::readInt(L, "VipCondition", data.mVipCondition);
		LuaCfgHelper::readInt(L, "GoldCondition", data.mGoldCondition);
		LuaCfgHelper::readInt(L, "BetMax", data.mBetMax);
		LuaCfgHelper::readInt(L, "RobCount", data.mRobCount);
		if (mMapData.find(data.mRoomID) != mMapData.end())std::cout <<"data refind:" << data.mRoomID << std::endl;
		CCASSERT(mMapData.find(data.mRoomID) == mMapData.end(), "data.mRoomID is exists");
		mMapData.insert(std::make_pair(data.mRoomID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("HappySupremacy_RoomCFG Loaded. Load Data:%u", mMapData.size());
}

void HappySupremacy_RoomCFG::Reload()
{
	mMapData.clear();
	Load();
}

HappySupremacy_RoomCFG* HappySupremacy_RoomCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new HappySupremacy_RoomCFG());
	}
	return msSingleton.get();
}
