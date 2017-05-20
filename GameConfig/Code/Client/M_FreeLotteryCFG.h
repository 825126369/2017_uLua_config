#pragma once
#include <map>
struct M_FreeLotteryCFGData
{
	//key
	int mID;
	//说明
	std::string mInfo;
	//最小奖池
	int mBaseGold;
	//ICON
	std::string mAwardIcon;
	//奖励标题
	std::string mAwardTitle;
	//奖励物品1
	std::vector<int> mAwardItem1;
	//奖励物品2
	std::vector<int> mAwardItem2;
	//奖励物品3
	std::vector<int> mAwardItem3;
	//奖励物品4
	std::vector<int> mAwardItem4;
	//奖励物品5
	std::vector<int> mAwardItem5;
};

class M_FreeLotteryCFG
{
public:
private:
	static std::auto_ptr<M_FreeLotteryCFG> msSingleton;
public:
	int GetCount();
	const M_FreeLotteryCFGData* GetData(int ID);
	const std::map<int, M_FreeLotteryCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_FreeLotteryCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_FreeLotteryCFGData> mMapData;
};
