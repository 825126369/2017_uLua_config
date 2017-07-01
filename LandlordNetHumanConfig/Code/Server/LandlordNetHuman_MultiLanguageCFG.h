#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
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
	boost::unordered_map<std::string, LandlordNetHuman_MultiLanguageCFGData>& GetMapData();
	void Reload();
	void Load();
	static LandlordNetHuman_MultiLanguageCFG* GetSingleton();
private:
	boost::unordered_map<std::string, LandlordNetHuman_MultiLanguageCFGData> mMapData;
};
