#pragma once
#include <map>
struct M_DialLotteryCFGData
{
	//编号
	int mID;
	//奖励金币
	int mRewardCoin;
	//奖励类型(1:金币    2:礼券)
	int mRewardType;
	//图标缩放比例
	float mScale;
	//物品ICON
	std::string mIcon;
	//获奖概率
	int mProbability;
};

class M_DialLotteryCFG
{
public:
private:
	static std::auto_ptr<M_DialLotteryCFG> msSingleton;
public:
	int GetCount();
	const M_DialLotteryCFGData* GetData(int ID);
	const std::map<int, M_DialLotteryCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_DialLotteryCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_DialLotteryCFGData> mMapData;
};
