Landlord_RoomCFG = {}

function Landlord_RoomCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function Landlord_RoomCFG:init()
	self.datas = {}
	self.datas[1] = {RoomID = 1, RoomName = "人机对战", IsOpen = true, RobTag = {1,2,3}, RoomImage = "B_RoomItem_1", VipCondition = 0, GoldCondition = 1000, BetMax = 10000, RobCount = 10}
	self.datas[2] = {RoomID = 2, RoomName = "自由匹配", IsOpen = false, RobTag = {1,2,3}, RoomImage = "B_RoomItem_2", VipCondition = 0, GoldCondition = 100000, BetMax = 100000, RobCount = 10}
	self.datas[3] = {RoomID = 3, RoomName = "排位赛", IsOpen = false, RobTag = {1,2,3}, RoomImage = "B_RoomItem_2", VipCondition = 0, GoldCondition = 100000, BetMax = 100000, RobCount = 10}
end

Landlord_RoomCFG:init()
