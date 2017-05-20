M_OnlineRewardCFG = {}

function M_OnlineRewardCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_OnlineRewardCFG:init()
	self.datas = {}
	self.datas[1] = {ID = 1, StartTime = "2015-10-01 11:0:0", EndTime = "2015-10-01 11:59:59", ConditionVip = 0, RewardCoin = 1000}
	self.datas[2] = {ID = 2, StartTime = "2015-10-01 12:00:00", EndTime = "2015-10-01 12:59:59", ConditionVip = 1, RewardCoin = 1000}
	self.datas[3] = {ID = 3, StartTime = "2015-10-01 13:00:00", EndTime = "2015-10-01 13:59:59", ConditionVip = 0, RewardCoin = 1000}
	self.datas[4] = {ID = 4, StartTime = "2015-10-01 14:00:00", EndTime = "2015-10-01 14:59:59", ConditionVip = 1, RewardCoin = 1000}
	self.datas[5] = {ID = 5, StartTime = "2015-10-01 15:00:00", EndTime = "2015-10-01 15:59:59", ConditionVip = 0, RewardCoin = 1000}
	self.datas[6] = {ID = 6, StartTime = "2015-10-01 16:00:00", EndTime = "2015-10-01 16:59:59", ConditionVip = 1, RewardCoin = 1000}
	self.datas[7] = {ID = 7, StartTime = "2015-10-01 17:00:00", EndTime = "2015-10-01 17:59:59", ConditionVip = 0, RewardCoin = 1000}
	self.datas[8] = {ID = 8, StartTime = "2015-10-01 18:00:00", EndTime = "2015-10-01 18:59:59", ConditionVip = 2, RewardCoin = 2000}
	self.datas[9] = {ID = 9, StartTime = "2015-10-01 19:00:00", EndTime = "2015-10-01 19:59:59", ConditionVip = 0, RewardCoin = 1000}
	self.datas[10] = {ID = 10, StartTime = "2015-10-01 20:00:00", EndTime = "2015-10-01 20:59:59", ConditionVip = 2, RewardCoin = 2000}
	self.datas[11] = {ID = 11, StartTime = "2015-10-01 21:00:00", EndTime = "2015-10-01 21:59:59", ConditionVip = 0, RewardCoin = 1000}
	self.datas[12] = {ID = 12, StartTime = "2015-10-01 22:00:00", EndTime = "2015-10-01 22:59:59", ConditionVip = 2, RewardCoin = 2000}
end

M_OnlineRewardCFG:init()
