#pragma once
#include <map>
struct HappySupremacy_RobCFGData
{
	//Key
	int mID;
	//玩家标签
	std::string mName;
	//金币最小值
	int mGoldMin;
	//金币最大值
	int mGoldMax;
	//VIP最小值
	int mVipMin;
	//VIP最大值
	int mVipMax;
};

class HappySupremacy_RobCFG
{
public:
private:
	static std::auto_ptr<HappySupremacy_RobCFG> msSingleton;
public:
	int GetCount();
	const HappySupremacy_RobCFGData* GetData(int ID);
	const std::map<int, HappySupremacy_RobCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static HappySupremacy_RobCFG* GetSingleton();
private:
	std::map<int, HappySupremacy_RobCFGData> mMapData;
};
