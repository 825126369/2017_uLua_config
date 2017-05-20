#pragma once
#include <map>
struct HappySupremacy_RoomStockCFGData
{
	//����id
	int mRoomID;
	//��ˮ
	float mDeduct;
	//Ĭ�Ͽ��
	int mDefaultStock;
	//���ˮλ(10��)
	std::vector<int> mStock;
	//�ŷָ��ʣ�10����
	std::vector<int> mScoreId;
};

class HappySupremacy_RoomStockCFG
{
public:
private:
	static std::auto_ptr<HappySupremacy_RoomStockCFG> msSingleton;
public:
	int GetCount();
	const HappySupremacy_RoomStockCFGData* GetData(int RoomID);
	const std::map<int, HappySupremacy_RoomStockCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static HappySupremacy_RoomStockCFG* GetSingleton();
private:
	std::map<int, HappySupremacy_RoomStockCFGData> mMapData;
};
