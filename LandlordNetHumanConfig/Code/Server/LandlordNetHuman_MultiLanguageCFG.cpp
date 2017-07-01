#include "stdafx.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <iostream>
#include <boost/smart_ptr.hpp>
#include <boost/algorithm/string.hpp>
#include "tinyxml2.h"
#include "LandlordNetHuman_MultiLanguageCFG.h"
std::auto_ptr<LandlordNetHuman_MultiLanguageCFG> LandlordNetHuman_MultiLanguageCFG::msSingleton(nullptr);

int LandlordNetHuman_MultiLanguageCFG::GetCount()
{
	return (int)mMapData.size();
}

const LandlordNetHuman_MultiLanguageCFGData* LandlordNetHuman_MultiLanguageCFG::GetData(std::string ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

boost::unordered_map<std::string, LandlordNetHuman_MultiLanguageCFGData>& LandlordNetHuman_MultiLanguageCFG::GetMapData()
{
	return mMapData;
}

void LandlordNetHuman_MultiLanguageCFG::Reload()
{
	mMapData.clear();
	Load();
}

void LandlordNetHuman_MultiLanguageCFG::Load()
{
	std::ifstream readStream("../Config/LandlordNetHuman_MultiLanguageCFG.xml", std::ios::binary);
	if (!readStream.is_open())
	{
		assert(false);
		return;
	}
	readStream.seekg(0, std::ios::end);
	int fileSize = readStream.tellg();
	boost::shared_array<char> buffer(new char[fileSize+1]);
	buffer.get()[fileSize] = '\0';
	readStream.seekg(0, std::ios::beg);
	readStream.read(buffer.get(), fileSize);
	readStream.close();
	tinyxml2::XMLDocument xmlDoc;
	auto result = xmlDoc.Parse(buffer.get(), fileSize);
	if (result != tinyxml2::XML_SUCCESS)
	{
		assert(false);
		return;
	}
	auto root = xmlDoc.RootElement();
	if (root == NULL)
	{
		assert(false);
		return;
	}
	auto element = root->FirstChildElement("Data");
	while (element != NULL)
	{
		LandlordNetHuman_MultiLanguageCFGData data;
		data.mID = element->Attribute("ID");
		data.mName = element->Attribute("Name");
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		assert(mMapData.find(data.mID) == mMapData.end());
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
}

LandlordNetHuman_MultiLanguageCFG* LandlordNetHuman_MultiLanguageCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new LandlordNetHuman_MultiLanguageCFG());
	}
	return msSingleton.get();
}
