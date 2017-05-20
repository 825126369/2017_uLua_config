#pragma once
#include <map>
struct HappySupremacy_MultiLanguageCFGData
{
	//Key
	std::string mID;
	//��������
	std::string mName;
};

class HappySupremacy_MultiLanguageCFG
{
public:
private:
	static std::auto_ptr<HappySupremacy_MultiLanguageCFG> msSingleton;
public:
	int GetCount();
	const HappySupremacy_MultiLanguageCFGData* GetData(std::string ID);
	const std::map<std::string, HappySupremacy_MultiLanguageCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static HappySupremacy_MultiLanguageCFG* GetSingleton();
private:
	std::map<std::string, HappySupremacy_MultiLanguageCFGData> mMapData;
};
