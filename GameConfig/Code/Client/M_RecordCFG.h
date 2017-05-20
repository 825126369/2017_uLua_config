#pragma once
#include <map>
struct M_RecordCFGData
{
	//ͳ��ID
	int mRecordID;
	//��¼����
	std::string mRecordName;
	//��¼��Ϣ�б�
	std::vector<std::string> mRecordInfoList;
};

class M_RecordCFG
{
public:
private:
	static std::auto_ptr<M_RecordCFG> msSingleton;
public:
	int GetCount();
	const M_RecordCFGData* GetData(int RecordID);
	const std::map<int, M_RecordCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_RecordCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_RecordCFGData> mMapData;
};
