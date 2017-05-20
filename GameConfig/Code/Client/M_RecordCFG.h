#pragma once
#include <map>
struct M_RecordCFGData
{
	//统计ID
	int mRecordID;
	//记录名称
	std::string mRecordName;
	//记录信息列表
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
