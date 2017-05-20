#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "HappySupremacy_RoomStockCFG.h"
std::auto_ptr<HappySupremacy_RoomStockCFG> HappySupremacy_RoomStockCFG::msSingleton(nullptr);

int HappySupremacy_RoomStockCFG::GetCount()
{
	return (int)mMapData.size();
}

const HappySupremacy_RoomStockCFGData* HappySupremacy_RoomStockCFG::GetData(int RoomID)
{
	auto it = mMapData.find(RoomID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, HappySupremacy_RoomStockCFGData>& HappySupremacy_RoomStockCFG::GetMapData()
{
	return mMapData;
}

void HappySupremacy_RoomStockCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/HappySupremacy_RoomStockCFG.xml");
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
		HappySupremacy_RoomStockCFGData data;
		data.mRoomID = element->IntAttribute("RoomID");
		data.mDeduct = element->FloatAttribute("Deduct");
		data.mDefaultStock = element->IntAttribute("DefaultStock");
		{
			const char* Stock = element->Attribute("Stock");
			std::vector<std::string> vecStock;
			boost::split(vecStock, Stock, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecStock.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecStock[i].c_str(), &temp))
				{
					data.mStock.push_back(temp);
				}
			}
		}
		{
			const char* ScoreId = element->Attribute("ScoreId");
			std::vector<std::string> vecScoreId;
			boost::split(vecScoreId, ScoreId, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecScoreId.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecScoreId[i].c_str(), &temp))
				{
					data.mScoreId.push_back(temp);
				}
			}
		}
		if (mMapData.find(data.mRoomID) != mMapData.end())std::cout <<"data refind:" << data.mRoomID << std::endl;
		CCASSERT(mMapData.find(data.mRoomID) == mMapData.end(), "data.mRoomID is exists");
		mMapData.insert(std::make_pair(data.mRoomID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("HappySupremacy_RoomStockCFG Loaded. Load Data:%u", mMapData.size());
}

void HappySupremacy_RoomStockCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("Config/HappySupremacy_RoomStockCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "HappySupremacy_RoomStockCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		HappySupremacy_RoomStockCFGData data;
		LuaCfgHelper::readInt(L, "RoomID", data.mRoomID);
		LuaCfgHelper::readFloat(L, "Deduct", data.mDeduct);
		LuaCfgHelper::readInt(L, "DefaultStock", data.mDefaultStock);
		LuaCfgHelper::readVectorInt(L, "Stock", data.mStock);
		LuaCfgHelper::readVectorInt(L, "ScoreId", data.mScoreId);
		if (mMapData.find(data.mRoomID) != mMapData.end())std::cout <<"data refind:" << data.mRoomID << std::endl;
		CCASSERT(mMapData.find(data.mRoomID) == mMapData.end(), "data.mRoomID is exists");
		mMapData.insert(std::make_pair(data.mRoomID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("HappySupremacy_RoomStockCFG Loaded. Load Data:%u", mMapData.size());
}

void HappySupremacy_RoomStockCFG::Reload()
{
	mMapData.clear();
	Load();
}

HappySupremacy_RoomStockCFG* HappySupremacy_RoomStockCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new HappySupremacy_RoomStockCFG());
	}
	return msSingleton.get();
}
