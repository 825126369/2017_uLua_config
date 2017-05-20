#pragma once
#include <map>
struct M_ShopCFGData
{
	//充值ID
	int mID;
	//名字
	std::string mName;
	//描述
	std::string mDesc;
	//名字ICON
	std::string mNameIcon;
	//ICON
	std::string mIcon;
	//类型 1金币 2月卡 3礼包
	int mType;
	//价格(钻石)
	int mPrice;
	//金币
	int mGold;
	//显示序号
	int mIndex;
	//显示商店
	int mShopType;
};

class M_ShopCFG
{
public:
private:
	static std::auto_ptr<M_ShopCFG> msSingleton;
public:
	int GetCount();
	const M_ShopCFGData* GetData(int ID);
	const std::map<int, M_ShopCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_ShopCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_ShopCFGData> mMapData;
};
