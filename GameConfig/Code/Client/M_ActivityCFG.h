#pragma once
#include <map>
struct M_ActivityCFGData
{
	//Key
	int mID;
	//�����
	std::string mActivityName;
	//��ʼʱ��
	std::string mStartTime;
	//����ʱ�� 
	std::string mEndTime;
	//�����
	int mActivityType;
	//��ֵ
	int mRechargeRMB;
	//VIP�ȼ�����
	int mVipLevel;
	//��½����
	std::string mLoginDay;
	//�����б�
	std::vector<int> mRewardList;
	//��������
	std::vector<int> mRewardCount;
	//�����ʼ�����
	std::string mActivityRewardMailTitle;
	//�����ʼ�����
	std::string mActivityRewardMailContent;
	//������ȡ��ʽ, 0:ͨ���ʼ� 1:�ֶ������ť��ȡ
	int mReceiveWay;
};

class M_ActivityCFG
{
public:
private:
	static std::auto_ptr<M_ActivityCFG> msSingleton;
public:
	int GetCount();
	const M_ActivityCFGData* GetData(int ID);
	const std::map<int, M_ActivityCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_ActivityCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_ActivityCFGData> mMapData;
};
