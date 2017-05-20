M_FaceCFG = {}

function M_FaceCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_FaceCFG:init()
	self.datas = {}
	self.datas[1] = {ID = 1, Name = "表情1", Icon = "UI/faceIcon/game_face01.png"}
	self.datas[2] = {ID = 2, Name = "表情2", Icon = "UI/faceIcon/game_face02.png"}
	self.datas[3] = {ID = 3, Name = "表情3", Icon = "UI/faceIcon/game_face03.png"}
	self.datas[4] = {ID = 4, Name = "表情4", Icon = "UI/faceIcon/game_face04.png"}
	self.datas[5] = {ID = 5, Name = "表情5", Icon = "UI/faceIcon/game_face05.png"}
	self.datas[6] = {ID = 6, Name = "表情6", Icon = "UI/faceIcon/game_face06.png"}
	self.datas[7] = {ID = 7, Name = "表情7", Icon = "UI/faceIcon/game_face07.png"}
	self.datas[8] = {ID = 8, Name = "表情8", Icon = "UI/faceIcon/game_face08.png"}
	self.datas[9] = {ID = 9, Name = "表情9", Icon = "UI/faceIcon/game_face09.png"}
	self.datas[10] = {ID = 10, Name = "表情10", Icon = "UI/faceIcon/game_face10.png"}
	self.datas[11] = {ID = 11, Name = "表情11", Icon = "UI/faceIcon/game_face11.png"}
	self.datas[12] = {ID = 12, Name = "表情12", Icon = "UI/faceIcon/game_face12.png"}
	self.datas[13] = {ID = 13, Name = "表情13", Icon = "UI/faceIcon/game_face13.png"}
	self.datas[14] = {ID = 14, Name = "表情14", Icon = "UI/faceIcon/game_face14.png"}
	self.datas[15] = {ID = 15, Name = "表情15", Icon = "UI/faceIcon/game_face15.png"}
end

M_FaceCFG:init()
