M_GameCFG = {}

function M_GameCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_GameCFG:init()
	self.datas = {}
	self.datas[15] = {ID = 15, GameName = "斗地主-人机大战", IsOpen = true}
	self.datas[16] = {ID = 16, GameName = "斗地主-自定义游戏", IsOpen = true}
	self.datas[17] = {ID = 17, GameName = "斗地主-排位赛", IsOpen = true}
end

M_GameCFG:init()
