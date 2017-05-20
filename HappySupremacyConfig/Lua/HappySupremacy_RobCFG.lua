HappySupremacy_RobCFG = {}

function HappySupremacy_RobCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function HappySupremacy_RobCFG:init()
	self.datas = {}
	self.datas[1] = {ID = 1, Name = "屌丝玩家", GoldMin = 4000000, GoldMax = 20000000, VipMin = 0, VipMax = 1}
	self.datas[2] = {ID = 2, Name = "普通玩家", GoldMin = 4000000, GoldMax = 30000000, VipMin = 1, VipMax = 2}
	self.datas[3] = {ID = 3, Name = "土豪玩家", GoldMin = 4000000, GoldMax = 50000000, VipMin = 3, VipMax = 5}
end

HappySupremacy_RobCFG:init()
