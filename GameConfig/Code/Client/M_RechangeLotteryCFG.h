#pragma once
#include <map>
struct M_RechangeLotteryCFGData
{
	//�н�����
	int mMuch;
	//�״μ��ʣ�10000��
	int mFirstRate;
	//Ĭ�ϼ���(10000)
	int mDefaultRate;
};

class M_RechangeLotteryCFG
{
public:
private:
	static std::auto_ptr<M_RechangeLotteryCFG> msSingleton;
public:
	int GetCount();
	const M_RechangeLotteryCFGData* GetData(int Much);
	const std::map<int, M_RechangeLotteryCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_RechangeLotteryCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_RechangeLotteryCFGData> mMapData;
};
