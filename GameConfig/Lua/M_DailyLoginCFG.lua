M_DailyLoginCFG = {}

function M_DailyLoginCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_DailyLoginCFG:init()
	self.datas = {}
	self.datas[1] = {ID = 1, Name = "500金币", Tpye = 1, Count = 500, Icon = "Common2/M_ShopIcon_2.png"}
	self.datas[2] = {ID = 2, Name = "800金币", Tpye = 1, Count = 800, Icon = "Common2/M_ShopIcon_3.png"}
	self.datas[3] = {ID = 3, Name = "VIP体验3天", Tpye = 100, Count = 3, Icon = "Common2/M_DailyIcon_3.png"}
	self.datas[4] = {ID = 4, Name = "900金币", Tpye = 1, Count = 900, Icon = "Common2/M_ShopIcon_4.png"}
	self.datas[5] = {ID = 5, Name = "1000金币", Tpye = 1, Count = 1000, Icon = "Common2/M_ShopIcon_4.png"}
	self.datas[6] = {ID = 6, Name = "1100金币", Tpye = 1, Count = 1100, Icon = "Common2/M_ShopIcon_4.png"}
	self.datas[7] = {ID = 7, Name = "幸运大转盘", Tpye = 99, Count = 0, Icon = "Common2/M_DailyIcon_7.png"}
end

M_DailyLoginCFG:init()
