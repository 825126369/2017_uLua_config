M_ChipCFG = {}

function M_ChipCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_ChipCFG:init()
	self.datas = {}
	self.datas[1] = {ID = 1, Count = 100, Icon = "Common2/M_Chip_1.png", IsCheck = false}
	self.datas[2] = {ID = 2, Count = 150, Icon = "Common2/M_Chip_2.png", IsCheck = false}
	self.datas[3] = {ID = 3, Count = 200, Icon = "Common2/M_Chip_3.png", IsCheck = false}
	self.datas[4] = {ID = 4, Count = 500, Icon = "Common2/M_Chip_4.png", IsCheck = false}
	self.datas[5] = {ID = 5, Count = 1000, Icon = "Common2/M_Chip_5.png", IsCheck = false}
	self.datas[6] = {ID = 6, Count = 1500, Icon = "Common2/M_Chip_6.png", IsCheck = false}
	self.datas[7] = {ID = 7, Count = 2000, Icon = "Common2/M_Chip_7.png", IsCheck = false}
	self.datas[8] = {ID = 8, Count = 5000, Icon = "Common2/M_Chip_8.png", IsCheck = false}
	self.datas[9] = {ID = 9, Count = 10000, Icon = "Common2/M_Chip_9.png", IsCheck = false}
	self.datas[10] = {ID = 10, Count = 15000, Icon = "Common2/M_Chip_10.png", IsCheck = false}
	self.datas[11] = {ID = 11, Count = 20000, Icon = "Common2/M_Chip_11.png", IsCheck = false}
	self.datas[12] = {ID = 12, Count = 50000, Icon = "Common2/M_Chip_12.png", IsCheck = false}
	self.datas[13] = {ID = 13, Count = 100000, Icon = "Common2/M_Chip_13.png", IsCheck = false}
	self.datas[14] = {ID = 14, Count = 150000, Icon = "Common2/M_Chip_14.png", IsCheck = false}
	self.datas[15] = {ID = 15, Count = 200000, Icon = "Common2/M_Chip_15.png", IsCheck = false}
end

M_ChipCFG:init()
