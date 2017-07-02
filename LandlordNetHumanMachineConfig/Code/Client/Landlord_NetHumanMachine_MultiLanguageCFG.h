#pragma once
#include <map>
struct Landlord_NetHumanMachine_MultiLanguageCFGData
{
	//Key
	std::string mID;
	//ÖÐÎÄÃû×Ö
	std::string mName;
};

class Landlord_NetHumanMachine_MultiLanguageCFG
{
public:
private:
	static std::auto_ptr<Landlord_NetHumanMachine_MultiLanguageCFG> msSingleton;
public:
	int GetCount();
	const Landlord_NetHumanMachine_MultiLanguageCFGData* GetData(std::string ID);
	const std::map<std::string, Landlord_NetHumanMachine_MultiLanguageCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static Landlord_NetHumanMachine_MultiLanguageCFG* GetSingleton();
private:
	std::map<std::string, Landlord_NetHumanMachine_MultiLanguageCFGData> mMapData;
};
