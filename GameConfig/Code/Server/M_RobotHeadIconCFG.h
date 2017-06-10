#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
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
	boost::unordered_map<int, M_RobotHeadIconCFGData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_RobotHeadIconCFG* GetSingleton();
private:
	boost::unordered_map<int, M_RobotHeadIconCFGData> mMapData;
};
