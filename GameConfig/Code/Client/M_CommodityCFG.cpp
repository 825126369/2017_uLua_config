#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_CommodityCFG.h"
std::auto_ptr<M_CommodityCFG> M_CommodityCFG::msSingleton(nullptr);

int M_CommodityCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_CommodityCFGData* M_CommodityCFG::GetData(int CommodityId)
{
	auto it = mMapData.find(CommodityId);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_CommodityCFGData>& M_CommodityCFG::GetMapData()
{
	return mMapData;
}

void M_CommodityCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_CommodityCFG.xml");
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
		M_CommodityCFGData data;
		data.mCommodityId = element->IntAttribute("CommodityId");
		data.mName = element->Attribute("Name");
		data.mCommodityType = element->IntAttribute("CommodityType");
		data.mPriceType = element->IntAttribute("PriceType");
		data.mPrice = element->IntAttribute("Price");
		{
			const char* Item = element->Attribute("Item");
			std::vector<std::string> vecItem;
			boost::split(vecItem, Item, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecItem.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecItem[i].c_str(), &temp))
				{
					data.mItem.push_back(temp);
				}
			}
		}
		data.mIsCanBuy = element->BoolAttribute("IsCanBuy");
		{
			const char* Count = element->Attribute("Count");
			std::vector<std::string> vecCount;
			boost::split(vecCount, Count, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecCount.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecCount[i].c_str(), &temp))
				{
					data.mCount.push_back(temp);
				}
			}
		}
		if (mMapData.find(data.mCommodityId) != mMapData.end())std::cout <<"data refind:" << data.mCommodityId << std::endl;
		CCASSERT(mMapData.find(data.mCommodityId) == mMapData.end(), "data.mCommodityId is exists");
		mMapData.insert(std::make_pair(data.mCommodityId, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_CommodityCFG Loaded. Load Data:%u", mMapData.size());
}

void M_CommodityCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_CommodityCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_CommodityCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_CommodityCFGData data;
		LuaCfgHelper::readInt(L, "CommodityId", data.mCommodityId);
		LuaCfgHelper::readString(L, "Name", data.mName);
		LuaCfgHelper::readInt(L, "CommodityType", data.mCommodityType);
		LuaCfgHelper::readInt(L, "PriceType", data.mPriceType);
		LuaCfgHelper::readInt(L, "Price", data.mPrice);
		LuaCfgHelper::readVectorInt(L, "Item", data.mItem);
		LuaCfgHelper::readBool(L, "IsCanBuy", data.mIsCanBuy);
		LuaCfgHelper::readVectorInt(L, "Count", data.mCount);
		if (mMapData.find(data.mCommodityId) != mMapData.end())std::cout <<"data refind:" << data.mCommodityId << std::endl;
		CCASSERT(mMapData.find(data.mCommodityId) == mMapData.end(), "data.mCommodityId is exists");
		mMapData.insert(std::make_pair(data.mCommodityId, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_CommodityCFG Loaded. Load Data:%u", mMapData.size());
}

void M_CommodityCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_CommodityCFG* M_CommodityCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_CommodityCFG());
	}
	return msSingleton.get();
}

void M_CommodityCFG::Release()
{
	msSingleton.reset(nullptr);
}
