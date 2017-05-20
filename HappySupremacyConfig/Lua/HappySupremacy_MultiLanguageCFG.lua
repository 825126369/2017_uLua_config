HappySupremacy_MultiLanguageCFG = {}

function HappySupremacy_MultiLanguageCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function HappySupremacy_MultiLanguageCFG:init()
	self.datas = {}
	self.datas["GoldNotEnough"] = {ID = "GoldNotEnough", Name = "金币不足"}
	self.datas["BetFull"] = {ID = "BetFull", Name = "押注已满"}
	self.datas["VIPNotEnough"] = {ID = "VIPNotEnough", Name = "VIP等级不足"}
	self.datas["RoomFull"] = {ID = "RoomFull", Name = "房间已满"}
	self.datas["WaitText"] = {ID = "WaitText", Name = "正在奖励结算，请稍候…"}
	self.datas["SystemBanker"] = {ID = "SystemBanker", Name = "系统小庄"}
	self.datas["BankerContinueCount"] = {ID = "BankerContinueCount", Name = "连庄次数:"}
	self.datas["RemainCardCount"] = {ID = "RemainCardCount", Name = "剩余牌数:"}
	self.datas["NowFirstInBankerList"] = {ID = "NowFirstInBankerList", Name = "您当前已经是上庄列表的首位"}
	self.datas["TicketNotEnough"] = {ID = "TicketNotEnough", Name = "钻石不足"}
	self.datas["BankerListIsFull"] = {ID = "BankerListIsFull", Name = "申请上庄列表已满，请稍候再申请"}
	self.datas["NowInBankerList"] = {ID = "NowInBankerList", Name = "您已经在上庄列表中"}
	self.datas["AskForBankerTip"] = {ID = "AskForBankerTip", Name = "您已成功申请上庄，请稍候"}
	self.datas["AskLeaveBankerTip"] = {ID = "AskLeaveBankerTip", Name = "您已申请下庄，下轮您将不再是庄家"}
	self.datas["AskFirstBankerTip"] = {ID = "AskFirstBankerTip", Name = "您已成功加入到上庄列表的第一位"}
	self.datas["NowBankerTip"] = {ID = "NowBankerTip", Name = "您当前正在坐庄"}
	self.datas["BankerGoldTip"] = {ID = "BankerGoldTip", Name = "申请上庄至少需要%d金币，是否前往充值"}
	self.datas["BankerLeaveTip"] = {ID = "BankerLeaveTip", Name = "您现在是庄家，下庄后才能离开"}
	self.datas["CurBankerText"] = {ID = "CurBankerText", Name = "当前庄家"}
	self.datas["BankerResultText"] = {ID = "BankerResultText", Name = "上庄成绩"}
	self.datas["BankerLimtText"] = {ID = "BankerLimtText", Name = "上庄条件"}
	self.datas["BankerListNull"] = {ID = "BankerListNull", Name = "目前无人申请上庄"}
	self.datas["BankerText"] = {ID = "BankerText", Name = "庄"}
	self.datas["PlayerText"] = {ID = "PlayerText", Name = "闲"}
	self.datas["TieText"] = {ID = "TieText", Name = "和"}
	self.datas["NowIsBanker"] = {ID = "NowIsBanker", Name = "您当前已经是庄家了"}
	self.datas["BankerWinText"] = {ID = "BankerWinText", Name = "庄家成绩:    %d金币"}
	self.datas["HelpText_1"] = {ID = "HelpText_1", Name = "筹码区域"}
	self.datas["HelpText_2"] = {ID = "HelpText_2", Name = "中心区域"}
	self.datas["HelpText_3"] = {ID = "HelpText_3", Name = "当前庄家信息&功能按钮"}
	self.datas["HelpText_4"] = {ID = "HelpText_4", Name = "信息按钮"}
	self.datas["RobBankerInfo_1"] = {ID = "RobBankerInfo_1", Name = "当前竞价为%d金币"}
	self.datas["RobBankerInfo_2"] = {ID = "RobBankerInfo_2", Name = "您是最高出价者%d金币"}
	self.datas["RobBankerTip"] = {ID = "RobBankerTip", Name = "是否花费%d金币竞价抢庄！\n (如果无人超过您的出价，下一局即可上庄) \n tip:竞价失败不会扣除金币"}
	self.datas["RobBankerYouFirst"] = {ID = "RobBankerYouFirst", Name = "您目前已经是出价最高的"}
	self.datas["OnBankerTip"] = {ID = "OnBankerTip", Name = "%s 已上庄成功！"}
	self.datas["OnBankerRobTip"] = {ID = "OnBankerRobTip", Name = "(此次上庄使用了抢庄功能)"}
	self.datas["LeaveBankerTip"] = {ID = "LeaveBankerTip", Name = "上庄%d局后方可下庄，是否花费%d钻石提前下庄！"}
	self.datas["LeaveBankerRepeat"] = {ID = "LeaveBankerRepeat", Name = "您已经申请过下庄了"}
	self.datas["AwardTimeTip_1"] = {ID = "AwardTimeTip_1", Name = "结算期间，无法申请上庄"}
	self.datas["AwardTimeTip_2"] = {ID = "AwardTimeTip_2", Name = "结算期间，无法申请下庄"}
	self.datas["AwardTimeTip_3"] = {ID = "AwardTimeTip_3", Name = "结算期间，无法抢庄"}
	self.datas["VipLockTip"] = {ID = "VipLockTip", Name = "VIP%d才能解锁，是否立即前往充值？"}
	self.datas["BetMaxText"] = {ID = "BetMaxText", Name = "单注上限:"}
	self.datas["WanText"] = {ID = "WanText", Name = "万"}
	self.datas["UpLimitTip"] = {ID = "UpLimitTip", Name = "是否现在进行充值？"}
	self.datas["BeginBetTip"] = {ID = "BeginBetTip", Name = "开始下注"}
	self.datas["TotalCanBet"] = {ID = "TotalCanBet", Name = "还能下注:%d"}
	self.datas["RepeatBetTip"] = {ID = "RepeatBetTip", Name = "续压金额超过可押注上限"}
	self.datas["SystemDrawWaterTip"] = {ID = "SystemDrawWaterTip", Name = "您已成功下庄，扣除%d%%系统手续费，共计%d金币"}
	self.datas["BankerNoCanBet"] = {ID = "BankerNoCanBet", Name = "您是庄家，无法下注"}
	self.datas["NowNoCanBet"] = {ID = "NowNoCanBet", Name = "现在还不能下注"}
	self.datas["NoCanChangeState"] = {ID = "NoCanChangeState", Name = "非下注期间不能修改该设置"}
	self.datas["CombineCardID_1"] = {ID = "CombineCardID_1", Name = "对至尊"}
	self.datas["CombineCardID_2"] = {ID = "CombineCardID_2", Name = "对天"}
	self.datas["CombineCardID_3"] = {ID = "CombineCardID_3", Name = "对地"}
	self.datas["CombineCardID_4"] = {ID = "CombineCardID_4", Name = "对神"}
	self.datas["CombineCardID_5"] = {ID = "CombineCardID_5", Name = "对鹅牌"}
	self.datas["CombineCardID_6"] = {ID = "CombineCardID_6", Name = "对平十"}
	self.datas["CombineCardID_7"] = {ID = "CombineCardID_7", Name = "对长三"}
	self.datas["CombineCardID_8"] = {ID = "CombineCardID_8", Name = "对板凳"}
	self.datas["CombineCardID_9"] = {ID = "CombineCardID_9", Name = "对斧头"}
	self.datas["CombineCardID_10"] = {ID = "CombineCardID_10", Name = "对棉花"}
	self.datas["CombineCardID_11"] = {ID = "CombineCardID_11", Name = "对高七"}
	self.datas["CombineCardID_12"] = {ID = "CombineCardID_12", Name = "对铜棰"}
	self.datas["CombineCardID_13"] = {ID = "CombineCardID_13", Name = "杂九"}
	self.datas["CombineCardID_14"] = {ID = "CombineCardID_14", Name = "杂八"}
	self.datas["CombineCardID_15"] = {ID = "CombineCardID_15", Name = "杂七"}
	self.datas["CombineCardID_16"] = {ID = "CombineCardID_16", Name = "杂五"}
	self.datas["CombineCardID_17"] = {ID = "CombineCardID_17", Name = "天九王"}
	self.datas["CombineCardID_18"] = {ID = "CombineCardID_18", Name = "天杠"}
	self.datas["CombineCardID_19"] = {ID = "CombineCardID_19", Name = "地杠"}
	self.datas["IsExitCurrentRoom"] = {ID = "IsExitCurrentRoom", Name = "确定要退出当前房间？"}
end

HappySupremacy_MultiLanguageCFG:init()
