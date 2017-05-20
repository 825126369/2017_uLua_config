M_ItemCFG = {}

function M_ItemCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_ItemCFG:init()
	self.datas = {}
	self.datas[1] = {ItemId = 1, ItemName = "金币", ItemDesc = "", Icon = "Common2/M_Gold_Icon.png", ItemCategory = 1, ItemValue = 0}
	self.datas[2] = {ItemId = 2, ItemName = "礼券", ItemDesc = "", Icon = "Common2/M_TicketIcon.png", ItemCategory = 2, ItemValue = 0}
	self.datas[11] = {ItemId = 11, ItemName = "碎片", ItemDesc = "", Icon = "Common3/M_TicketIcon.png", ItemCategory = 11, ItemValue = 0}
	self.datas[100] = {ItemId = 100, ItemName = "vip体验卡", ItemDesc = "", Icon = "", ItemCategory = 100, ItemValue = nil}
	self.datas[40101] = {ItemId = 40101, ItemName = "50元话费", ItemDesc = "", Icon = "Common2/M_ExChange_50.png", ItemCategory = 4, ItemValue = nil}
	self.datas[40102] = {ItemId = 40102, ItemName = "100元话费", ItemDesc = "", Icon = "Common2/M_ExChange_100.png", ItemCategory = 4, ItemValue = nil}
	self.datas[40103] = {ItemId = 40103, ItemName = "华为手机", ItemDesc = "", Icon = "Common2/M_ExChange_roogyao7.png", ItemCategory = 4, ItemValue = nil}
	self.datas[40104] = {ItemId = 40104, ItemName = "苹果表", ItemDesc = "", Icon = "Common2/M_ExChange_AppleWatch.png", ItemCategory = 4, ItemValue = nil}
	self.datas[40105] = {ItemId = 40105, ItemName = "IPAD", ItemDesc = "", Icon = "Common2/M_ExChange_IPAD.png", ItemCategory = 4, ItemValue = nil}
	self.datas[40106] = {ItemId = 40106, ItemName = "IPHONE6", ItemDesc = "", Icon = "Common2/M_ExChange_IPHONE6.png", ItemCategory = 4, ItemValue = nil}
	self.datas[40107] = {ItemId = 40107, ItemName = "IPHONE6P", ItemDesc = "", Icon = "Common2/M_ExChange_IPHONE6P.png", ItemCategory = 4, ItemValue = nil}
	self.datas[40108] = {ItemId = 40108, ItemName = "30元话费", ItemDesc = "", Icon = "Common2/M_ExChange_30.png", ItemCategory = 4, ItemValue = nil}
	self.datas[10101] = {ItemId = 10101, ItemName = "6000金币", ItemDesc = "", Icon = "", ItemCategory = 1, ItemValue = nil}
	self.datas[10102] = {ItemId = 10102, ItemName = "12000金币", ItemDesc = "", Icon = "", ItemCategory = 1, ItemValue = nil}
	self.datas[10103] = {ItemId = 10103, ItemName = "31500金币", ItemDesc = "", Icon = "", ItemCategory = 1, ItemValue = nil}
	self.datas[10104] = {ItemId = 10104, ItemName = "55000金币", ItemDesc = "", Icon = "", ItemCategory = 1, ItemValue = nil}
	self.datas[10105] = {ItemId = 10105, ItemName = "115000金币", ItemDesc = "", Icon = "", ItemCategory = 1, ItemValue = nil}
	self.datas[10106] = {ItemId = 10106, ItemName = "240000金币", ItemDesc = "", Icon = "", ItemCategory = 1, ItemValue = nil}
	self.datas[20101] = {ItemId = 20101, ItemName = "5礼券", ItemDesc = "", Icon = "", ItemCategory = 2, ItemValue = nil}
	self.datas[20102] = {ItemId = 20102, ItemName = "10礼券", ItemDesc = "", Icon = "", ItemCategory = 2, ItemValue = nil}
	self.datas[20103] = {ItemId = 20103, ItemName = "15礼券", ItemDesc = "", Icon = "", ItemCategory = 2, ItemValue = nil}
	self.datas[20104] = {ItemId = 20104, ItemName = "250礼券", ItemDesc = "", Icon = "", ItemCategory = 2, ItemValue = nil}
	self.datas[20105] = {ItemId = 20105, ItemName = "500礼券", ItemDesc = "", Icon = "", ItemCategory = 2, ItemValue = nil}
	self.datas[20106] = {ItemId = 20106, ItemName = "1000礼券", ItemDesc = "", Icon = "", ItemCategory = 2, ItemValue = nil}
	self.datas[20107] = {ItemId = 20107, ItemName = "1200礼券", ItemDesc = "", Icon = "", ItemCategory = 2, ItemValue = nil}
	self.datas[20108] = {ItemId = 20108, ItemName = "2500礼券", ItemDesc = "", Icon = "", ItemCategory = 2, ItemValue = nil}
	self.datas[20109] = {ItemId = 20109, ItemName = "3000礼券", ItemDesc = "", Icon = "", ItemCategory = 2, ItemValue = nil}
	self.datas[30101] = {ItemId = 30101, ItemName = "美钞", ItemDesc = "", Icon = "Common2/M_Icon_Gift_1.png", ItemCategory = 3, ItemValue = nil}
	self.datas[30102] = {ItemId = 30102, ItemName = "金条", ItemDesc = "", Icon = "Common2/M_Icon_Gift_2.png", ItemCategory = 3, ItemValue = nil}
	self.datas[30103] = {ItemId = 30103, ItemName = "摇钱树", ItemDesc = "", Icon = "Common2/M_Icon_Gift_3.png", ItemCategory = 3, ItemValue = nil}
	self.datas[30104] = {ItemId = 30104, ItemName = "跑车", ItemDesc = "", Icon = "Common2/M_Icon_Gift_4.png", ItemCategory = 3, ItemValue = nil}
	self.datas[30105] = {ItemId = 30105, ItemName = "游艇", ItemDesc = "", Icon = "Common2/M_Icon_Gift_5.png", ItemCategory = 3, ItemValue = nil}
	self.datas[30106] = {ItemId = 30106, ItemName = "飞机", ItemDesc = "", Icon = "Common2/M_Icon_Gift_6.png", ItemCategory = 3, ItemValue = nil}
	self.datas[30107] = {ItemId = 30107, ItemName = "金币", ItemDesc = "", Icon = "Common2/M_Gold_Icon.png", ItemCategory = 3, ItemValue = nil}
	self.datas[50101] = {ItemId = 50101, ItemName = "头像框1", ItemDesc = "", Icon = "Common2/M_DefaultHeadFrame.png", ItemCategory = 5, ItemValue = nil}
	self.datas[50102] = {ItemId = 50102, ItemName = "头像框2", ItemDesc = "", Icon = "Common2/M_HeadFrame1.png", ItemCategory = 5, ItemValue = nil}
	self.datas[50103] = {ItemId = 50103, ItemName = "头像框3", ItemDesc = "", Icon = "Common2/M_HeadFrame2.png", ItemCategory = 5, ItemValue = nil}
	self.datas[50104] = {ItemId = 50104, ItemName = "头像框4", ItemDesc = "", Icon = "Common2/M_HeadFrame3.png", ItemCategory = 5, ItemValue = nil}
	self.datas[50105] = {ItemId = 50105, ItemName = "头像框5", ItemDesc = "", Icon = "Common2/M_HeadFrame4.png", ItemCategory = 5, ItemValue = nil}
	self.datas[50106] = {ItemId = 50106, ItemName = "头像框6", ItemDesc = "", Icon = "Common2/M_HeadFrame5.png", ItemCategory = 5, ItemValue = nil}
	self.datas[50107] = {ItemId = 50107, ItemName = "头像框7", ItemDesc = "", Icon = "Common2/M_HeadFrame6.png", ItemCategory = 5, ItemValue = nil}
	self.datas[50108] = {ItemId = 50108, ItemName = "头像框8", ItemDesc = "", Icon = "Common2/M_HeadFrame7.png", ItemCategory = 5, ItemValue = nil}
	self.datas[50109] = {ItemId = 50109, ItemName = "头像框9", ItemDesc = "", Icon = "Common2/M_HeadFrame8.png", ItemCategory = 5, ItemValue = nil}
	self.datas[50110] = {ItemId = 50110, ItemName = "头像框10", ItemDesc = "", Icon = "Common2/M_HeadFrame9.png", ItemCategory = 5, ItemValue = nil}
	self.datas[50111] = {ItemId = 50111, ItemName = "春节头像框福", ItemDesc = "", Icon = "Common2/M_HeadFrame_fu.png", ItemCategory = 5, ItemValue = nil}
	self.datas[50112] = {ItemId = 50112, ItemName = "春节头像框禄", ItemDesc = "", Icon = "Common2/M_HeadFrame_lu.png", ItemCategory = 5, ItemValue = nil}
	self.datas[50113] = {ItemId = 50113, ItemName = "春节头像框寿", ItemDesc = "", Icon = "Common2/M_HeadFrame_shou.png", ItemCategory = 5, ItemValue = nil}
	self.datas[50114] = {ItemId = 50114, ItemName = "春节头像框喜", ItemDesc = "", Icon = "Common2/M_HeadFrame_xi.png", ItemCategory = 5, ItemValue = nil}
	self.datas[50115] = {ItemId = 50115, ItemName = "首充头像框", ItemDesc = "", Icon = "Common2/M_HeadFrameFirst.png", ItemCategory = 5, ItemValue = nil}
end

M_ItemCFG:init()
