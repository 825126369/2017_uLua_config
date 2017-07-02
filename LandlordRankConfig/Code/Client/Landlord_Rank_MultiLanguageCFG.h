#pragma once
#include <map>
struct Landlord_Rank_MultiLanguageCFGData
{
	//Key
	std::string mID;
	//ÖÐÎÄÃû×Ö
	std::string mName;
};

class Landlord_Rank_MultiLanguageCFG
{
public:
private:
	static std::auto_ptr<Landlord_Rank_MultiLanguageCFG> msSingleton;
public:
	int GetCount();
	const Landlord_Rank_MultiLanguageCFGData* GetData(std::string ID);
	const std::map<std::string, Landlord_Rank_MultiLanguageCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static Landlord_Rank_MultiLanguageCFG* GetSingleton();
private:
	std::map<std::string, Landlord_Rank_MultiLanguageCFGData> mMapData;
};
