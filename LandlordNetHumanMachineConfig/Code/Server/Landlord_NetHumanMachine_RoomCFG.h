#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct Landlord_NetHumanMachine_RoomCFGData
{
	//����id
	int mRoomID;
	//������
	std::string mRoomName;
	//�Ƿ񿪷�
	bool mIsOpen;
	//����ͼƬ
	std::string mRoomImage;
	//�����������
	int mGoldCondition;
	//�Ƿ�ϴ��
	bool morShuffle;
	//��������
	int mdeskCount;
	//�׷�
	int mScore;
};

class Landlord_NetHumanMachine_RoomCFG
{
public:
private:
	static std::auto_ptr<Landlord_NetHumanMachine_RoomCFG> msSingleton;
public:
	int GetCount();
	const Landlord_NetHumanMachine_RoomCFGData* GetData(int RoomID);
	boost::unordered_map<int, Landlord_NetHumanMachine_RoomCFGData>& GetMapData();
	void Reload();
	void Load();
	static Landlord_NetHumanMachine_RoomCFG* GetSingleton();
private:
	boost::unordered_map<int, Landlord_NetHumanMachine_RoomCFGData> mMapData;
};
