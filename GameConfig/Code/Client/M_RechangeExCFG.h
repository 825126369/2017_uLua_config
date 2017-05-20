#pragma once
#include <map>
struct M_RechangeExCFGData
{
	//渠道ID
	int mID;
	//渠道对应的paycode(顺序索引对应M_RechangeCFG.xls表充值ID)
	std::vector<int> mPayCodes;
};

class M_RechangeExCFG
{
public:
private:
	static std::auto_ptr<M_RechangeExCFG> msSingleton;
public:
	int GetCount();
	const M_RechangeExCFGData* GetData(int ID);
	const std::map<int, M_RechangeExCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_RechangeExCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_RechangeExCFGData> mMapData;
};
