M_ExchangeCFG = {}

function M_ExchangeCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_ExchangeCFG:init()
	self.datas = {}
	self.datas[1] = {ChangeId = 1, CostTicket = 300, ItemId = 40108, Vip = 0, ItemIcon = "Common2/M_ExChange_30.png", ItemName = "Common2/M_ExChangeItemName30.png", ItemCount = 1}
	self.datas[2] = {ChangeId = 2, CostTicket = 100, ItemId = 2, Vip = 0, ItemIcon = "Common2/M_TicketIcon_2.png", ItemName = "Common2/M_ExChangeItemName2.png", ItemCount = 8}
	self.datas[3] = {ChangeId = 3, CostTicket = 200, ItemId = 1, Vip = 0, ItemIcon = "Common2/M_ShopIcon_6.png", ItemName = "Common2/M_ExChangeItemName3.png", ItemCount = 180000}
end

M_ExchangeCFG:init()
