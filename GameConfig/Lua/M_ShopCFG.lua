M_ShopCFG = {}

function M_ShopCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_ShopCFG:init()
	self.datas = {}
	self.datas[1] = {ID = 1, Name = "月卡", Desc = "超值特惠！达人必备！", NameIcon = "Common2/M_ShopName4.png", Icon = "Common2/M_ShopIcon_0.png", Type = 2, Price = 30, Gold = 300000, Index = 1, ShopType = 1}
	self.datas[11] = {ID = 11, Name = "3280000金币", Desc = "", NameIcon = "Common2/M_ShopName1.png", Icon = "Common2/M_ShopIcon_7.png", Type = 1, Price = 328, Gold = 4920000, Index = 11, ShopType = 1}
	self.datas[12] = {ID = 12, Name = "1980000金币", Desc = "", NameIcon = "Common2/M_ShopName1.png", Icon = "Common2/M_ShopIcon_6.png", Type = 1, Price = 198, Gold = 2970000, Index = 12, ShopType = 1}
	self.datas[13] = {ID = 13, Name = "980000金币", Desc = "", NameIcon = "Common2/M_ShopName1.png", Icon = "Common2/M_ShopIcon_5.png", Type = 1, Price = 98, Gold = 1470000, Index = 13, ShopType = 1}
	self.datas[14] = {ID = 14, Name = "500000金币", Desc = "", NameIcon = "Common2/M_ShopName1.png", Icon = "Common2/M_ShopIcon_4.png", Type = 1, Price = 50, Gold = 750000, Index = 14, ShopType = 1}
	self.datas[15] = {ID = 15, Name = "300000金币", Desc = "", NameIcon = "Common2/M_ShopName1.png", Icon = "Common2/M_ShopIcon_3.png", Type = 1, Price = 30, Gold = 450000, Index = 15, ShopType = 1}
	self.datas[16] = {ID = 16, Name = "120000金币", Desc = "", NameIcon = "Common2/M_ShopName1.png", Icon = "Common2/M_ShopIcon_2.png", Type = 1, Price = 12, Gold = 180000, Index = 16, ShopType = 1}
	self.datas[17] = {ID = 17, Name = "60000金币", Desc = "", NameIcon = "Common2/M_ShopName1.png", Icon = "Common2/M_ShopIcon_1.png", Type = 1, Price = 6, Gold = 90000, Index = 17, ShopType = 1}
end

M_ShopCFG:init()
