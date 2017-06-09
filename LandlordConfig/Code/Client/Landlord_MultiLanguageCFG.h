#pragma once
#include <map>
struct Landlord_MultiLanguageCFGData
{
	//Key
	std::string mID;
	//ÖÐÎÄÃû×Ö
	std::string mName;
};

class Landlord_MultiLanguageCFG
{
public:
private:
	static std::auto_ptr<Landlord_MultiLanguageCFG> msSingleton;
public:
	int GetCount();
	const Landlord_MultiLanguageCFGData* GetData(std::string ID);
	const std::map<std::string, Landlord_MultiLanguageCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static Landlord_MultiLanguageCFG* GetSingleton();
private:
	std::map<std::string, Landlord_MultiLanguageCFGData> mMapData;
};
