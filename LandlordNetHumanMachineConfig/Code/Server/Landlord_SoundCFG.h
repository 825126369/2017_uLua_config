#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct Landlord_SoundCFGData
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

class Landlord_SoundCFG
{
public:
private:
	static std::auto_ptr<Landlord_SoundCFG> msSingleton;
public:
	int GetCount();
	const Landlord_SoundCFGData* GetData(int SoundID);
	boost::unordered_map<int, Landlord_SoundCFGData>& GetMapData();
	void Reload();
	void Load();
	static Landlord_SoundCFG* GetSingleton();
private:
	boost::unordered_map<int, Landlord_SoundCFGData> mMapData;
};
