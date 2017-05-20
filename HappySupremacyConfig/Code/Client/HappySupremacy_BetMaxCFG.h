#pragma once
#include <map>
struct HappySupremacy_BetMaxCFGData
{
	//Key
	int mID;
	//�������
	int mGoldCount;
	//����Ͷע����
	int mBetMax;
	//���ó������
	std::vector<int> mCanUseWeight;
};

class HappySupremacy_BetMaxCFG
{
public:
private:
	static std::auto_ptr<HappySupremacy_BetMaxCFG> msSingleton;
public:
	int GetCount();
	const HappySupremacy_BetMaxCFGData* GetData(int ID);
	const std::map<int, HappySupremacy_BetMaxCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static HappySupremacy_BetMaxCFG* GetSingleton();
private:
	std::map<int, HappySupremacy_BetMaxCFGData> mMapData;
};
