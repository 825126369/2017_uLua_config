M_RobotHeadIconCFG = {}

function M_RobotHeadIconCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_RobotHeadIconCFG:init()
	self.datas = {}
end

M_RobotHeadIconCFG:init()
