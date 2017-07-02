Landlord_NetHumanMachine_SoundCFG = {}

function Landlord_NetHumanMachine_SoundCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function Landlord_NetHumanMachine_SoundCFG:init()
	self.datas = {}
	self.datas[1] = {SoundID = 1, SoundName = "百家乐背景音乐", SoundPath = "Sound/music-bg.mp3", SoundTime = 64}
	self.datas[2] = {SoundID = 2, SoundName = "倒计时音效", SoundPath = "Sound/count_down.mp3", SoundTime = 1}
	self.datas[3] = {SoundID = 3, SoundName = "倒计时3", SoundPath = "Sound/countdown_3.mp3", SoundTime = 1}
	self.datas[4] = {SoundID = 4, SoundName = "倒计时2", SoundPath = "Sound/countdown_2.mp3", SoundTime = 1}
	self.datas[5] = {SoundID = 5, SoundName = "倒计时1", SoundPath = "Sound/countdown_1.mp3", SoundTime = 1}
	self.datas[6] = {SoundID = 6, SoundName = "倒计时0开牌", SoundPath = "Sound/countdown_open.mp3", SoundTime = 1}
	self.datas[7] = {SoundID = 7, SoundName = "发牌音效", SoundPath = "Sound/sound-fapai.mp3", SoundTime = 1}
	self.datas[8] = {SoundID = 8, SoundName = "翻牌音效", SoundPath = "Sound/sound-fanpai.mp3", SoundTime = 1}
	self.datas[9] = {SoundID = 9, SoundName = "开始下注", SoundPath = "Sound/sound-start-wager.mp3", SoundTime = 2}
	self.datas[10] = {SoundID = 10, SoundName = "庄家轮换", SoundPath = "Sound/zhuang-2.mp3", SoundTime = 2}
	self.datas[11] = {SoundID = 11, SoundName = "筹码飞入音效", SoundPath = "Sound/sound-jetton.mp3", SoundTime = 1}
	self.datas[12] = {SoundID = 12, SoundName = "结算获胜音乐", SoundPath = "Sound/END_WIN.mp3", SoundTime = 5}
	self.datas[13] = {SoundID = 13, SoundName = "赢钱音效1", SoundPath = "Sound/girl_win_0.mp3", SoundTime = 2}
	self.datas[14] = {SoundID = 14, SoundName = "赢钱音效2", SoundPath = "Sound/girl_win_1.mp3", SoundTime = 3}
	self.datas[15] = {SoundID = 15, SoundName = "赢钱音效3", SoundPath = "Sound/girl_win_2.mp3", SoundTime = 3}
	self.datas[16] = {SoundID = 16, SoundName = "结算失败音乐", SoundPath = "Sound/END_LOST.mp3", SoundTime = 2}
	self.datas[17] = {SoundID = 17, SoundName = "输钱音效1", SoundPath = "Sound/girl_lost_1.mp3", SoundTime = 3}
	self.datas[18] = {SoundID = 18, SoundName = "输钱音效2", SoundPath = "Sound/girl_lost_2.mp3", SoundTime = 3}
	self.datas[19] = {SoundID = 19, SoundName = "输钱音效3", SoundPath = "Sound/girl_lost_3.mp3", SoundTime = 3}
	self.datas[20] = {SoundID = 20, SoundName = "和", SoundPath = "Sound/tie.mp3", SoundTime = 1}
	self.datas[21] = {SoundID = 21, SoundName = "闲赢", SoundPath = "Sound/player_win.mp3", SoundTime = 1}
	self.datas[22] = {SoundID = 22, SoundName = "闲对", SoundPath = "Sound/player_pair.mp3", SoundTime = 1}
	self.datas[23] = {SoundID = 23, SoundName = "庄对", SoundPath = "Sound/banker_pair.mp3", SoundTime = 1}
	self.datas[24] = {SoundID = 24, SoundName = "庄赢", SoundPath = "Sound/banker_win.mp3", SoundTime = 1}
	self.datas[25] = {SoundID = 25, SoundName = "游戏结束", SoundPath = "Sound/GAME_END.mp3", SoundTime = 1}
end

Landlord_NetHumanMachine_SoundCFG:init()
