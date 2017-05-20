#pragma once
#include <map>
struct M_DialLotteryCFGData
{
	//���
	int mID;
	//�������
	int mRewardCoin;
	//��������(1:���    2:��ȯ)
	int mRewardType;
	//ͼ�����ű���
	float mScale;
	//��ƷICON
	std::string mIcon;
	//�񽱸���
	int mProbability;
};

class M_DialLotteryCFG
{
public:
private:
	static std::auto_ptr<M_DialLotteryCFG> msSingleton;
public:
	int GetCount();
	const M_DialLotteryCFGData* GetData(int ID);
	const std::map<int, M_DialLotteryCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_DialLotteryCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_DialLotteryCFGData> mMapData;
};
