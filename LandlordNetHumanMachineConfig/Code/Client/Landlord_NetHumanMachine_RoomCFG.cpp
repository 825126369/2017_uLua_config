#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "Landlord_NetHumanMachine_RoomCFG.h"
std::auto_ptr<Landlord_NetHumanMachine_RoomCFG> Landlord_NetHumanMachine_RoomCFG::msSingleton(nullptr);

int Landlord_NetHumanMachine_RoomCFG::GetCount()
{
	return (int)mMapData.size();
}

const Landlord_NetHumanMachine_RoomCFGData* Landlord_NetHumanMachine_RoomCFG::GetData(int RoomID)
{
	auto it = mMapData.find(RoomID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, Landlord_NetHumanMachine_RoomCFGData>& Landlord_NetHumanMachine_RoomCFG::GetMapData()
{
	return mMapData;
}

void Landlord_NetHumanMachine_RoomCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/Landlord_NetHumanMachine_RoomCFG.xml");
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
		Landlord_NetHumanMachine_RoomCFGData data;
		data.mRoomID = element->IntAttribute("RoomID");
		data.mRoomName = element->Attribute("RoomName");
		data.mIsOpen = element->BoolAttribute("IsOpen");
		data.mRoomImage = element->Attribute("RoomImage");
		data.mGoldCondition = element->IntAttribute("GoldCondition");
		data.morShuffle = element->BoolAttribute("orShuffle");
		data.mdeskCount = element->IntAttribute("deskCount");
		data.mScore = element->IntAttribute("Score");
		if (mMapData.find(data.mRoomID) != mMapData.end())std::cout <<"data refind:" << data.mRoomID << std::endl;
		CCASSERT(mMapData.find(data.mRoomID) == mMapData.end(), "data.mRoomID is exists");
		mMapData.insert(std::make_pair(data.mRoomID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("Landlord_NetHumanMachine_RoomCFG Loaded. Load Data:%u", mMapData.size());
}

void Landlord_NetHumanMachine_RoomCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("Config/Landlord_NetHumanMachine_RoomCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "Landlord_NetHumanMachine_RoomCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		Landlord_NetHumanMachine_RoomCFGData data;
		LuaCfgHelper::readInt(L, "RoomID", data.mRoomID);
		LuaCfgHelper::readString(L, "RoomName", data.mRoomName);
		LuaCfgHelper::readBool(L, "IsOpen", data.mIsOpen);
		LuaCfgHelper::readString(L, "RoomImage", data.mRoomImage);
		LuaCfgHelper::readInt(L, "GoldCondition", data.mGoldCondition);
		LuaCfgHelper::readBool(L, "orShuffle", data.morShuffle);
		LuaCfgHelper::readInt(L, "deskCount", data.mdeskCount);
		LuaCfgHelper::readInt(L, "Score", data.mScore);
		if (mMapData.find(data.mRoomID) != mMapData.end())std::cout <<"data refind:" << data.mRoomID << std::endl;
		CCASSERT(mMapData.find(data.mRoomID) == mMapData.end(), "data.mRoomID is exists");
		mMapData.insert(std::make_pair(data.mRoomID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("Landlord_NetHumanMachine_RoomCFG Loaded. Load Data:%u", mMapData.size());
}

void Landlord_NetHumanMachine_RoomCFG::Reload()
{
	mMapData.clear();
	Load();
}

Landlord_NetHumanMachine_RoomCFG* Landlord_NetHumanMachine_RoomCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new Landlord_NetHumanMachine_RoomCFG());
	}
	return msSingleton.get();
}
