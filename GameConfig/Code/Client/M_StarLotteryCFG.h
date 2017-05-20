#pragma once
#include <map>
struct M_StarLotteryCFGData
{
	//����
	int mIndex;
	//����
	int mStarLvl;
	//��Ʒ����
	int mItemType;
	//��Ʒ����
	int mItemCount;
	//���ɼ���(10000)
	int mRate1;
	//���ɼ���(10000)
	int mRate2;
	//���ɼ���(10000)
	int mRate3;
	//���ɼ���(10000)
	int mRate4;
};

class M_StarLotteryCFG
{
public:
private:
	static std::auto_ptr<M_StarLotteryCFG> msSingleton;
public:
	int GetCount();
	const M_StarLotteryCFGData* GetData(int Index);
	const std::map<int, M_StarLotteryCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_StarLotteryCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_StarLotteryCFGData> mMapData;
};
