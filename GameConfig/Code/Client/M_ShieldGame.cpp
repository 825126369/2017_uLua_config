#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_ShieldGame.h"
std::auto_ptr<M_ShieldGame> M_ShieldGame::msSingleton(nullptr);

int M_ShieldGame::GetCount()
{
	return (int)mMapData.size();
}

const M_ShieldGameData* M_ShieldGame::GetData(int ChannelID)
{
	auto it = mMapData.find(ChannelID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_ShieldGameData>& M_ShieldGame::GetMapData()
{
	return mMapData;
}

void M_ShieldGame::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_ShieldGame.xml");
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
		M_ShieldGameData data;
		data.mChannelID = element->IntAttribute("ChannelID");
		data.mType = element->IntAttribute("Type");
		{
			const char* ShieldGameList = element->Attribute("ShieldGameList");
			std::vector<std::string> vecShieldGameList;
			boost::split(vecShieldGameList, ShieldGameList, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecShieldGameList.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecShieldGameList[i].c_str(), &temp))
				{
					data.mShieldGameList.push_back(temp);
				}
			}
		}
		{
			const char* ShowAchieveList = element->Attribute("ShowAchieveList");
			std::vector<std::string> vecShowAchieveList;
			boost::split(vecShowAchieveList, ShowAchieveList, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecShowAchieveList.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecShowAchieveList[i].c_str(), &temp))
				{
					data.mShowAchieveList.push_back(temp);
				}
			}
		}
		if (mMapData.find(data.mChannelID) != mMapData.end())std::cout <<"data refind:" << data.mChannelID << std::endl;
		CCASSERT(mMapData.find(data.mChannelID) == mMapData.end(), "data.mChannelID is exists");
		mMapData.insert(std::make_pair(data.mChannelID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_ShieldGame Loaded. Load Data:%u", mMapData.size());
}

void M_ShieldGame::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_ShieldGame");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_ShieldGame");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_ShieldGameData data;
		LuaCfgHelper::readInt(L, "ChannelID", data.mChannelID);
		LuaCfgHelper::readInt(L, "Type", data.mType);
		LuaCfgHelper::readVectorInt(L, "ShieldGameList", data.mShieldGameList);
		LuaCfgHelper::readVectorInt(L, "ShowAchieveList", data.mShowAchieveList);
		if (mMapData.find(data.mChannelID) != mMapData.end())std::cout <<"data refind:" << data.mChannelID << std::endl;
		CCASSERT(mMapData.find(data.mChannelID) == mMapData.end(), "data.mChannelID is exists");
		mMapData.insert(std::make_pair(data.mChannelID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_ShieldGame Loaded. Load Data:%u", mMapData.size());
}

void M_ShieldGame::Reload()
{
	mMapData.clear();
	Load();
}

M_ShieldGame* M_ShieldGame::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_ShieldGame());
	}
	return msSingleton.get();
}

void M_ShieldGame::Release()
{
	msSingleton.reset(nullptr);
}
