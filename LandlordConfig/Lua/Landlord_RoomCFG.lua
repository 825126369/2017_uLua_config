Landlord_RoomCFG = {}

function Landlord_RoomCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function Landlord_RoomCFG:init()
	self.datas = {}
	self.datas[1] = {RoomID = 1, RoomName = "人机对战", IsOpen = true, RoomImage = "B_RoomItem_1", VipCondition = 0, GoldCondition = 1000, orShuffle = false}
	self.datas[2] = {RoomID = 2, RoomName = "自由匹配", IsOpen = true, RoomImage = "B_RoomItem_2", VipCondition = 0, GoldCondition = 100000, orShuffle = true}
	self.datas[3] = {RoomID = 3, RoomName = "排位赛", IsOpen = true, RoomImage = "B_RoomItem_2", VipCondition = 0, GoldCondition = 100000, orShuffle = true}
end

Landlord_RoomCFG:init()
