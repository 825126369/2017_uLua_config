HappySupremacy_RoomStockCFG = {}

function HappySupremacy_RoomStockCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function HappySupremacy_RoomStockCFG:init()
	self.datas = {}
	self.datas[1] = {RoomID = 1, Deduct = 0.01, DefaultStock = 100000, Stock = {0,100000,200000,300000,500000,700000,1000000,5000000,10000000,20000000}, ScoreId = {5,20,30,40,50,60,70,80,90,95}}
	self.datas[2] = {RoomID = 2, Deduct = 0.01, DefaultStock = 1000000, Stock = {0,500000,700000,900000,2000000,5000000,8000000,10000000,30000000,50000000}, ScoreId = {5,20,30,40,50,60,70,80,90,95}}
	self.datas[3] = {RoomID = 3, Deduct = 0.01, DefaultStock = 1500000, Stock = {0,1000000,3000000,6000000,9000000,15000000,30000000,50000000,70000000,100000000}, ScoreId = {5,20,30,40,50,60,70,80,90,95}}
end

HappySupremacy_RoomStockCFG:init()
