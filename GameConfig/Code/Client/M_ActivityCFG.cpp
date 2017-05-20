#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_ActivityCFG.h"
std::auto_ptr<M_ActivityCFG> M_ActivityCFG::msSingleton(nullptr);

int M_ActivityCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_ActivityCFGData* M_ActivityCFG::GetData(int ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_ActivityCFGData>& M_ActivityCFG::GetMapData()
{
	return mMapData;
}

void M_ActivityCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_ActivityCFG.xml");
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
		M_ActivityCFGData data;
		data.mID = element->IntAttribute("ID");
		data.mActivityName = element->Attribute("ActivityName");
		data.mStartTime = element->Attribute("StartTime");
		data.mEndTime = element->Attribute("EndTime");
		data.mActivityType = element->IntAttribute("ActivityType");
		data.mRechargeRMB = element->IntAttribute("RechargeRMB");
		data.mVipLevel = element->IntAttribute("VipLevel");
		data.mLoginDay = element->Attribute("LoginDay");
		{
			const char* RewardList = element->Attribute("RewardList");
			std::vector<std::string> vecRewardList;
			boost::split(vecRewardList, RewardList, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecRewardList.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecRewardList[i].c_str(), &temp))
				{
					data.mRewardList.push_back(temp);
				}
			}
		}
		{
			const char* RewardCount = element->Attribute("RewardCount");
			std::vector<std::string> vecRewardCount;
			boost::split(vecRewardCount, RewardCount, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecRewardCount.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecRewardCount[i].c_str(), &temp))
				{
					data.mRewardCount.push_back(temp);
				}
			}
		}
		data.mActivityRewardMailTitle = element->Attribute("ActivityRewardMailTitle");
		data.mActivityRewardMailContent = element->Attribute("ActivityRewardMailContent");
		data.mReceiveWay = element->IntAttribute("ReceiveWay");
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_ActivityCFG Loaded. Load Data:%u", mMapData.size());
}

void M_ActivityCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_ActivityCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_ActivityCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_ActivityCFGData data;
		LuaCfgHelper::readInt(L, "ID", data.mID);
		LuaCfgHelper::readString(L, "ActivityName", data.mActivityName);
		LuaCfgHelper::readString(L, "StartTime", data.mStartTime);
		LuaCfgHelper::readString(L, "EndTime", data.mEndTime);
		LuaCfgHelper::readInt(L, "ActivityType", data.mActivityType);
		LuaCfgHelper::readInt(L, "RechargeRMB", data.mRechargeRMB);
		LuaCfgHelper::readInt(L, "VipLevel", data.mVipLevel);
		LuaCfgHelper::readString(L, "LoginDay", data.mLoginDay);
		LuaCfgHelper::readVectorInt(L, "RewardList", data.mRewardList);
		LuaCfgHelper::readVectorInt(L, "RewardCount", data.mRewardCount);
		LuaCfgHelper::readString(L, "ActivityRewardMailTitle", data.mActivityRewardMailTitle);
		LuaCfgHelper::readString(L, "ActivityRewardMailContent", data.mActivityRewardMailContent);
		LuaCfgHelper::readInt(L, "ReceiveWay", data.mReceiveWay);
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_ActivityCFG Loaded. Load Data:%u", mMapData.size());
}

void M_ActivityCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_ActivityCFG* M_ActivityCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_ActivityCFG());
	}
	return msSingleton.get();
}

void M_ActivityCFG::Release()
{
	msSingleton.reset(nullptr);
}
