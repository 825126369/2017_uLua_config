#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
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
	boost::unordered_map<std::string, Landlord_NetHumanMachine_MultiLanguageCFGData>& GetMapData();
	void Reload();
	void Load();
	static Landlord_NetHumanMachine_MultiLanguageCFG* GetSingleton();
private:
	boost::unordered_map<std::string, Landlord_NetHumanMachine_MultiLanguageCFGData> mMapData;
};
