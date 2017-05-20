#pragma once
#include <map>
struct M_ActivityMultiLanguageCFGData
{
	//Key
	std::string mID;
	//ÖÐÎÄÃû×Ö
	std::string mName;
};

class M_ActivityMultiLanguageCFG
{
public:
private:
	static std::auto_ptr<M_ActivityMultiLanguageCFG> msSingleton;
public:
	int GetCount();
	const M_ActivityMultiLanguageCFGData* GetData(std::string ID);
	const std::map<std::string, M_ActivityMultiLanguageCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_ActivityMultiLanguageCFG* GetSingleton();
	static void Release();
private:
	std::map<std::string, M_ActivityMultiLanguageCFGData> mMapData;
};
