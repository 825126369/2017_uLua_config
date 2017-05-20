#pragma once
#include <map>
struct M_ThirdPluginCFGData
{
	//������
	std::string mChannelID;
	//ƽ̨
	std::string mPlatform;
	//�ű�·��
	std::string mLuaFilePath;
	//��ע
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
