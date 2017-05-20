#pragma once
#include <map>
struct M_OnlineRewardCFGData
{
	//Key
	int mID;
	//��ʼʱ��,���ڲ��ֲ�������
	std::string mStartTime;
	//����ʱ��,,���ڲ��ֲ�������
	std::string mEndTime;
	//VIP����
	int mConditionVip;
	//��ҽ���
	int mRewardCoin;
};

class M_OnlineRewardCFG
{
public:
private:
	static std::auto_ptr<M_OnlineRewardCFG> msSingleton;
public:
	int GetCount();
	const M_OnlineRewardCFGData* GetData(int ID);
	const std::map<int, M_OnlineRewardCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_OnlineRewardCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_OnlineRewardCFGData> mMapData;
};
