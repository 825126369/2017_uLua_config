M_BaseInfoCFG = {}

function M_BaseInfoCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_BaseInfoCFG:init()
	self.datas = {}
	self.datas["base_gold"] = {Key = "base_gold", Value = 5000}
	self.datas["base_ticket"] = {Key = "base_ticket", Value = 1}
	self.datas["base_chip"] = {Key = "base_chip", Value = 10}
	self.datas["signatureMaxLength"] = {Key = "signatureMaxLength", Value = 80}
	self.datas["giftDepreciation"] = {Key = "giftDepreciation", Value = 100}
	self.datas["friendLimit"] = {Key = "friendLimit", Value = 50}
	self.datas["onlineRewardTimeInterval"] = {Key = "onlineRewardTimeInterval", Value = 30}
	self.datas["onlineRewardGold"] = {Key = "onlineRewardGold", Value = 500}
	self.datas["noticeCdTime"] = {Key = "noticeCdTime", Value = 30}
	self.datas["all_notice_player"] = {Key = "all_notice_player", Value = 50}
	self.datas["worldChatInterval"] = {Key = "worldChatInterval", Value = 5}
	self.datas["almsGoldCount"] = {Key = "almsGoldCount", Value = 2000}
	self.datas["almsLimit"] = {Key = "almsLimit", Value = 2000}
	self.datas["almsMaxCount"] = {Key = "almsMaxCount", Value = 3}
	self.datas["nickNameMaxLength"] = {Key = "nickNameMaxLength", Value = 16}
	self.datas["bindCount"] = {Key = "bindCount", Value = 3}
	self.datas["bindCodeExpiryDate"] = {Key = "bindCodeExpiryDate", Value = 60}
	self.datas["isOpenGuide"] = {Key = "isOpenGuide", Value = 0}
	self.datas["isAutoConnect"] = {Key = "isAutoConnect", Value = 0}
	self.datas["isInsertAnySdk"] = {Key = "isInsertAnySdk", Value = 1}
	self.datas["sendGiftLogMaxCount"] = {Key = "sendGiftLogMaxCount", Value = 50}
	self.datas["sendMailLogMaxCount"] = {Key = "sendMailLogMaxCount", Value = 50}
	self.datas["UpdateIcon"] = {Key = "UpdateIcon", Value = 100}
	self.datas["modifyNicknameCost"] = {Key = "modifyNicknameCost", Value = 100}
	self.datas["costType"] = {Key = "costType", Value = 2}
	self.datas["exchangeMaxCount"] = {Key = "exchangeMaxCount", Value = 50}
	self.datas["updateGameList"] = {Key = "updateGameList", Value = 300}
	self.datas["updateMailPoint"] = {Key = "updateMailPoint", Value = 60}
	self.datas["isOfflineVersion"] = {Key = "isOfflineVersion", Value = 0}
	self.datas["defaultvip"] = {Key = "defaultvip", Value = 0}
	self.datas["firstGameId"] = {Key = "firstGameId", Value = 1}
	self.datas["isApple"] = {Key = "isApple", Value = 0}
	self.datas["lotteryBigPrize"] = {Key = "lotteryBigPrize", Value = 30000}
	self.datas["lotterySmallPrize"] = {Key = "lotterySmallPrize", Value = 500}
	self.datas["ticketLotteryCost"] = {Key = "ticketLotteryCost", Value = 20}
	self.datas["lotteryBoxCount"] = {Key = "lotteryBoxCount", Value = 12}
	self.datas["thankYouJoinExchangeTicket"] = {Key = "thankYouJoinExchangeTicket", Value = 5}
	self.datas["thankYouExchangeLimit"] = {Key = "thankYouExchangeLimit", Value = 20}
	self.datas["tankkYouCountLimit"] = {Key = "tankkYouCountLimit", Value = 999}
	self.datas["continuousVipCount"] = {Key = "continuousVipCount", Value = 1}
	self.datas["continuousSendSpeakerCost"] = {Key = "continuousSendSpeakerCost", Value = 50}
	self.datas["continuousSendSpeakerInterval"] = {Key = "continuousSendSpeakerInterval", Value = 120}
	self.datas["continuousSendTime1"] = {Key = "continuousSendTime1", Value = 10}
	self.datas["continuousSendTime2"] = {Key = "continuousSendTime2", Value = 100}
	self.datas["continuousSendTime3"] = {Key = "continuousSendTime3", Value = 1000}
	self.datas["continuousSpeakerMaxCount"] = {Key = "continuousSpeakerMaxCount", Value = 1000}
	self.datas["ptotectTime"] = {Key = "ptotectTime", Value = 604800}
	self.datas["FreeSpeakerLevel"] = {Key = "FreeSpeakerLevel", Value = 9}
	self.datas["rechargeNumSpeaker"] = {Key = "rechargeNumSpeaker", Value = 30}
	self.datas["silverMember"] = {Key = "silverMember", Value = 100}
	self.datas["goldMember"] = {Key = "goldMember", Value = 1000}
	self.datas["notifyEnterGameVipLevel"] = {Key = "notifyEnterGameVipLevel", Value = 3}
	self.datas["DiceCondition"] = {Key = "DiceCondition", Value = 3000}
	self.datas["MinLifeTime"] = {Key = "MinLifeTime", Value = 1800}
	self.datas["MaxLifeTime"] = {Key = "MaxLifeTime", Value = 7200}
	self.datas["MaxGold"] = {Key = "MaxGold", Value = 20000000}
	self.datas["DiscountVIP"] = {Key = "DiscountVIP", Value = 11}
	self.datas["DiscountValue"] = {Key = "DiscountValue", Value = 100}
	self.datas["StarMax"] = {Key = "StarMax", Value = 50}
	self.datas["AwardMax"] = {Key = "AwardMax", Value = 100000}
	self.datas["BaseChip"] = {Key = "BaseChip", Value = 200}
	self.datas["ChipRate"] = {Key = "ChipRate", Value = 50}
	self.datas["StarCount"] = {Key = "StarCount", Value = 20}
	self.datas["RobotNoticeMinTime"] = {Key = "RobotNoticeMinTime", Value = 10}
	self.datas["RobotNoticeMaxTime"] = {Key = "RobotNoticeMaxTime", Value = 20}
	self.datas["SendGiftLimit"] = {Key = "SendGiftLimit", Value = 200000}
	self.datas["safeBoxLogMaxCount"] = {Key = "safeBoxLogMaxCount", Value = 50}
end

M_BaseInfoCFG:init()
