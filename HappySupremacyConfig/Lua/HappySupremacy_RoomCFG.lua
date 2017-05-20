HappySupremacy_RoomCFG = {}

function HappySupremacy_RoomCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function HappySupremacy_RoomCFG:init()
	self.datas = {}
	self.datas[1] = {RoomID = 1, RoomName = "初级场", WeightList = {10,1000,10000,100000,1000000}, IsOpen = true, BankerCondition = 5000000, FirstBankerCost = 500000, AddBankerCost = 500000, LeaveBankerCost = 0, AutoLeaveBanker = 1500000, PlayerMaxCount = 5000, RobTag = {1,2,3}, CreateProb = {40,30,30}, RoomImage = "B_RoomItem_1", VipCondition = 0, GoldCondition = 1000, BetMax = 10000, RobCount = 10}
	self.datas[2] = {RoomID = 2, RoomName = "中级场", WeightList = {10,1000,10000,100000,1000000}, IsOpen = false, BankerCondition = 10000000, FirstBankerCost = 1000000, AddBankerCost = 1000000, LeaveBankerCost = 0, AutoLeaveBanker = 1500000, PlayerMaxCount = 5000, RobTag = {1,2,3}, CreateProb = {40,30,30}, RoomImage = "B_RoomItem_2", VipCondition = 0, GoldCondition = 100000, BetMax = 100000, RobCount = nil}
end

HappySupremacy_RoomCFG:init()
