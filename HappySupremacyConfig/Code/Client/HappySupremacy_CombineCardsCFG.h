#pragma once
#include <map>
struct HappySupremacy_CombineCardsCFGData
{
	//组合牌ID
	int mCombineCardID;
	//组合牌的名字
	std::string mCombineCardsName;
};

class HappySupremacy_CombineCardsCFG
{
public:
private:
	static std::auto_ptr<HappySupremacy_CombineCardsCFG> msSingleton;
public:
	int GetCount();
	const HappySupremacy_CombineCardsCFGData* GetData(int CombineCardID);
	const std::map<int, HappySupremacy_CombineCardsCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static HappySupremacy_CombineCardsCFG* GetSingleton();
private:
	std::map<int, HappySupremacy_CombineCardsCFGData> mMapData;
};
