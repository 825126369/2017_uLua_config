#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
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
	boost::unordered_map<std::string, Landlord_MultiLanguageCFGData>& GetMapData();
	void Reload();
	void Load();
	static Landlord_MultiLanguageCFG* GetSingleton();
private:
	boost::unordered_map<std::string, Landlord_MultiLanguageCFGData> mMapData;
};
