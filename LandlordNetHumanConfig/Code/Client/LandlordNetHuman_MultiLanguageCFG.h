#pragma once
#include <map>
struct LandlordNetHuman_MultiLanguageCFGData
{
	//Key
	std::string mID;
	//ÖÐÎÄÃû×Ö
	std::string mName;
};

class LandlordNetHuman_MultiLanguageCFG
{
public:
private:
	static std::auto_ptr<LandlordNetHuman_MultiLanguageCFG> msSingleton;
public:
	int GetCount();
	const LandlordNetHuman_MultiLanguageCFGData* GetData(std::string ID);
	const std::map<std::string, LandlordNetHuman_MultiLanguageCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static LandlordNetHuman_MultiLanguageCFG* GetSingleton();
private:
	std::map<std::string, LandlordNetHuman_MultiLanguageCFGData> mMapData;
};
