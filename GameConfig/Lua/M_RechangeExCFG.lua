M_RechangeExCFG = {}

function M_RechangeExCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_RechangeExCFG:init()
	self.datas = {}
end

M_RechangeExCFG:init()
