#pragma once
#include <map>
struct M_DailyLoginCFGData
{
	//编号
	int mID;
	//名字（图标下面的描述）
	std::string mName;
	//类型
	int mTpye;
	//数量（/VIP体验卡天数）
	int mCount;
	//图标
	std::string mIcon;
};

class M_DailyLoginCFG
{
public:
private:
	static std::auto_ptr<M_DailyLoginCFG> msSingleton;
public:
	int GetCount();
	const M_DailyLoginCFGData* GetData(int ID);
	const std::map<int, M_DailyLoginCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_DailyLoginCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_DailyLoginCFGData> mMapData;
};
