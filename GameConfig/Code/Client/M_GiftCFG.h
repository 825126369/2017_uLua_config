#pragma once
#include <map>
struct M_GiftCFGData
{
	//礼物ID
	int mGiftId;
	//所含金币
	int mCoin;
	//是否显示
	int misShow;
	//抽成(手续费)
	float mPercent;
	//所需VIP等级
	int mVip;
	//播放的动画
	std::string mAction;
	//物品美术字名字
	std::string mTextIcon;
};

class M_GiftCFG
{
public:
private:
	static std::auto_ptr<M_GiftCFG> msSingleton;
public:
	int GetCount();
	const M_GiftCFGData* GetData(int GiftId);
	const std::map<int, M_GiftCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_GiftCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_GiftCFGData> mMapData;
};
