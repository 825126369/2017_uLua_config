#pragma once
#include <map>
struct M_RechangeCFGData
{
	//��ֵID
	int mID;
	//����
	std::string mName;
	//����
	std::string mDesc;
	//����ICON
	std::string mNameIcon;
	//ICON
	std::string mIcon;
	//֧������ 1������ƽ̨ 2����֧����
	int mPayType;
	//���� 1��ʯ����ʯ 2�¿� 3���
	int mType;
	//�۸�
	int mPrice;
	//���
	int mGold;
	//�״��ͽ��
	int mFirstGold;
	//ÿ���ͽ��
	int mGiveGold;
	//ÿ������ȯ
	int mGiveTicket;
	//����vip����
	int mVIPExp;
	//��ʾ���
	int mIndex;
	//��ʾ�̵�
	int mShopType;
	//�������
	bool mFlag;
	//AppStore��ƷID
	std::string mAppStoreID;
};

class M_RechangeCFG
{
public:
private:
	static std::auto_ptr<M_RechangeCFG> msSingleton;
public:
	int GetCount();
	const M_RechangeCFGData* GetData(int ID);
	const std::map<int, M_RechangeCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_RechangeCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_RechangeCFGData> mMapData;
};
