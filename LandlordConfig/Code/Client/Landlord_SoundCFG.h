#pragma once
#include <map>
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
	const std::map<int, Landlord_SoundCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static Landlord_SoundCFG* GetSingleton();
private:
	std::map<int, Landlord_SoundCFGData> mMapData;
};
