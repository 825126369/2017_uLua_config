#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_GiftRewardCFG.h"
std::auto_ptr<M_GiftRewardCFG> M_GiftRewardCFG::msSingleton(nullptr);

int M_GiftRewardCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_GiftRewardCFGData* M_GiftRewardCFG::GetData(int RewardType)
{
	auto it = mMapData.find(RewardType);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_GiftRewardCFGData>& M_GiftRewardCFG::GetMapData()
{
	return mMapData;
}

void M_GiftRewardCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_GiftRewardCFG.xml");
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
		M_GiftRewardCFGData data;
		data.mRewardType = element->IntAttribute("RewardType");
		{
			const char* ItemId = element->Attribute("ItemId");
			std::vector<std::string> vecItemId;
			boost::split(vecItemId, ItemId, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecItemId.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecItemId[i].c_str(), &temp))
				{
					data.mItemId.push_back(temp);
				}
			}
		}
		{
			const char* ItemCount = element->Attribute("ItemCount");
			std::vector<std::string> vecItemCount;
			boost::split(vecItemCount, ItemCount, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecItemCount.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecItemCount[i].c_str(), &temp))
				{
					data.mItemCount.push_back(temp);
				}
			}
		}
		if (mMapData.find(data.mRewardType) != mMapData.end())std::cout <<"data refind:" << data.mRewardType << std::endl;
		CCASSERT(mMapData.find(data.mRewardType) == mMapData.end(), "data.mRewardType is exists");
		mMapData.insert(std::make_pair(data.mRewardType, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_GiftRewardCFG Loaded. Load Data:%u", mMapData.size());
}

void M_GiftRewardCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_GiftRewardCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_GiftRewardCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_GiftRewardCFGData data;
		LuaCfgHelper::readInt(L, "RewardType", data.mRewardType);
		LuaCfgHelper::readVectorInt(L, "ItemId", data.mItemId);
		LuaCfgHelper::readVectorInt(L, "ItemCount", data.mItemCount);
		if (mMapData.find(data.mRewardType) != mMapData.end())std::cout <<"data refind:" << data.mRewardType << std::endl;
		CCASSERT(mMapData.find(data.mRewardType) == mMapData.end(), "data.mRewardType is exists");
		mMapData.insert(std::make_pair(data.mRewardType, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_GiftRewardCFG Loaded. Load Data:%u", mMapData.size());
}

void M_GiftRewardCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_GiftRewardCFG* M_GiftRewardCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_GiftRewardCFG());
	}
	return msSingleton.get();
}

void M_GiftRewardCFG::Release()
{
	msSingleton.reset(nullptr);
}
