#pragma once
#include <map>
struct M_ExchangeCFGData
{
	//�һ�ID
	int mChangeId;
	//�����ѻ��Ѿ�����(��λ��)
	int mCostTicket;
	//����ID����ItemCFG.xld����ID��Ӧ)
	int mItemId;
	//Ҫ�ﵽ�õȼ����ܶһ�
	int mVip;
	//ͼ���ӦͼƬ
	std::string mItemIcon;
	//�����ӦͼƬ
	std::string mItemName;
	//��Ʒ����
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
