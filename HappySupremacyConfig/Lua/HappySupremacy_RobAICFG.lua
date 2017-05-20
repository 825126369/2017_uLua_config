HappySupremacy_RobAICFG = {}

function HappySupremacy_RobAICFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function HappySupremacy_RobAICFG:init()
	self.datas = {}
	self.datas[1] = {ID = 1, BetName = "1爱好1", BetRate = {10,50,10,10,10,10}}
	self.datas[2] = {ID = 2, BetName = "1爱好2", BetRate = {15,55,5,5,10,10}}
	self.datas[3] = {ID = 3, BetName = "1爱好3", BetRate = {5,60,5,5,15,10}}
	self.datas[4] = {ID = 4, BetName = "1爱好4", BetRate = {5,65,0,0,20,10}}
	self.datas[5] = {ID = 5, BetName = "1爱好5", BetRate = {5,65,0,5,15,10}}
	self.datas[6] = {ID = 6, BetName = "2爱好1", BetRate = {10,10,10,10,50,10}}
	self.datas[7] = {ID = 7, BetName = "2爱好2", BetRate = {10,15,5,5,55,10}}
	self.datas[8] = {ID = 8, BetName = "2爱好3", BetRate = {5,15,5,5,60,10}}
	self.datas[9] = {ID = 9, BetName = "2爱好4", BetRate = {0,25,0,0,65,10}}
	self.datas[10] = {ID = 10, BetName = "2爱好5", BetRate = {0,20,5,0,65,10}}
	self.datas[11] = {ID = 11, BetName = "3爱好1", BetRate = {15,25,15,15,15,15}}
	self.datas[12] = {ID = 12, BetName = "3爱好2", BetRate = {25,15,15,15,15,15}}
	self.datas[13] = {ID = 13, BetName = "3爱好3", BetRate = {15,15,25,15,15,15}}
	self.datas[14] = {ID = 14, BetName = "3爱好4", BetRate = {15,15,15,25,15,15}}
	self.datas[15] = {ID = 15, BetName = "3爱好5", BetRate = {15,15,15,15,25,15}}
end

HappySupremacy_RobAICFG:init()
