#pragma once
#include <map>
struct M_BaseInfoCFGData
{
	//Key
	std::string mKey;
	//ÊýÖµ
	int mValue;
};

class M_BaseInfoCFG
{
public:
private:
	static std::auto_ptr<M_BaseInfoCFG> msSingleton;
public:
	int GetCount();
	const M_BaseInfoCFGData* GetData(std::string Key);
	const std::map<std::string, M_BaseInfoCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_BaseInfoCFG* GetSingleton();
	static void Release();
private:
	std::map<std::string, M_BaseInfoCFGData> mMapData;
};
