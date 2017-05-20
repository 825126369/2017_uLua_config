M_ActivityMultiLanguageCFG = {}

function M_ActivityMultiLanguageCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_ActivityMultiLanguageCFG:init()
	self.datas = {}
	self.datas["ActivityTime1"] = {ID = "ActivityTime1", Name = "活动时间:2016年4月27日0:00至2016年5月3日23:59"}
	self.datas["ActivityTitle1"] = {ID = "ActivityTitle1", Name = "四月充值有惊喜，单笔充值满即送钻石。充几次算几次千万别错过哦！"}
	self.datas["ActivityContent1"] = {ID = "ActivityContent1", Name = "充值198元送100钻石；{newline}充值328元送330钻石；"}
	self.datas["ActivityTime2"] = {ID = "ActivityTime2", Name = ""}
	self.datas["ActivityTitle2"] = {ID = "ActivityTitle2", Name = "捕鱼新杀器“齐天大圣”炮台(原价3627钻石,现3折980钻石。劳动节前夕限时特卖。美猴王至尊法器,必杀开启虐杀鱼场。"}
	self.datas["ActivityContent2"] = {ID = "ActivityContent2", Name = "“齐天大圣”炮台再度优惠登场，不买睡不着！"}
	self.datas["ActivityTime3"] = {ID = "ActivityTime3", Name = ""}
	self.datas["ActivityTitle3"] = {ID = "ActivityTitle3", Name = "新版本火热上线——VIP权限再度强化，VIP3买炮台折扣3折！一日VIP终生VIP，马上加入到VIP队伍中来吧。这等福利就是要让老板跳楼的节奏啊！！！"}
	self.datas["ActivityShowBegin"] = {ID = "ActivityShowBegin", Name = "2016-04-01 00:00:00"}
	self.datas["ActivityShowEnd"] = {ID = "ActivityShowEnd", Name = "2016-06-01 00:00:00"}
	self.datas["ActivityShowThree"] = {ID = "ActivityShowThree", Name = "2016-04-01 00:00:00"}
end

M_ActivityMultiLanguageCFG:init()
