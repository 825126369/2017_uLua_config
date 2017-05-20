M_DialLotteryCFG = {}

function M_DialLotteryCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_DialLotteryCFG:init()
	self.datas = {}
	self.datas[1] = {ID = 1, RewardCoin = 500, RewardType = 1, Scale = 0.65, Icon = "Common2/M_ShopIcon_1.png", Probability = 20}
	self.datas[2] = {ID = 2, RewardCoin = 15, RewardType = 2, Scale = 0.8, Icon = "Common2/M_TicketIcon_3.png", Probability = 1}
	self.datas[3] = {ID = 3, RewardCoin = 1000, RewardType = 1, Scale = 0.65, Icon = "Common2/M_ShopIcon_2.png", Probability = 30}
	self.datas[4] = {ID = 4, RewardCoin = 2, RewardType = 2, Scale = 0.8, Icon = "Common2/M_TicketIcon_2.png", Probability = 4}
	self.datas[5] = {ID = 5, RewardCoin = 1500, RewardType = 1, Scale = 0.65, Icon = "Common2/M_ShopIcon_3.png", Probability = 20}
	self.datas[6] = {ID = 6, RewardCoin = 800, RewardType = 1, Scale = 0.65, Icon = "Common2/M_ShopIcon_3.png", Probability = 10}
	self.datas[7] = {ID = 7, RewardCoin = 2000, RewardType = 1, Scale = 0.65, Icon = "Common2/M_ShopIcon_4.png", Probability = 14}
	self.datas[8] = {ID = 8, RewardCoin = 5000, RewardType = 1, Scale = 0.65, Icon = "Common2/M_ShopIcon_4.png", Probability = 6}
end

M_DialLotteryCFG:init()
