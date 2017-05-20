M_GiftCFG = {}

function M_GiftCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_GiftCFG:init()
	self.datas = {}
	self.datas[30101] = {GiftId = 30101, Coin = 200000, isShow = 1, Percent = 0.01, Vip = 2, Action = "meijin", TextIcon = "Common2/M_text_Gift_1.png"}
	self.datas[30102] = {GiftId = 30102, Coin = 2000000, isShow = 1, Percent = 0.01, Vip = 3, Action = "jintiao", TextIcon = "Common2/M_text_Gift_2.png"}
	self.datas[30103] = {GiftId = 30103, Coin = 10000000, isShow = 1, Percent = 0.01, Vip = 4, Action = "yaoqianshu", TextIcon = "Common2/M_text_Gift_3.png"}
	self.datas[30104] = {GiftId = 30104, Coin = 30000000, isShow = 1, Percent = 0.01, Vip = 5, Action = "paoche", TextIcon = "Common2/M_text_Gift_4.png"}
	self.datas[30105] = {GiftId = 30105, Coin = 100000000, isShow = 1, Percent = 0.01, Vip = 6, Action = "youting", TextIcon = "Common2/M_text_Gift_5.png"}
	self.datas[30106] = {GiftId = 30106, Coin = 300000000, isShow = 1, Percent = 0.01, Vip = 7, Action = "feiji", TextIcon = "Common2/M_text_Gift_6.png"}
	self.datas[30107] = {GiftId = 30107, Coin = 1, isShow = 0, Percent = 0.01, Vip = 0, Action = "", TextIcon = ""}
end

M_GiftCFG:init()
