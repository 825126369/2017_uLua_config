#pragma once
#include <map>
struct M_ItemCFGData
{
	//����ID
	int mItemId;
	//��Ʒ����
	std::string mItemName;
	//����
	std::string mItemDesc;
	//��Ʒͼ��
	std::string mIcon;
	//��Ʒ����
	int mItemCategory;
	//���߼�ֵ
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
