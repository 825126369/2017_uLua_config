#pragma once
#include <map>
struct HappySupremacy_RateCFGData
{
	//���
	int mKey;
	//����
	std::string mName;
	//ӮǮ����
	int mRate1;
	//���䲻Ӯ����
	int mRate2;
};

class HappySupremacy_RateCFG
{
public:
private:
	static std::auto_ptr<HappySupremacy_RateCFG> msSingleton;
public:
	int GetCount();
	const HappySupremacy_RateCFGData* GetData(int Key);
	const std::map<int, HappySupremacy_RateCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static HappySupremacy_RateCFG* GetSingleton();
private:
	std::map<int, HappySupremacy_RateCFGData> mMapData;
};
