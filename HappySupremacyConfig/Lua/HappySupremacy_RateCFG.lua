HappySupremacy_RateCFG = {}

function HappySupremacy_RateCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function HappySupremacy_RateCFG:init()
	self.datas = {}
	self.datas[1] = {Key = 1, Name = "顺门", Rate1 = 2, Rate2 = 0}
	self.datas[2] = {Key = 2, Name = "对门", Rate1 = 2, Rate2 = 0}
	self.datas[3] = {Key = 3, Name = "倒门", Rate1 = 2, Rate2 = 0}
	self.datas[4] = {Key = 4, Name = "顺对门", Rate1 = 2, Rate2 = 1}
	self.datas[5] = {Key = 5, Name = "倒对门", Rate1 = 2, Rate2 = 1}
	self.datas[6] = {Key = 6, Name = "顺倒门（桥）", Rate1 = 2, Rate2 = 1}
end

HappySupremacy_RateCFG:init()
