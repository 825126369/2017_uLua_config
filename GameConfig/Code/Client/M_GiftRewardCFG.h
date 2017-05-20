#pragma once
#include <map>
struct M_GiftRewardCFGData
{
	//��������
	int mRewardType;
	//����ID
	std::vector<int> mItemId;
	//����
	std::vector<int> mItemCount;
};

class M_GiftRewardCFG
{
public:
private:
	static std::auto_ptr<M_GiftRewardCFG> msSingleton;
public:
	int GetCount();
	const M_GiftRewardCFGData* GetData(int RewardType);
	const std::map<int, M_GiftRewardCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_GiftRewardCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_GiftRewardCFGData> mMapData;
};
