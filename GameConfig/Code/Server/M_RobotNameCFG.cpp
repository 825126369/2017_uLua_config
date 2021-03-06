#include "stdafx.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <iostream>
#include <boost/smart_ptr.hpp>
#include <boost/algorithm/string.hpp>
#include "tinyxml2.h"
#include "M_RobotNameCFG.h"
std::auto_ptr<M_RobotNameCFG> M_RobotNameCFG::msSingleton(nullptr);

int M_RobotNameCFG::GetCount()
{
	return (int)mMapData.size();
}

const M_RobotNameCFGData* M_RobotNameCFG::GetData(int Index)
{
	auto it = mMapData.find(Index);
	if (it != mMapData.end())
	{
		return &it->second;
	}
	return NULL;
}

boost::unordered_map<int, M_RobotNameCFGData>& M_RobotNameCFG::GetMapData()
{
	return mMapData;
}

void M_RobotNameCFG::Reload()
{
	mMapData.clear();
	Load();
}

void M_RobotNameCFG::Reload(const std::string& path)
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
		M_RobotNameCFGData data;
		data.mIndex = element->IntAttribute("Index");
		data.mNickName = element->Attribute("NickName");
		mMapData[data.mIndex] = data;
		element = element->NextSiblingElement();
	}
}

void M_RobotNameCFG::Load(const std::string& path)
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
		M_RobotNameCFGData data;
		data.mIndex = element->IntAttribute("Index");
		data.mNickName = element->Attribute("NickName");
		if (mMapData.find(data.mIndex) != mMapData.end())std::cout <<"data refind:" << data.mIndex << std::endl;
		assert(mMapData.find(data.mIndex) == mMapData.end());
		mMapData.insert(std::make_pair(data.mIndex, data));
		element = element->NextSiblingElement();
	}
}

void M_RobotNameCFG::Load()
{
	Load("../Config/M_RobotNameCFG.xml");
}

M_RobotNameCFG* M_RobotNameCFG::GetSingleton()
{
	if (msSingleton.get() == nullptr)
	{
		msSingleton.reset(new M_RobotNameCFG());
	}
	return msSingleton.get();
}
