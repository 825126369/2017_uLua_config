#pragma once
#include <map>
struct Landlord_RoomCFGData
{
	//房间id
	int mRoomID;
	//房间名
	std::string mRoomName;
	//是否开放
	bool mIsOpen;
	//房间图片
	std::string mRoomImage;
	//进场金币条件
	int mGoldCondition;
	//是否洗牌
	bool morShuffle;
	//凳子数量
	int mdeskCount;
	//底分
	int mScore;
};

class Landlord_RoomCFG
{
public:
private:
	static std::auto_ptr<Landlord_RoomCFG> msSingleton;
public:
	int GetCount();
	const Landlord_RoomCFGData* GetData(int RoomID);
	const std::map<int, Landlord_RoomCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static Landlord_RoomCFG* GetSingleton();
private:
	std::map<int, Landlord_RoomCFGData> mMapData;
};
