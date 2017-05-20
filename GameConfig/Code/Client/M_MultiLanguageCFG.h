#pragma once
#include <map>
struct M_MultiLanguageCFGData
{
	//Key
	std::string mID;
	//ÖÐÎÄÃû×Ö
	std::string mName;
};

class M_MultiLanguageCFG
{
public:
private:
	static std::auto_ptr<M_MultiLanguageCFG> msSingleton;
public:
	int GetCount();
	const M_MultiLanguageCFGData* GetData(std::string ID);
	const std::map<std::string, M_MultiLanguageCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_MultiLanguageCFG* GetSingleton();
	static void Release();
private:
	std::map<std::string, M_MultiLanguageCFGData> mMapData;
};
