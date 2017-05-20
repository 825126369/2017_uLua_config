HappySupremacy_BaseCFG = {}

function HappySupremacy_BaseCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function HappySupremacy_BaseCFG:init()
	self.datas = {}
	self.datas["PlayerMaxCount"] = {Key = "PlayerMaxCount", Value = 10000}
	self.datas["BetTime"] = {Key = "BetTime", Value = 20}
	self.datas["Odds_0"] = {Key = "Odds_0", Value = 800}
	self.datas["Odds_1"] = {Key = "Odds_1", Value = 100}
	self.datas["Odds_2"] = {Key = "Odds_2", Value = 1100}
	self.datas["Odds_3"] = {Key = "Odds_3", Value = 1100}
	self.datas["Odds_4"] = {Key = "Odds_4", Value = 95}
	self.datas["Odds_5"] = {Key = "Odds_5", Value = 95}
	self.datas["MinBankerCount"] = {Key = "MinBankerCount", Value = 0}
	self.datas["HistoryMaxCount"] = {Key = "HistoryMaxCount", Value = 66}
	self.datas["DefendRate"] = {Key = "DefendRate", Value = -15}
	self.datas["MaxRate"] = {Key = "MaxRate", Value = 20}
	self.datas["IsOpenAdjust"] = {Key = "IsOpenAdjust", Value = 0}
	self.datas["IsOpenGM"] = {Key = "IsOpenGM", Value = 0}
	self.datas["ShuffleLimit"] = {Key = "ShuffleLimit", Value = 9}
	self.datas["BetLimitRate"] = {Key = "BetLimitRate", Value = 8}
	self.datas["SystemDrawWater"] = {Key = "SystemDrawWater", Value = 0}
	self.datas["IsOpenRob"] = {Key = "IsOpenRob", Value = 1}
	self.datas["PlayerMinCount"] = {Key = "PlayerMinCount", Value = 30}
	self.datas["RobMinCount"] = {Key = "RobMinCount", Value = 30}
	self.datas["RobMaxCount"] = {Key = "RobMaxCount", Value = 30}
	self.datas["RobEnterMinTime"] = {Key = "RobEnterMinTime", Value = 5}
	self.datas["RobEnterMaxTime"] = {Key = "RobEnterMaxTime", Value = 15}
	self.datas["RobAskBankerMin"] = {Key = "RobAskBankerMin", Value = 2}
	self.datas["RobAskBankerMax"] = {Key = "RobAskBankerMax", Value = 10}
	self.datas["WinStarCount"] = {Key = "WinStarCount", Value = 0}
	self.datas["AwardGetRate"] = {Key = "AwardGetRate", Value = 100}
	self.datas["RobBetMin"] = {Key = "RobBetMin", Value = 10000}
	self.datas["RobBetMax"] = {Key = "RobBetMax", Value = 20000}
end

HappySupremacy_BaseCFG:init()
