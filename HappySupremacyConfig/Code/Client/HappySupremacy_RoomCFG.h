#pragma once
#include <map>
struct HappySupremacy_RoomCFGData
{
	//����id
	int mRoomID;
	//������
	std::string mRoomName;
	//�����б�
	std::vector<int> mWeightList;
	//�Ƿ񿪷�
	bool mIsOpen;
	//��ׯ����(���)
	int mBankerCondition;
	//��ׯ����(���)
	int mFirstBankerCost;
	//ÿ����ׯ�����ۼ�ֵ(���)
	int mAddBankerCost;
	//��ǰ��ׯ����(��ȯ)
	int mLeaveBankerCost;
	//�Զ���ׯ����(���)
	int mAutoLeaveBanker;
	//���������������
	int mPlayerMaxCount;
	//�����˱�ǩ
	std::vector<int> mRobTag;
	//��Ӧ����(�ٷֱ�)
	std::vector<int> mCreateProb;
	//����ͼƬ
	std::string mRoomImage;
	//����VIP����
	int mVipCondition;
	//�����������
	int mGoldCondition;
	//�����ע��
	int mBetMax;
	//����������
	int mRobCount;
};

class HappySupremacy_RoomCFG
{
public:
private:
	static std::auto_ptr<HappySupremacy_RoomCFG> msSingleton;
public:
	int GetCount();
	const HappySupremacy_RoomCFGData* GetData(int RoomID);
	const std::map<int, HappySupremacy_RoomCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static HappySupremacy_RoomCFG* GetSingleton();
private:
	std::map<int, HappySupremacy_RoomCFGData> mMapData;
};
