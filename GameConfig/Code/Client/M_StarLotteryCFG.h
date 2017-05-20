#pragma once
#include <map>
struct M_StarLotteryCFGData
{
	//索引
	int mIndex;
	//类型
	int mStarLvl;
	//物品类型
	int mItemType;
	//物品数量
	int mItemCount;
	//生成几率(10000)
	int mRate1;
	//生成几率(10000)
	int mRate2;
	//生成几率(10000)
	int mRate3;
	//生成几率(10000)
	int mRate4;
};

class M_StarLotteryCFG
{
public:
private:
	static std::auto_ptr<M_StarLotteryCFG> msSingleton;
public:
	int GetCount();
	const M_StarLotteryCFGData* GetData(int Index);
	const std::map<int, M_StarLotteryCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_StarLotteryCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_StarLotteryCFGData> mMapData;
};
