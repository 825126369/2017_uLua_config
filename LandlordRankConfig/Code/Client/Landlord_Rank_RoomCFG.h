#pragma once
#include <map>
struct Landlord_Rank_RoomCFGData
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

class Landlord_Rank_RoomCFG
{
public:
private:
	static std::auto_ptr<Landlord_Rank_RoomCFG> msSingleton;
public:
	int GetCount();
	const Landlord_Rank_RoomCFGData* GetData(int RoomID);
	const std::map<int, Landlord_Rank_RoomCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static Landlord_Rank_RoomCFG* GetSingleton();
private:
	std::map<int, Landlord_Rank_RoomCFGData> mMapData;
};
