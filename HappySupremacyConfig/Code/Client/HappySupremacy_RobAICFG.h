#pragma once
#include <map>
struct HappySupremacy_RobAICFGData
{
	//Key
	int mID;
	//��עƫ��
	std::string mBetName;
	//��ע����(˳��:0������,1��˳�ǣ�2������,3:˳���ţ��ǣ�,4:�����ţ��ǣ�,5:˳���ţ��ţ����ţ�)(�ٷֱ�)
	std::vector<int> mBetRate;
};

class HappySupremacy_RobAICFG
{
public:
private:
	static std::auto_ptr<HappySupremacy_RobAICFG> msSingleton;
public:
	int GetCount();
	const HappySupremacy_RobAICFGData* GetData(int ID);
	const std::map<int, HappySupremacy_RobAICFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static HappySupremacy_RobAICFG* GetSingleton();
private:
	std::map<int, HappySupremacy_RobAICFGData> mMapData;
};
