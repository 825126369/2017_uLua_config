#pragma once
#include <map>
struct HappySupremacy_SoundCFGData
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

class HappySupremacy_SoundCFG
{
public:
private:
	static std::auto_ptr<HappySupremacy_SoundCFG> msSingleton;
public:
	int GetCount();
	const HappySupremacy_SoundCFGData* GetData(int SoundID);
	const std::map<int, HappySupremacy_SoundCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static HappySupremacy_SoundCFG* GetSingleton();
private:
	std::map<int, HappySupremacy_SoundCFGData> mMapData;
};
