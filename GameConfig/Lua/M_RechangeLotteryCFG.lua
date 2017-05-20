M_RechangeLotteryCFG = {}

function M_RechangeLotteryCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_RechangeLotteryCFG:init()
	self.datas = {}
	self.datas[1] = {Much = 1, FirstRate = 10000, DefaultRate = 10000}
	self.datas[2] = {Much = 2, FirstRate = 5900, DefaultRate = 1300}
	self.datas[3] = {Much = 3, FirstRate = 0, DefaultRate = 0}
	self.datas[4] = {Much = 4, FirstRate = 0, DefaultRate = 0}
	self.datas[5] = {Much = 5, FirstRate = 1100, DefaultRate = 300}
	self.datas[6] = {Much = 6, FirstRate = 0, DefaultRate = 0}
	self.datas[7] = {Much = 7, FirstRate = 400, DefaultRate = 200}
	self.datas[8] = {Much = 8, FirstRate = 0, DefaultRate = 0}
	self.datas[9] = {Much = 9, FirstRate = 0, DefaultRate = 100}
	self.datas[10] = {Much = 10, FirstRate = 0, DefaultRate = 0}
end

M_RechangeLotteryCFG:init()
