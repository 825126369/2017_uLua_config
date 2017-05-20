#pragma once
#include <map>
struct M_ChipCFGData
{
	//key
	int mID;
	//对应金额
	int mCount;
	//对应图片
	std::string mIcon;
	//是否选中
	bool mIsCheck;
};

class M_ChipCFG
{
public:
private:
	static std::auto_ptr<M_ChipCFG> msSingleton;
public:
	int GetCount();
	const M_ChipCFGData* GetData(int ID);
	const std::map<int, M_ChipCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_ChipCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_ChipCFGData> mMapData;
};
