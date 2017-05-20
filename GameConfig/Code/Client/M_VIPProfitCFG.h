#pragma once
#include <map>
struct M_VIPProfitCFGData
{
	//vip�ȼ�
	int mVipLv;
	//�������辭��
	int mVipExp;
	//��ȡ���߽�������
	int mOnlineReward;
	//ÿ����������
	long long mMaxGiftslimit;
	//��������
	std::vector<std::string> mGiftUnlock;
	//�������
	std::vector<std::string> mRoomUnlock;
	//������߽���
	std::vector<std::string> mFishItemUnlock;
	//���VIP��־
	int mVipName;
	//ÿ��������ȯ
	int mGiveTicket;
	//ÿ�ճ齱��������
	int mDailyLottery;
};

class M_VIPProfitCFG
{
public:
private:
	static std::auto_ptr<M_VIPProfitCFG> msSingleton;
public:
	int GetCount();
	const M_VIPProfitCFGData* GetData(int VipLv);
	const std::map<int, M_VIPProfitCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_VIPProfitCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_VIPProfitCFGData> mMapData;
};
