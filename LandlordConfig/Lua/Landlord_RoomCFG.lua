Landlord_RoomCFG = {}

function Landlord_RoomCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function Landlord_RoomCFG:init()
	self.datas = {}
	self.datas[1] = {RoomID = 1, RoomName = "初级房", IsOpen = true, RoomImage = "B_RoomItem_1", VipCondition = 0, GoldCondition = 1000, orShuffle = false, deskCount = 3, Score = 100}
	self.datas[2] = {RoomID = 2, RoomName = "中级房", IsOpen = true, RoomImage = "B_RoomItem_2", VipCondition = 0, GoldCondition = 1000, orShuffle = true, deskCount = 3, Score = 200}
	self.datas[3] = {RoomID = 3, RoomName = "高级房", IsOpen = true, RoomImage = "B_RoomItem_2", VipCondition = 0, GoldCondition = 1000, orShuffle = true, deskCount = 3, Score = 300}
end

Landlord_RoomCFG:init()
