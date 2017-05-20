M_SoundCFG = {}

function M_SoundCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_SoundCFG:init()
	self.datas = {}
	self.datas[1] = {SoundID = 1, SoundName = "点击", SoundPath = "Sound/click.mp3", SoundTime = 1}
	self.datas[2] = {SoundID = 2, SoundName = "取消", SoundPath = "Sound/back.mp3", SoundTime = 1}
	self.datas[3] = {SoundID = 3, SoundName = "奖励", SoundPath = "Sound/bonus.mp3", SoundTime = 1}
	self.datas[4] = {SoundID = 4, SoundName = "筹码", SoundPath = "Sound/coins.mp3", SoundTime = 1}
	self.datas[5] = {SoundID = 5, SoundName = "弹出框", SoundPath = "Sound/popup.mp3", SoundTime = 1}
	self.datas[6] = {SoundID = 6, SoundName = "升级", SoundPath = "Sound/lvup.mp3", SoundTime = 1}
	self.datas[7] = {SoundID = 7, SoundName = "在线奖励", SoundPath = "Sound/charge.mp3", SoundTime = 1}
	self.datas[8] = {SoundID = 8, SoundName = "大厅音乐", SoundPath = "Sound/BG00.mp3", SoundTime = 58}
	self.datas[9] = {SoundID = 9, SoundName = "标题界面音乐", SoundPath = "Sound/BG309", SoundTime = 112}
	self.datas[10] = {SoundID = 10, SoundName = "收集金币音效", SoundPath = "Sound/ReceiveGold1.mp3", SoundTime = 2}
	self.datas[11] = {SoundID = 11, SoundName = "街机台选中音效", SoundPath = "Sound/arcade.mp3", SoundTime = 2}
	self.datas[12] = {SoundID = 12, SoundName = "金币音效", SoundPath = "Sound/gold.mp3", SoundTime = 5}
end

M_SoundCFG:init()
