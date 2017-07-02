#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
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
	boost::unordered_map<std::string, Landlord_Rank_MultiLanguageCFGData>& GetMapData();
	void Reload();
	void Load();
	static Landlord_Rank_MultiLanguageCFG* GetSingleton();
private:
	boost::unordered_map<std::string, Landlord_Rank_MultiLanguageCFGData> mMapData;
};
