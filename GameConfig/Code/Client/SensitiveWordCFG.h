#pragma once
#include <map>
struct SensitiveWordCFGData
{
	//ÐòºÅ
	int mID;
	//×Ö·û
	std::string mSensitiveWord;
};

class SensitiveWordCFG
{
public:
private:
	static std::auto_ptr<SensitiveWordCFG> msSingleton;
public:
	int GetCount();
	const SensitiveWordCFGData* GetData(int ID);
	const std::map<int, SensitiveWordCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static SensitiveWordCFG* GetSingleton();
	static void Release();
private:
	std::map<int, SensitiveWordCFGData> mMapData;
};
