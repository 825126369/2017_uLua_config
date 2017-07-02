#include "stdafx.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <iostream>
#include <boost/smart_ptr.hpp>
#include <boost/algorithm/string.hpp>
#include "tinyxml2.h"
#include "Landlord_Rank_MultiLanguageCFG.h"
std::auto_ptr<Landlord_Rank_MultiLanguageCFG> Landlord_Rank_MultiLanguageCFG::msSingleton(nullptr);

int Landlord_Rank_MultiLanguageCFG::GetCount()
{
	return (int)mMapData.size();
}

const Landlord_Rank_MultiLanguageCFGData* Landlord_Rank_MultiLanguageCFG::GetData(std::string ID)
{
	auto it = mMapData.find(ID);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

boost::unordered_map<std::string, Landlord_Rank_MultiLanguageCFGData>& Landlord_Rank_MultiLanguageCFG::GetMapData()
{
	return mMapData;
}

void Landlord_Rank_MultiLanguageCFG::Reload()
{
	mMapData.clear();
	Load();
}

void Landlord_Rank_MultiLanguageCFG::Load()
{
	std::ifstream readStream("../Config/Landlord_Rank_MultiLanguageCFG.xml", std::ios::binary);
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
		Landlord_Rank_MultiLanguageCFGData data;
		data.mID = element->Attribute("ID");
		data.mName = element->Attribute("Name");
		if (mMapData.find(data.mID) != mMapData.end())std::cout <<"data refind:" << data.mID << std::endl;
		assert(mMapData.find(data.mID) == mMapData.end());
		mMapData.insert(std::make_pair(data.mID, data));
		element = element->NextSiblingElement();
	}
}

Landlord_Rank_MultiLanguageCFG* Landlord_Rank_MultiLanguageCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new Landlord_Rank_MultiLanguageCFG());
	}
	return msSingleton.get();
}
