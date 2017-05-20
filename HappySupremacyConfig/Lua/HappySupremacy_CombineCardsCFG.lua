HappySupremacy_CombineCardsCFG = {}

function HappySupremacy_CombineCardsCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function HappySupremacy_CombineCardsCFG:init()
	self.datas = {}
	self.datas[1] = {CombineCardID = 1, CombineCardsName = "至尊宝"}
	self.datas[2] = {CombineCardID = 2, CombineCardsName = "双天"}
	self.datas[3] = {CombineCardID = 3, CombineCardsName = "双地"}
	self.datas[4] = {CombineCardID = 4, CombineCardsName = "双人"}
	self.datas[5] = {CombineCardID = 5, CombineCardsName = "双和"}
	self.datas[6] = {CombineCardID = 6, CombineCardsName = "双梅"}
	self.datas[7] = {CombineCardID = 7, CombineCardsName = "双长"}
	self.datas[8] = {CombineCardID = 8, CombineCardsName = "双板凳"}
	self.datas[9] = {CombineCardID = 9, CombineCardsName = "双斧头"}
	self.datas[10] = {CombineCardID = 10, CombineCardsName = "双红头"}
	self.datas[11] = {CombineCardID = 11, CombineCardsName = "双铜棰"}
	self.datas[12] = {CombineCardID = 12, CombineCardsName = "双幺五"}
	self.datas[13] = {CombineCardID = 13, CombineCardsName = "杂九"}
	self.datas[14] = {CombineCardID = 14, CombineCardsName = "杂八"}
	self.datas[15] = {CombineCardID = 15, CombineCardsName = "杂七"}
	self.datas[16] = {CombineCardID = 16, CombineCardsName = "杂五"}
	self.datas[17] = {CombineCardID = 17, CombineCardsName = "天九王"}
	self.datas[18] = {CombineCardID = 18, CombineCardsName = "天槓"}
	self.datas[19] = {CombineCardID = 19, CombineCardsName = "地槓"}
end

HappySupremacy_CombineCardsCFG:init()
