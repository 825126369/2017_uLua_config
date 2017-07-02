#pragma once
#include <map>
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
	const std::map<int, Landlord_NetHumanMachine_RoomCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static Landlord_NetHumanMachine_RoomCFG* GetSingleton();
private:
	std::map<int, Landlord_NetHumanMachine_RoomCFGData> mMapData;
};
