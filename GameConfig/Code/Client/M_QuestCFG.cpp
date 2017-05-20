#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_QuestCFG.h"
std::auto_ptr<M_QuestCFG> M_QuestCFG::msSingleton(nullptr);

int M_QuestCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_QuestCFGData* M_QuestCFG::GetData(int ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_QuestCFGData>& M_QuestCFG::GetMapData()
{
	return mMapData;
}

void M_QuestCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_QuestCFG.xml");
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
		M_QuestCFGData data;
		data.mID = element->IntAttribute("ID");
		data.mName = element->Attribute("Name");
		data.mDesc = element->Attribute("Desc");
		data.mIcon1 = element->Attribute("Icon1");
		data.mIcon2 = element->Attribute("Icon2");
		data.mFrame = element->Attribute("Frame");
		data.mDefault = element->BoolAttribute("Default");
		data.mClass = element->IntAttribute("Class");
		data.mType = element->IntAttribute("Type");
		data.mCompleteType = element->IntAttribute("CompleteType");
		data.mCompleteCount = element->IntAttribute("CompleteCount");
		data.mCompleteParam = element->IntAttribute("CompleteParam");
		data.mNextQuestID = element->IntAttribute("NextQuestID");
		data.mIsSaveCount = element->BoolAttribute("IsSaveCount");
		{
			const char* AwardItemIDs = element->Attribute("AwardItemIDs");
			std::vector<std::string> vecAwardItemIDs;
			boost::split(vecAwardItemIDs, AwardItemIDs, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecAwardItemIDs.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecAwardItemIDs[i].c_str(), &temp))
				{
					data.mAwardItemIDs.push_back(temp);
				}
			}
		}
		{
			const char* AwardItemCounts = element->Attribute("AwardItemCounts");
			std::vector<std::string> vecAwardItemCounts;
			boost::split(vecAwardItemCounts, AwardItemCounts, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecAwardItemCounts.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecAwardItemCounts[i].c_str(), &temp))
				{
					data.mAwardItemCounts.push_back(temp);
				}
			}
		}
		data.mIsSet = element->BoolAttribute("IsSet");
		data.mGoTo = element->IntAttribute("GoTo");
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_QuestCFG Loaded. Load Data:%u", mMapData.size());
}

void M_QuestCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_QuestCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_QuestCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_QuestCFGData data;
		LuaCfgHelper::readInt(L, "ID", data.mID);
		LuaCfgHelper::readString(L, "Name", data.mName);
		LuaCfgHelper::readString(L, "Desc", data.mDesc);
		LuaCfgHelper::readString(L, "Icon1", data.mIcon1);
		LuaCfgHelper::readString(L, "Icon2", data.mIcon2);
		LuaCfgHelper::readString(L, "Frame", data.mFrame);
		LuaCfgHelper::readBool(L, "Default", data.mDefault);
		LuaCfgHelper::readInt(L, "Class", data.mClass);
		LuaCfgHelper::readInt(L, "Type", data.mType);
		LuaCfgHelper::readInt(L, "CompleteType", data.mCompleteType);
		LuaCfgHelper::readInt(L, "CompleteCount", data.mCompleteCount);
		LuaCfgHelper::readInt(L, "CompleteParam", data.mCompleteParam);
		LuaCfgHelper::readInt(L, "NextQuestID", data.mNextQuestID);
		LuaCfgHelper::readBool(L, "IsSaveCount", data.mIsSaveCount);
		LuaCfgHelper::readVectorInt(L, "AwardItemIDs", data.mAwardItemIDs);
		LuaCfgHelper::readVectorInt(L, "AwardItemCounts", data.mAwardItemCounts);
		LuaCfgHelper::readBool(L, "IsSet", data.mIsSet);
		LuaCfgHelper::readInt(L, "GoTo", data.mGoTo);
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_QuestCFG Loaded. Load Data:%u", mMapData.size());
}

void M_QuestCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_QuestCFG* M_QuestCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_QuestCFG());
	}
	return msSingleton.get();
}

void M_QuestCFG::Release()
{
	msSingleton.reset(nullptr);
}
