#pragma once
#include <map>
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
	const std::map<int, LandlordNetHuman_RoomCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static LandlordNetHuman_RoomCFG* GetSingleton();
private:
	std::map<int, LandlordNetHuman_RoomCFGData> mMapData;
};
