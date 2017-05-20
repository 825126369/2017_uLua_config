HappySupremacy_BetMaxCFG = {}

function HappySupremacy_BetMaxCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function HappySupremacy_BetMaxCFG:init()
	self.datas = {}
	self.datas[1] = {ID = 1, GoldCount = 0, BetMax = 2000000000, CanUseWeight = {1}}
	self.datas[2] = {ID = 2, GoldCount = 0, BetMax = 2000000000, CanUseWeight = {1,2}}
	self.datas[3] = {ID = 3, GoldCount = 0, BetMax = 2000000000, CanUseWeight = {1,2,3}}
	self.datas[4] = {ID = 4, GoldCount = 0, BetMax = 2000000000, CanUseWeight = {1,2,3,4}}
	self.datas[5] = {ID = 5, GoldCount = 0, BetMax = 2000000000, CanUseWeight = {1,2,3,4,5}}
	self.datas[6] = {ID = 6, GoldCount = 0, BetMax = 2000000000, CanUseWeight = {1,2,3,4,5,6}}
	self.datas[7] = {ID = 7, GoldCount = 0, BetMax = 2000000000, CanUseWeight = {1,2,3,4,5,6,7}}
end

HappySupremacy_BetMaxCFG:init()
