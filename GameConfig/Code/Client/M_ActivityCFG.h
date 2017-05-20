#pragma once
#include <map>
struct M_ActivityCFGData
{
	//Key
	int mID;
	//活动名称
	std::string mActivityName;
	//开始时间
	std::string mStartTime;
	//结束时间 
	std::string mEndTime;
	//活动类型
	int mActivityType;
	//充值
	int mRechargeRMB;
	//VIP等级条件
	int mVipLevel;
	//登陆日期
	std::string mLoginDay;
	//奖励列表
	std::vector<int> mRewardList;
	//奖励个数
	std::vector<int> mRewardCount;
	//奖励邮件标题
	std::string mActivityRewardMailTitle;
	//奖励邮件内容
	std::string mActivityRewardMailContent;
	//奖励领取方式, 0:通过邮件 1:手动点击按钮领取
	int mReceiveWay;
};

class M_ActivityCFG
{
public:
private:
	static std::auto_ptr<M_ActivityCFG> msSingleton;
public:
	int GetCount();
	const M_ActivityCFGData* GetData(int ID);
	const std::map<int, M_ActivityCFGData>& GetMapData();
	void Load();
	void LoadLua();
	void Reload();
	static M_ActivityCFG* GetSingleton();
	static void Release();
private:
	std::map<int, M_ActivityCFGData> mMapData;
};
