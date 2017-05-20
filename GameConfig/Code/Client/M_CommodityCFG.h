#pragma once
#include <map>
struct M_CommodityCFGData
{
	//��ƷID
	int mCommodityId;
	//��Ʒ����
	std::string mName;
	//��Ʒ����(3.����5.���)
	int mCommodityType;
	//�۸�����(1��� 2��ȯ)
	int mPriceType;
	//ʵ�ʼ۸�
	int mPrice;
	//�������ߣ���ӦItemCFG.xls��
	std::vector<int> mItem;
	//�Ƿ��ܹ���(�Ƿ���ʾ)
	bool mIsCanBuy;
	//����
	std::vector<int> mCount;
};

class M_CommodityCFG
{
public:
private:
	static std::auto_ptr<M_CommodityCFG> msSingleton;
public:
	int GetCount();
	const M_CommodityCFGData* GetData(int CommodityId);
	const std::map<int, M_CommodityCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_CommodityCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_CommodityCFGData> mMapData;
};
