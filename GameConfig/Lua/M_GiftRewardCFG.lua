M_GiftRewardCFG = {}

function M_GiftRewardCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_GiftRewardCFG:init()
	self.datas = {}
	self.datas[1] = {RewardType = 1, ItemId = {1}, ItemCount = {20000}}
	self.datas[2] = {RewardType = 2, ItemId = {1,2}, ItemCount = {50000,100}}
end

M_GiftRewardCFG:init()
