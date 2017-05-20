M_VIPProfitCFG = {}

function M_VIPProfitCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_VIPProfitCFG:init()
	self.datas = {}
	self.datas[0] = {VipLv = 0, VipExp = 6, OnlineReward = 0, MaxGiftslimit = 0, GiftUnlock = {}, RoomUnlock = {}, FishItemUnlock = {}, VipName = 0, GiveTicket = 0, DailyLottery = 1}
	self.datas[1] = {VipLv = 1, VipExp = 30, OnlineReward = 0, MaxGiftslimit = 99999999999, GiftUnlock = {}, RoomUnlock = {}, FishItemUnlock = {}, VipName = 1, GiveTicket = 0, DailyLottery = 2}
	self.datas[2] = {VipLv = 2, VipExp = 100, OnlineReward = 0, MaxGiftslimit = 99999999999, GiftUnlock = {}, RoomUnlock = {}, FishItemUnlock = {}, VipName = 2, GiveTicket = 0, DailyLottery = 2}
	self.datas[3] = {VipLv = 3, VipExp = 300, OnlineReward = 0, MaxGiftslimit = 99999999999, GiftUnlock = {}, RoomUnlock = {}, FishItemUnlock = {}, VipName = 3, GiveTicket = 0, DailyLottery = 2}
	self.datas[4] = {VipLv = 4, VipExp = 1000, OnlineReward = 0, MaxGiftslimit = 99999999999, GiftUnlock = {}, RoomUnlock = {}, FishItemUnlock = {}, VipName = 4, GiveTicket = 0, DailyLottery = 3}
	self.datas[5] = {VipLv = 5, VipExp = 3000, OnlineReward = 0, MaxGiftslimit = 99999999999, GiftUnlock = {}, RoomUnlock = {}, FishItemUnlock = {}, VipName = 5, GiveTicket = 0, DailyLottery = 3}
	self.datas[6] = {VipLv = 6, VipExp = 10000, OnlineReward = 0, MaxGiftslimit = 99999999999, GiftUnlock = {}, RoomUnlock = {}, FishItemUnlock = {}, VipName = 6, GiveTicket = 0, DailyLottery = 3}
	self.datas[7] = {VipLv = 7, VipExp = 30000, OnlineReward = 0, MaxGiftslimit = 99999999999, GiftUnlock = {}, RoomUnlock = {}, FishItemUnlock = {}, VipName = 7, GiveTicket = 0, DailyLottery = 4}
	self.datas[8] = {VipLv = 8, VipExp = 100000, OnlineReward = 0, MaxGiftslimit = 99999999999, GiftUnlock = {}, RoomUnlock = {}, FishItemUnlock = {}, VipName = 8, GiveTicket = 0, DailyLottery = 4}
	self.datas[9] = {VipLv = 9, VipExp = 300000, OnlineReward = 0, MaxGiftslimit = 99999999999, GiftUnlock = {}, RoomUnlock = {}, FishItemUnlock = {}, VipName = 9, GiveTicket = 0, DailyLottery = 4}
	self.datas[10] = {VipLv = 10, VipExp = 0, OnlineReward = 0, MaxGiftslimit = 99999999999, GiftUnlock = {}, RoomUnlock = {}, FishItemUnlock = {}, VipName = 10, GiveTicket = 0, DailyLottery = 5}
	self.datas[99] = {VipLv = 99, VipExp = 0, OnlineReward = 0, MaxGiftslimit = 0, GiftUnlock = {}, RoomUnlock = {}, FishItemUnlock = {}, VipName = 0, GiveTicket = 0, DailyLottery = 1}
end

M_VIPProfitCFG:init()
