#pragma once
#include <map>
struct M_GameCFGData
{
	//key
	int mID;
	//��Ϸ����
	std::string mGameName;
	//�Ƿ񿪷�
	bool mIsOpen;
};

class M_GameCFG
{
public:
private:
	static std::auto_ptr<M_GameCFG> msSingleton;
public:
	int GetCount();
	const M_GameCFGData* GetData(int ID);
	const std::map<int, M_GameCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_GameCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_GameCFGData> mMapData;
};
