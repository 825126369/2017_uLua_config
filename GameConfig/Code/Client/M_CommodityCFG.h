#pragma once
#include <map>
struct M_CommodityCFGData
{
	//商品ID
	int mCommodityId;
	//商品名称
	std::string mName;
	//商品类型(3.礼物5.相框)
	int mCommodityType;
	//价格类型(1金币 2礼券)
	int mPriceType;
	//实际价格
	int mPrice;
	//所含道具，对应ItemCFG.xls表
	std::vector<int> mItem;
	//是否能购买(是否显示)
	bool mIsCanBuy;
	//数量
	std::vector<int> mCount;
};

class M_CommodityCFG
{
public:
private:
	static std::auto_ptr<M_CommodityCFG> msSingleton;
public:
	int GetCount();
	const M_CommodityCFGData* GetData(int CommodityId);
	const std::map<int, M_CommodityCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_CommodityCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_CommodityCFGData> mMapData;
};
