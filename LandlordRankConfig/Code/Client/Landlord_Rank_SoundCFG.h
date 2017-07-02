#pragma once
#include <map>
struct Landlord_Rank_SoundCFGData
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

class Landlord_Rank_SoundCFG
{
public:
private:
	static std::auto_ptr<Landlord_Rank_SoundCFG> msSingleton;
public:
	int GetCount();
	const Landlord_Rank_SoundCFGData* GetData(int SoundID);
	const std::map<int, Landlord_Rank_SoundCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static Landlord_Rank_SoundCFG* GetSingleton();
private:
	std::map<int, Landlord_Rank_SoundCFGData> mMapData;
};
