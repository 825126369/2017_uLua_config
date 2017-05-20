#include "stdafx.h"
#include "tinyxml2/tinyxml2.h"
#include "LuaCfgHelper.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "M_FreeLotteryCFG.h"
std::auto_ptr<M_FreeLotteryCFG> M_FreeLotteryCFG::msSingleton(nullptr);

int M_FreeLotteryCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_FreeLotteryCFGData* M_FreeLotteryCFG::GetData(int ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

const std::map<int, M_FreeLotteryCFGData>& M_FreeLotteryCFG::GetMapData()
{
	return mMapData;
}

void M_FreeLotteryCFG::Load()
{
	tinyxml2::XMLDocument xmlDoc;
	std::string content = FileUtils::getInstance()->getStringFromFile("Config/M_FreeLotteryCFG.xml");
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
		M_FreeLotteryCFGData data;
		data.mID = element->IntAttribute("ID");
		data.mInfo = element->Attribute("Info");
		data.mBaseGold = element->IntAttribute("BaseGold");
		data.mAwardIcon = element->Attribute("AwardIcon");
		data.mAwardTitle = element->Attribute("AwardTitle");
		{
			const char* AwardItem1 = element->Attribute("AwardItem1");
			std::vector<std::string> vecAwardItem1;
			boost::split(vecAwardItem1, AwardItem1, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecAwardItem1.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecAwardItem1[i].c_str(), &temp))
				{
					data.mAwardItem1.push_back(temp);
				}
			}
		}
		{
			const char* AwardItem2 = element->Attribute("AwardItem2");
			std::vector<std::string> vecAwardItem2;
			boost::split(vecAwardItem2, AwardItem2, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecAwardItem2.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecAwardItem2[i].c_str(), &temp))
				{
					data.mAwardItem2.push_back(temp);
				}
			}
		}
		{
			const char* AwardItem3 = element->Attribute("AwardItem3");
			std::vector<std::string> vecAwardItem3;
			boost::split(vecAwardItem3, AwardItem3, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecAwardItem3.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecAwardItem3[i].c_str(), &temp))
				{
					data.mAwardItem3.push_back(temp);
				}
			}
		}
		{
			const char* AwardItem4 = element->Attribute("AwardItem4");
			std::vector<std::string> vecAwardItem4;
			boost::split(vecAwardItem4, AwardItem4, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecAwardItem4.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecAwardItem4[i].c_str(), &temp))
				{
					data.mAwardItem4.push_back(temp);
				}
			}
		}
		{
			const char* AwardItem5 = element->Attribute("AwardItem5");
			std::vector<std::string> vecAwardItem5;
			boost::split(vecAwardItem5, AwardItem5, boost::is_any_of(","));
			int temp;
			for (unsigned int i = 0; i < vecAwardItem5.size(); i++)
			{
				if (tinyxml2::XMLUtil::ToInt(vecAwardItem5[i].c_str(), &temp))
				{
					data.mAwardItem5.push_back(temp);
				}
			}
		}
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
	CCLOG("M_FreeLotteryCFG Loaded. Load Data:%u", mMapData.size());
}

void M_FreeLotteryCFG::LoadLua()
{
	LuaEngine::getInstance()->executeScriptFile("config/M_FreeLotteryCFG");
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, "M_FreeLotteryCFG");
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushstring(L, "datas");
	lua_gettable(L, -2);
	CCASSERT(lua_istable(L, -1) == 1, "is not table");
	lua_pushnil(L);
	while(lua_next(L, 2))
	{
		CCASSERT(lua_istable(L, -1) == 1, "is not table");
		M_FreeLotteryCFGData data;
		LuaCfgHelper::readInt(L, "ID", data.mID);
		LuaCfgHelper::readString(L, "Info", data.mInfo);
		LuaCfgHelper::readInt(L, "BaseGold", data.mBaseGold);
		LuaCfgHelper::readString(L, "AwardIcon", data.mAwardIcon);
		LuaCfgHelper::readString(L, "AwardTitle", data.mAwardTitle);
		LuaCfgHelper::readVectorInt(L, "AwardItem1", data.mAwardItem1);
		LuaCfgHelper::readVectorInt(L, "AwardItem2", data.mAwardItem2);
		LuaCfgHelper::readVectorInt(L, "AwardItem3", data.mAwardItem3);
		LuaCfgHelper::readVectorInt(L, "AwardItem4", data.mAwardItem4);
		LuaCfgHelper::readVectorInt(L, "AwardItem5", data.mAwardItem5);
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		CCASSERT(mMapData.find(data.mID) == mMapData.end(), "data.mID is exists");
		mMapData.insert(std::make_pair(data.mID, data));
		lua_pop(L, 1);
	}
	lua_settop(L, 0);
	CCLOG("M_FreeLotteryCFG Loaded. Load Data:%u", mMapData.size());
}

void M_FreeLotteryCFG::Reload()
{
	mMapData.clear();
	Load();
}

M_FreeLotteryCFG* M_FreeLotteryCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_FreeLotteryCFG());
	}
	return msSingleton.get();
}

void M_FreeLotteryCFG::Release()
{
	msSingleton.reset(nullptr);
}
