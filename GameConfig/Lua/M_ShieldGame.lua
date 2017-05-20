M_ShieldGame = {}

function M_ShieldGame:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_ShieldGame:init()
	self.datas = {}
	self.datas[800031] = {ChannelID = 800031, Type = 2, ShieldGameList = {1}, ShowAchieveList = {0,1}}
end

M_ShieldGame:init()
