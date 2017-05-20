#pragma once
#include <map>
struct HappySupremacy_BaseCFGData
{
	//KeyÖµ
	std::string mKey;
	//ÊýÖµ
	int mValue;
};

class HappySupremacy_BaseCFG
{
public:
private:
	static std::auto_ptr<HappySupremacy_BaseCFG> msSingleton;
public:
	int GetCount();
	const HappySupremacy_BaseCFGData* GetData(std::string Key);
	const std::map<std::string, HappySupremacy_BaseCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static HappySupremacy_BaseCFG* GetSingleton();
private:
	std::map<std::string, HappySupremacy_BaseCFGData> mMapData;
};
