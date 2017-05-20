#pragma once
#include <map>
struct HappySupremacy_RobCFGData
{
	//Key
	int mID;
	//��ұ�ǩ
	std::string mName;
	//�����Сֵ
	int mGoldMin;
	//������ֵ
	int mGoldMax;
	//VIP��Сֵ
	int mVipMin;
	//VIP���ֵ
	int mVipMax;
};

class HappySupremacy_RobCFG
{
public:
private:
	static std::auto_ptr<HappySupremacy_RobCFG> msSingleton;
public:
	int GetCount();
	const HappySupremacy_RobCFGData* GetData(int ID);
	const std::map<int, HappySupremacy_RobCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static HappySupremacy_RobCFG* GetSingleton();
private:
	std::map<int, HappySupremacy_RobCFGData> mMapData;
};
