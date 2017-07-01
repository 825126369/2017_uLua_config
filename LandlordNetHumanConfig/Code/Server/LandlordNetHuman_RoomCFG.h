#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct LandlordNetHuman_RoomCFGData
{
	//����id
	int mRoomID;
	//������ǰ׺
	std::string mRoomNamePrefix;
	//�����������
	int mGoldCondition;
	//�Ƿ�ϴ��
	bool morShuffle;
	//��������
	int mdeskCount;
	//�׷�
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
	boost::unordered_map<int, LandlordNetHuman_RoomCFGData>& GetMapData();
	void Reload();
	void Load();
	static LandlordNetHuman_RoomCFG* GetSingleton();
private:
	boost::unordered_map<int, LandlordNetHuman_RoomCFGData> mMapData;
};
