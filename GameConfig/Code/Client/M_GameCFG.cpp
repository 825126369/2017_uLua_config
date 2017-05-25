#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_GameCFG.h"
std::auto_ptr<M_GameCFG> M_GameCFG::msSingleton(nullptr);

int M_GameCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_GameCFGData* M_GameCFG::GetData(int ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_GameCFGData>& M_GameCFG::GetMapData()
{
	return mMapData;
}

void M_GameCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_GameCFG.xml");
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
		M_GameCFGData data;
		data.mID = element->IntAttribute("ID");
		data.mGameName = element->Attribute("GameName");
		data.mGamePrefix = element->Attribute("GamePrefix");
		data.mUpdateUrl = element->Attribute("UpdateUrl");
		data.mIsOpen = element->BoolAttribute("IsOpen");
		data.mGameSize = element->Attribute("GameSize");
		data.mZipVersion = element->Attribute("ZipVersion");
		data.mAnimationName = element->Attribute("AnimationName");
		data.mPictureName = element->Attribute("PictureName");
		data.mIsShow = element->BoolAttribute("IsShow");
		data.mEnterGold = element->IntAttribute("EnterGold");
		data.mEnterVIP = element->IntAttribute("EnterVIP");
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_GameCFG Loaded. Load Data:%u", mMapData.size());
}

void M_GameCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_GameCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_GameCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_GameCFGData data;
		LuaCfgHelper::readInt(L, "ID", data.mID);
		LuaCfgHelper::readString(L, "GameName", data.mGameName);
		LuaCfgHelper::readString(L, "GamePrefix", data.mGamePrefix);
		LuaCfgHelper::readString(L, "UpdateUrl", data.mUpdateUrl);
		LuaCfgHelper::readBool(L, "IsOpen", data.mIsOpen);
		LuaCfgHelper::readString(L, "GameSize", data.mGameSize);
		LuaCfgHelper::readString(L, "ZipVersion", data.mZipVersion);
		LuaCfgHelper::readString(L, "AnimationName", data.mAnimationName);
		LuaCfgHelper::readString(L, "PictureName", data.mPictureName);
		LuaCfgHelper::readBool(L, "IsShow", data.mIsShow);
		LuaCfgHelper::readInt(L, "EnterGold", data.mEnterGold);
		LuaCfgHelper::readInt(L, "EnterVIP", data.mEnterVIP);
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_GameCFG Loaded. Load Data:%u", mMapData.size());
}

void M_GameCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_GameCFG* M_GameCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_GameCFG());
	}
	return msSingleton.get();
}

void M_GameCFG::Release()
{
	msSingleton.reset(nullptr);
}
