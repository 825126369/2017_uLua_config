#pragma once
#include <map>
struct M_FaceCFGData
{
	//ID
	int mID;
	//Ãû×Ö
	std::string mName;
	//Â·¾¶
	std::string mIcon;
};

class M_FaceCFG
{
public:
private:
	static std::auto_ptr<M_FaceCFG> msSingleton;
public:
	int GetCount();
	const M_FaceCFGData* GetData(int ID);
	const std::map<int, M_FaceCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_FaceCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_FaceCFGData> mMapData;
};
