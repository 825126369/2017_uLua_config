#pragma once
#include <map>
struct M_ExchangeCFGData
{
	//兑换ID
	int mChangeId;
	//所花费话费卷数量(单位分)
	int mCostTicket;
	//道具ID（与ItemCFG.xld道具ID对应)
	int mItemId;
	//要达到该等级才能兑换
	int mVip;
	//图标对应图片
	std::string mItemIcon;
	//标题对应图片
	std::string mItemName;
	//物品数量
	int mItemCount;
};

class M_ExchangeCFG
{
public:
private:
	static std::auto_ptr<M_ExchangeCFG> msSingleton;
public:
	int GetCount();
	const M_ExchangeCFGData* GetData(int ChangeId);
	const std::map<int, M_ExchangeCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_ExchangeCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_ExchangeCFGData> mMapData;
};
