#pragma once
#include <map>
struct LandlordNetHuman_RoomCFGData
{
	//房间id
	int mRoomID;
	//房间名前缀
	std::string mRoomNamePrefix;
	//进场金币条件
	int mGoldCondition;
	//是否洗牌
	bool morShuffle;
	//凳子数量
	int mdeskCount;
	//底分
	int mScore;
};

class LandlordNetHuman_RoomCFG
{
public:
private:
	static std::auto_ptr<LandlordNetHuman_RoomCFG> msSingleton;
public:
	int GetCount();
	const LandlordNetHuman_RoomCFGData* GetData(int RoomID);
	const std::map<int, LandlordNetHuman_RoomCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static LandlordNetHuman_RoomCFG* GetSingleton();
private:
	std::map<int, LandlordNetHuman_RoomCFGData> mMapData;
};
