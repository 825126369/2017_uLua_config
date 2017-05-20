#pragma once
#include <map>
struct M_ShieldGameData
{
	//����ID
	int mChannelID;
	//��������(1Ϊֻ����2Ϊֻ����)
	int mType;
	//��������\������Ϸ�б�
	std::vector<int> mShieldGameList;
	//��ʾ�ɾ�����
	std::vector<int> mShowAchieveList;
};

class M_ShieldGame
{
public:
private:
	static std::auto_ptr<M_ShieldGame> msSingleton;
public:
	int GetCount();
	const M_ShieldGameData* GetData(int ChannelID);
	const std::map<int, M_ShieldGameData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_ShieldGame* GetSingleton();
	static void Release();
private:
	std::map<int, M_ShieldGameData> mMapData;
};
