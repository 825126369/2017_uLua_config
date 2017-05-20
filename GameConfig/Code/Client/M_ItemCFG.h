#pragma once
#include <map>
struct M_ItemCFGData
{
	//道具ID
	int mItemId;
	//物品名称
	std::string mItemName;
	//描述
	std::string mItemDesc;
	//物品图标
	std::string mIcon;
	//物品类型
	int mItemCategory;
	//道具价值
	int mItemValue;
};

class M_ItemCFG
{
public:
private:
	static std::auto_ptr<M_ItemCFG> msSingleton;
public:
	int GetCount();
	const M_ItemCFGData* GetData(int ItemId);
	const std::map<int, M_ItemCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_ItemCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_ItemCFGData> mMapData;
};
