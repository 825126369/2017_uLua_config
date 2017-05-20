#pragma once
#include <map>
struct M_DailyLoginCFGData
{
	//���
	int mID;
	//���֣�ͼ�������������
	std::string mName;
	//����
	int mTpye;
	//������/VIP���鿨������
	int mCount;
	//ͼ��
	std::string mIcon;
};

class M_DailyLoginCFG
{
public:
private:
	static std::auto_ptr<M_DailyLoginCFG> msSingleton;
public:
	int GetCount();
	const M_DailyLoginCFGData* GetData(int ID);
	const std::map<int, M_DailyLoginCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_DailyLoginCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_DailyLoginCFGData> mMapData;
};
