#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct Landlord_Rank_SoundCFGData
{
	//ÉùÒôID
	int mSoundID;
	//ÉùÒôÃû×Ö
	std::string mSoundName;
	//ÉùÒôÂ·¾¶
	std::string mSoundPath;
	//ÉùÒôÊ±¼ä
	int mSoundTime;
};

class Landlord_Rank_SoundCFG
{
public:
private:
	static std::auto_ptr<Landlord_Rank_SoundCFG> msSingleton;
public:
	int GetCount();
	const Landlord_Rank_SoundCFGData* GetData(int SoundID);
	boost::unordered_map<int, Landlord_Rank_SoundCFGData>& GetMapData();
	void Reload();
	void Load();
	static Landlord_Rank_SoundCFG* GetSingleton();
private:
	boost::unordered_map<int, Landlord_Rank_SoundCFGData> mMapData;
};
