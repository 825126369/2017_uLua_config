#pragma once
#include <map>
struct M_RobotHeadIconCFGData
{
	//����
	int mIndex;
	//��ͷ��
	int mboyIcon_MinIndex;
	//Ůͷ��
	int mgirlIcon;
};

class M_RobotHeadIconCFG
{
public:
private:
	static std::auto_ptr<M_RobotHeadIconCFG> msSingleton;
public:
	int GetCount();
	const M_RobotHeadIconCFGData* GetData(int Index);
	const std::map<int, M_RobotHeadIconCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_RobotHeadIconCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_RobotHeadIconCFGData> mMapData;
};
