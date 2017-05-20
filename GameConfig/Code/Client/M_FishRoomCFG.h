#pragma once
#include <map>
struct M_FishRoomCFGData
{
	//房间id
	int mRoomID;
	//房间名
	std::string mRoomName;
	//房间图片
	std::string mRoomImage;
	//房间名字
	std::string mArmatureName;
	//房间路径
	std::string mArmaturePath;
	//金币条件
	int mGoldCondition;
	//vip条件
	int mVipCondition;
	//礼券条件
	int mTicketCondition;
	//等级条件
	int mLevelCondition;
	//最低倍率
	int mMinRate;
	//最大倍率
	int mMaxRate;
	//切换倍率挡位
	int mStepRate;
	//桌子数
	int mTableCount;
	//是否开放
	bool mIsOpen;
	//能量系数
	int mPowerParam;
	//购买能量消耗
	int mBuyPowerCost;
	//导弹消耗
	int mMissileCost;
	//开启保护
	bool mOpenProtect;
	//能获取经验
	bool mCanGetExp;
	//检查倍率
	bool mCheckOpenRate;
	//免费道具
	bool mFreeItem;
};

class M_FishRoomCFG
{
public:
private:
	static std::auto_ptr<M_FishRoomCFG> msSingleton;
public:
	int GetCount();
	const M_FishRoomCFGData* GetData(int RoomID);
	const std::map<int, M_FishRoomCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_FishRoomCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_FishRoomCFGData> mMapData;
};
