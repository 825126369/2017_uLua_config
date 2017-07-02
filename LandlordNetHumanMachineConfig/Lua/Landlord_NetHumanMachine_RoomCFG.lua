Landlord_NetHumanMachine_RoomCFG = {}

function Landlord_NetHumanMachine_RoomCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function Landlord_NetHumanMachine_RoomCFG:init()
	self.datas = {}
	self.datas[1] = {RoomID = 1, RoomName = "初级房", IsOpen = true, RoomImage = "B_RoomItem_1", GoldCondition = 1000, orShuffle = false, deskCount = 3, Score = 100}
	self.datas[2] = {RoomID = 2, RoomName = "中级房", IsOpen = true, RoomImage = "B_RoomItem_2", GoldCondition = 1000, orShuffle = false, deskCount = 3, Score = 200}
	self.datas[3] = {RoomID = 3, RoomName = "高级房", IsOpen = true, RoomImage = "B_RoomItem_2", GoldCondition = 1000, orShuffle = false, deskCount = 3, Score = 300}
	self.datas[4] = {RoomID = 4, RoomName = "初级房", IsOpen = true, RoomImage = "B_RoomItem_1", GoldCondition = 1000, orShuffle = true, deskCount = 3, Score = 100}
	self.datas[5] = {RoomID = 5, RoomName = "中级房", IsOpen = true, RoomImage = "B_RoomItem_2", GoldCondition = 1000, orShuffle = true, deskCount = 3, Score = 200}
	self.datas[6] = {RoomID = 6, RoomName = "高级房", IsOpen = true, RoomImage = "B_RoomItem_2", GoldCondition = 1000, orShuffle = true, deskCount = 3, Score = 300}
end

Landlord_NetHumanMachine_RoomCFG:init()
