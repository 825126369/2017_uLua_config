#include "stdafx.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <iostream>
#include <boost/smart_ptr.hpp>
#include <boost/algorithm/string.hpp>
#include "tinyxml2.h"
#include "M_RobotHeadIconCFG.h"
std::auto_ptr<M_RobotHeadIconCFG> M_RobotHeadIconCFG::msSingleton(nullptr);

int M_RobotHeadIconCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_RobotHeadIconCFGData* M_RobotHeadIconCFG::GetData(int Index)
{
	auto it = mMapData.find(Index);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

boost::unordered_map<int, M_RobotHeadIconCFGData>& M_RobotHeadIconCFG::GetMapData()
{
	return mMapData;
}

void M_RobotHeadIconCFG::Reload()
{
	mMapData.clear();
	Load();
}

void M_RobotHeadIconCFG::Reload(const std::string& path)
{
	std::ifstream readStream(path, std::ios::binary);
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
		M_RobotHeadIconCFGData data;
		data.mIndex = element->IntAttribute("Index");
		data.mboyIcon_MinIndex = element->IntAttribute("boyIcon_MinIndex");
		data.mgirlIcon = element->IntAttribute("girlIcon");
		mMapData[data.mIndex] = data;
		element = element->NextSiblingElement();
	}
}

void M_RobotHeadIconCFG::Load(const std::string& path)
{
	std::ifstream readStream(path, std::ios::binary);
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
		M_RobotHeadIconCFGData data;
		data.mIndex = element->IntAttribute("Index");
		data.mboyIcon_MinIndex = element->IntAttribute("boyIcon_MinIndex");
		data.mgirlIcon = element->IntAttribute("girlIcon");
		if (mMapData.find(data.mIndex) != mMapData.end())std::cout <<"data refind:" << data.mIndex << std::endl;
		assert(mMapData.find(data.mIndex) == mMapData.end());
		mMapData.insert(std::make_pair(data.mIndex, data));
		element = element->NextSiblingElement();
	}
}

void M_RobotHeadIconCFG::Load()
{
	Load("../Config/M_RobotHeadIconCFG.xml");
}

M_RobotHeadIconCFG* M_RobotHeadIconCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_RobotHeadIconCFG());
	}
	return msSingleton.get();
}
