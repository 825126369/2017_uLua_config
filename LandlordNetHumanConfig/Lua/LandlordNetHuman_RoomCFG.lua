LandlordNetHuman_RoomCFG = {}

function LandlordNetHuman_RoomCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function LandlordNetHuman_RoomCFG:init()
	self.datas = {}
	self.datas[1] = {RoomID = 1, RoomNamePrefix = "三人标准房", GoldCondition = 1000, orShuffle = false, deskCount = 3, Score = 100}
end

LandlordNetHuman_RoomCFG:init()
