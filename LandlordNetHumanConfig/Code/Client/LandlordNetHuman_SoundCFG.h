#pragma once
#include <map>
struct LandlordNetHuman_SoundCFGData
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

class LandlordNetHuman_SoundCFG
{
public:
private:
	static std::auto_ptr<LandlordNetHuman_SoundCFG> msSingleton;
public:
	int GetCount();
	const LandlordNetHuman_SoundCFGData* GetData(int SoundID);
	const std::map<int, LandlordNetHuman_SoundCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static LandlordNetHuman_SoundCFG* GetSingleton();
private:
	std::map<int, LandlordNetHuman_SoundCFGData> mMapData;
};
