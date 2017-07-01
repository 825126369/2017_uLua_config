#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct LandlordNetHuman_SoundCFGData
{
	//����ID
	int mSoundID;
	//��������
	std::string mSoundName;
	//����·��
	std::string mSoundPath;
	//����ʱ��
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
	boost::unordered_map<int, LandlordNetHuman_SoundCFGData>& GetMapData();
	void Reload();
	void Load();
	static LandlordNetHuman_SoundCFG* GetSingleton();
private:
	boost::unordered_map<int, LandlordNetHuman_SoundCFGData> mMapData;
};
