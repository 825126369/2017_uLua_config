M_CommodityCFG = {}

function M_CommodityCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_CommodityCFG:init()
	self.datas = {}
	self.datas[1] = {CommodityId = 1, Name = "头像框1", CommodityType = 5, PriceType = 1, Price = 0, Item = {50101}, IsCanBuy = true, Count = {1}}
	self.datas[2] = {CommodityId = 2, Name = "头像框2头盔", CommodityType = 5, PriceType = 1, Price = 7000, Item = {50102}, IsCanBuy = true, Count = {1}}
	self.datas[3] = {CommodityId = 3, Name = "头像框3假发", CommodityType = 5, PriceType = 1, Price = 70000, Item = {50103}, IsCanBuy = true, Count = {1}}
	self.datas[4] = {CommodityId = 4, Name = "头像框4鳄鱼", CommodityType = 5, PriceType = 1, Price = 12800, Item = {50104}, IsCanBuy = true, Count = {1}}
	self.datas[5] = {CommodityId = 5, Name = "头像框5海盗", CommodityType = 5, PriceType = 1, Price = 128000, Item = {50105}, IsCanBuy = true, Count = {1}}
	self.datas[6] = {CommodityId = 6, Name = "头像框6墨镜", CommodityType = 5, PriceType = 1, Price = 500000, Item = {50106}, IsCanBuy = true, Count = {1}}
	self.datas[7] = {CommodityId = 7, Name = "头像框7王冠", CommodityType = 5, PriceType = 1, Price = 500000, Item = {50107}, IsCanBuy = true, Count = {1}}
	self.datas[8] = {CommodityId = 8, Name = "头像框8骰子", CommodityType = 5, PriceType = 1, Price = 50000, Item = {50108}, IsCanBuy = true, Count = {1}}
	self.datas[9] = {CommodityId = 9, Name = "头像框9猫耳", CommodityType = 5, PriceType = 1, Price = 1000000, Item = {50109}, IsCanBuy = true, Count = {1}}
	self.datas[10] = {CommodityId = 10, Name = "头像框10牛仔", CommodityType = 5, PriceType = 1, Price = 100000, Item = {50110}, IsCanBuy = true, Count = {1}}
	self.datas[11] = {CommodityId = 11, Name = "美钞", CommodityType = 3, PriceType = 1, Price = 300, Item = {30101}, IsCanBuy = true, Count = {1}}
	self.datas[12] = {CommodityId = 12, Name = "金条", CommodityType = 3, PriceType = 1, Price = 1000, Item = {30102}, IsCanBuy = true, Count = {1}}
	self.datas[13] = {CommodityId = 13, Name = "摇钱树", CommodityType = 3, PriceType = 1, Price = 30000, Item = {30103}, IsCanBuy = true, Count = {1}}
	self.datas[14] = {CommodityId = 14, Name = "跑车", CommodityType = 3, PriceType = 1, Price = 100000, Item = {30104}, IsCanBuy = true, Count = {1}}
	self.datas[15] = {CommodityId = 15, Name = "游艇", CommodityType = 3, PriceType = 1, Price = 3000000, Item = {30105}, IsCanBuy = true, Count = {1}}
	self.datas[16] = {CommodityId = 16, Name = "飞机", CommodityType = 3, PriceType = 1, Price = 10000000, Item = {30106}, IsCanBuy = true, Count = {1}}
	self.datas[17] = {CommodityId = 17, Name = "头像框福", CommodityType = 5, PriceType = 2, Price = 9999999, Item = {50111}, IsCanBuy = false, Count = {1}}
	self.datas[18] = {CommodityId = 18, Name = "头像框禄", CommodityType = 5, PriceType = 2, Price = 9999999, Item = {50112}, IsCanBuy = false, Count = {1}}
	self.datas[19] = {CommodityId = 19, Name = "头像框寿", CommodityType = 5, PriceType = 2, Price = 9999999, Item = {50113}, IsCanBuy = false, Count = {1}}
	self.datas[20] = {CommodityId = 20, Name = "头像框喜", CommodityType = 5, PriceType = 2, Price = 9999999, Item = {50114}, IsCanBuy = false, Count = {1}}
	self.datas[21] = {CommodityId = 21, Name = "首充头像框", CommodityType = 5, PriceType = 2, Price = 9999999, Item = {50115}, IsCanBuy = true, Count = {1}}
end

M_CommodityCFG:init()
