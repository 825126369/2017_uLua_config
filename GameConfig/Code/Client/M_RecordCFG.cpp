#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_RecordCFG.h"
std::auto_ptr<M_RecordCFG> M_RecordCFG::msSingleton(nullptr);

int M_RecordCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_RecordCFGData* M_RecordCFG::GetData(int RecordID)
{
	auto it = mMapData.find(RecordID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_RecordCFGData>& M_RecordCFG::GetMapData()
{
	return mMapData;
}

void M_RecordCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_RecordCFG.xml");
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
		M_RecordCFGData data;
		data.mRecordID = element->IntAttribute("RecordID");
		data.mRecordName = element->Attribute("RecordName");
		{
			const char* RecordInfoList = element->Attribute("RecordInfoList");
			std::vector<std::string> vecRecordInfoList;
			boost::split(vecRecordInfoList, RecordInfoList, boost::is_any_of(","));
			for (unsigned int i = 0; i < vecRecordInfoList.size(); i++)
			{
				data.mRecordInfoList.push_back(vecRecordInfoList[i]);
			}
		}
		if (mMapData.find(data.mRecordID) != mMapData.end())std::cout <<"data refind:" << data.mRecordID << std::endl;
		CCASSERT(mMapData.find(data.mRecordID) == mMapData.end(), "data.mRecordID is exists");
		mMapData.insert(std::make_pair(data.mRecordID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_RecordCFG Loaded. Load Data:%u", mMapData.size());
}

void M_RecordCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_RecordCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_RecordCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_RecordCFGData data;
		LuaCfgHelper::readInt(L, "RecordID", data.mRecordID);
		LuaCfgHelper::readString(L, "RecordName", data.mRecordName);
		LuaCfgHelper::readVectorString(L, "RecordInfoList", data.mRecordInfoList);
		if (mMapData.find(data.mRecordID) != mMapData.end())std::cout <<"data refind:" << data.mRecordID << std::endl;
		CCASSERT(mMapData.find(data.mRecordID) == mMapData.end(), "data.mRecordID is exists");
		mMapData.insert(std::make_pair(data.mRecordID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_RecordCFG Loaded. Load Data:%u", mMapData.size());
}

void M_RecordCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_RecordCFG* M_RecordCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_RecordCFG());
	}
	return msSingleton.get();
}

void M_RecordCFG::Release()
{
	msSingleton.reset(nullptr);
}
