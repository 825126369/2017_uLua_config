#pragma once
#include <map>
struct M_SoundCFGData
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

class M_SoundCFG
{
public:
private:
	static std::auto_ptr<M_SoundCFG> msSingleton;
public:
	int GetCount();
	const M_SoundCFGData* GetData(int SoundID);
	const std::map<int, M_SoundCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_SoundCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_SoundCFGData> mMapData;
};
