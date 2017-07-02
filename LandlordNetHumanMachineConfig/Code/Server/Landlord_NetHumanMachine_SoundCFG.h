#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct Landlord_NetHumanMachine_SoundCFGData
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

class Landlord_NetHumanMachine_SoundCFG
{
public:
private:
	static std::auto_ptr<Landlord_NetHumanMachine_SoundCFG> msSingleton;
public:
	int GetCount();
	const Landlord_NetHumanMachine_SoundCFGData* GetData(int SoundID);
	boost::unordered_map<int, Landlord_NetHumanMachine_SoundCFGData>& GetMapData();
	void Reload();
	void Load();
	static Landlord_NetHumanMachine_SoundCFG* GetSingleton();
private:
	boost::unordered_map<int, Landlord_NetHumanMachine_SoundCFGData> mMapData;
};
