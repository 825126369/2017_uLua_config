#pragma once
#include <map>
struct M_GiftCFGData
{
	//����ID
	int mGiftId;
	//�������
	int mCoin;
	//�Ƿ���ʾ
	int misShow;
	//���(������)
	float mPercent;
	//����VIP�ȼ�
	int mVip;
	//���ŵĶ���
	std::string mAction;
	//��Ʒ����������
	std::string mTextIcon;
};

class M_GiftCFG
{
public:
private:
	static std::auto_ptr<M_GiftCFG> msSingleton;
public:
	int GetCount();
	const M_GiftCFGData* GetData(int GiftId);
	const std::map<int, M_GiftCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_GiftCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_GiftCFGData> mMapData;
};
