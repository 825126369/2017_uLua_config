M_StarLotteryCFG = {}

function M_StarLotteryCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_StarLotteryCFG:init()
	self.datas = {}
	self.datas[1] = {Index = 1, StarLvl = 1, ItemType = 1, ItemCount = 200, Rate1 = 10000, Rate2 = 10000, Rate3 = 10000, Rate4 = 10000}
	self.datas[2] = {Index = 2, StarLvl = 1, ItemType = 1, ItemCount = 2000, Rate1 = 3850, Rate2 = 2775, Rate3 = 2517, Rate4 = 2280}
	self.datas[3] = {Index = 3, StarLvl = 1, ItemType = 2, ItemCount = 2, Rate1 = 2350, Rate2 = 1375, Rate3 = 1217, Rate4 = 1080}
	self.datas[4] = {Index = 4, StarLvl = 1, ItemType = 2, ItemCount = 5, Rate1 = 1550, Rate2 = 625, Rate3 = 517, Rate4 = 430}
	self.datas[5] = {Index = 5, StarLvl = 1, ItemType = 11, ItemCount = 1, Rate1 = 1000, Rate2 = 125, Rate3 = 67, Rate4 = 30}
	self.datas[6] = {Index = 6, StarLvl = 2, ItemType = 1, ItemCount = 1000, Rate1 = 10000, Rate2 = 10000, Rate3 = 10000, Rate4 = 10000}
	self.datas[7] = {Index = 7, StarLvl = 2, ItemType = 1, ItemCount = 10000, Rate1 = 2851, Rate2 = 2401, Rate3 = 2101, Rate4 = 1821}
	self.datas[8] = {Index = 8, StarLvl = 2, ItemType = 2, ItemCount = 10, Rate1 = 851, Rate2 = 501, Rate3 = 301, Rate4 = 121}
	self.datas[9] = {Index = 9, StarLvl = 2, ItemType = 2, ItemCount = 50, Rate1 = 451, Rate2 = 201, Rate3 = 101, Rate4 = 21}
	self.datas[10] = {Index = 10, StarLvl = 2, ItemType = 11, ItemCount = 3, Rate1 = 300, Rate2 = 100, Rate3 = 50, Rate4 = 20}
	self.datas[11] = {Index = 11, StarLvl = 3, ItemType = 1, ItemCount = 5000, Rate1 = 10000, Rate2 = 10000, Rate3 = 10000, Rate4 = 10000}
	self.datas[12] = {Index = 12, StarLvl = 3, ItemType = 1, ItemCount = 50000, Rate1 = 1550, Rate2 = 1280, Rate3 = 990, Rate4 = 710}
	self.datas[13] = {Index = 13, StarLvl = 3, ItemType = 2, ItemCount = 20, Rate1 = 750, Rate2 = 580, Rate3 = 390, Rate4 = 210}
	self.datas[14] = {Index = 14, StarLvl = 3, ItemType = 2, ItemCount = 150, Rate1 = 300, Rate2 = 230, Rate3 = 140, Rate4 = 60}
	self.datas[15] = {Index = 15, StarLvl = 3, ItemType = 11, ItemCount = 10, Rate1 = 100, Rate2 = 80, Rate3 = 40, Rate4 = 10}
	self.datas[16] = {Index = 16, StarLvl = 4, ItemType = 1, ItemCount = 10000, Rate1 = 10000, Rate2 = 10000, Rate3 = 10000, Rate4 = 10000}
	self.datas[17] = {Index = 17, StarLvl = 4, ItemType = 1, ItemCount = 100000, Rate1 = 2870, Rate2 = 3265, Rate3 = 3100, Rate4 = 2955}
	self.datas[18] = {Index = 18, StarLvl = 4, ItemType = 2, ItemCount = 50, Rate1 = 870, Rate2 = 765, Rate3 = 600, Rate4 = 455}
	self.datas[19] = {Index = 19, StarLvl = 4, ItemType = 2, ItemCount = 300, Rate1 = 370, Rate2 = 340, Rate3 = 250, Rate4 = 180}
	self.datas[20] = {Index = 20, StarLvl = 4, ItemType = 11, ItemCount = 20, Rate1 = 50, Rate2 = 70, Rate3 = 30, Rate4 = 10}
	self.datas[21] = {Index = 21, StarLvl = 5, ItemType = 1, ItemCount = 80000, Rate1 = 10000, Rate2 = 10000, Rate3 = 10000, Rate4 = 10000}
	self.datas[22] = {Index = 22, StarLvl = 5, ItemType = 1, ItemCount = 500000, Rate1 = 2125, Rate2 = 2420, Rate3 = 2220, Rate4 = 2020}
	self.datas[23] = {Index = 23, StarLvl = 5, ItemType = 2, ItemCount = 100, Rate1 = 1125, Rate2 = 920, Rate3 = 720, Rate4 = 520}
	self.datas[24] = {Index = 24, StarLvl = 5, ItemType = 2, ItemCount = 500, Rate1 = 525, Rate2 = 420, Rate3 = 320, Rate4 = 220}
	self.datas[25] = {Index = 25, StarLvl = 5, ItemType = 11, ItemCount = 50, Rate1 = 25, Rate2 = 20, Rate3 = 20, Rate4 = 20}
end

M_StarLotteryCFG:init()
