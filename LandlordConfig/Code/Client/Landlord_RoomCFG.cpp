#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "Landlord_RoomCFG.h"
std::auto_ptr<Landlord_RoomCFG> Landlord_RoomCFG::msSingleton(nullptr);

int Landlord_RoomCFG::GetCount()
{
	return (int)mMapData.size();
}

const Landlord_RoomCFGData* Landlord_RoomCFG::GetData(int RoomID)
{
	auto it = mMapData.find(RoomID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, Landlord_RoomCFGData>& Landlord_RoomCFG::GetMapData()
{
	return mMapData;
}

void Landlord_RoomCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/Landlord_RoomCFG.xml");
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
		Landlord_RoomCFGData data;
		data.mRoomID = element->IntAttribute("RoomID");
		data.mRoomName = element->Attribute("RoomName");
		data.mIsOpen = element->BoolAttribute("IsOpen");
		data.mRoomImage = element->Attribute("RoomImage");
		data.mVipCondition = element->IntAttribute("VipCondition");
		data.mGoldCondition = element->IntAttribute("GoldCondition");
		data.morShuffle = element->BoolAttribute("orShuffle");
		if (mMapData.find(data.mRoomID) != mMapData.end())std::cout <<"data refind:" << data.mRoomID << std::endl;
		CCASSERT(mMapData.find(data.mRoomID) == mMapData.end(), "data.mRoomID is exists");
		mMapData.insert(std::make_pair(data.mRoomID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("Landlord_RoomCFG Loaded. Load Data:%u", mMapData.size());
}

void Landlord_RoomCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("Config/Landlord_RoomCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "Landlord_RoomCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		Landlord_RoomCFGData data;
		LuaCfgHelper::readInt(L, "RoomID", data.mRoomID);
		LuaCfgHelper::readString(L, "RoomName", data.mRoomName);
		LuaCfgHelper::readBool(L, "IsOpen", data.mIsOpen);
		LuaCfgHelper::readString(L, "RoomImage", data.mRoomImage);
		LuaCfgHelper::readInt(L, "VipCondition", data.mVipCondition);
		LuaCfgHelper::readInt(L, "GoldCondition", data.mGoldCondition);
		LuaCfgHelper::readBool(L, "orShuffle", data.morShuffle);
		if (mMapData.find(data.mRoomID) != mMapData.end())std::cout <<"data refind:" << data.mRoomID << std::endl;
		CCASSERT(mMapData.find(data.mRoomID) == mMapData.end(), "data.mRoomID is exists");
		mMapData.insert(std::make_pair(data.mRoomID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("Landlord_RoomCFG Loaded. Load Data:%u", mMapData.size());
}

void Landlord_RoomCFG::Reload()
{
	mMapData.clear();
	Load();
}

Landlord_RoomCFG* Landlord_RoomCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new Landlord_RoomCFG());
	}
	return msSingleton.get();
}
