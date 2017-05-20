#pragma once
#include <map>
struct M_ThirdPluginCFGData
{
	//渠道号
	std::string mChannelID;
	//平台
	std::string mPlatform;
	//脚本路径
	std::string mLuaFilePath;
	//备注
	std::string mRemark;
};

class M_ThirdPluginCFG
{
public:
private:
	static std::auto_ptr<M_ThirdPluginCFG> msSingleton;
public:
	int GetCount();
	const M_ThirdPluginCFGData* GetData(std::string ChannelID);
	const std::map<std::string, M_ThirdPluginCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_ThirdPluginCFG* GetSingleton();
	static void Release();
private:
	std::map<std::string, M_ThirdPluginCFGData> mMapData;
};
