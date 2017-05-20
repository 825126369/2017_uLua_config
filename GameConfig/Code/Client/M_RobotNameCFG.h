#pragma once
#include <map>
struct M_RobotNameCFGData
{
	//Ë÷Òý
	int mIndex;
	//êÇ³Æ
	std::string mNickName;
};

class M_RobotNameCFG
{
public:
private:
	static std::auto_ptr<M_RobotNameCFG> msSingleton;
public:
	int GetCount();
	const M_RobotNameCFGData* GetData(int Index);
	const std::map<int, M_RobotNameCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_RobotNameCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_RobotNameCFGData> mMapData;
};
