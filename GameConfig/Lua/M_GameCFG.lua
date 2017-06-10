M_GameCFG = {}

function M_GameCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_GameCFG:init()
	self.datas = {}
	self.datas[1] = {ID = 1, GameName = "经典捕鱼", GamePrefix = "Fish", UpdateUrl = "http://121.199.75.142:26011", IsOpen = false, GameSize = "9.30M", ZipVersion = "2.4.0", AnimationName = "shuanglongbuyu", PictureName = "shuanglongbuyu", IsShow = false}
	self.datas[2] = {ID = 2, GameName = "鳄鱼大亨", GamePrefix = "Crocodile", UpdateUrl = "http://121.199.75.142:26011", IsOpen = false, GameSize = "3.50M", ZipVersion = "2.4.0", AnimationName = "eyudaheng", PictureName = "shuanglongbuyu", IsShow = false}
	self.datas[3] = {ID = 3, GameName = "欢乐骰宝", GamePrefix = "Dice", UpdateUrl = "http://121.199.75.142:26011", IsOpen = false, GameSize = "2.00M", ZipVersion = "2.4.0", AnimationName = "yaoyaole", PictureName = "shuanglongbuyu", IsShow = false}
	self.datas[4] = {ID = 4, GameName = "万人牛牛", GamePrefix = "Cows", UpdateUrl = "http://121.199.75.142:26011", IsOpen = false, GameSize = "2.00M", ZipVersion = "2.4.0", AnimationName = "bairenniuniu", PictureName = "shuanglongbuyu", IsShow = false}
	self.datas[5] = {ID = 5, GameName = "百家乐", GamePrefix = "Baccarat", UpdateUrl = "http://121.199.75.142:26011", IsOpen = false, GameSize = "2.00M", ZipVersion = "2.4.0", AnimationName = "jiangxiangheab", PictureName = "shuanglongbuyu", IsShow = false}
	self.datas[6] = {ID = 6, GameName = "五龙", GamePrefix = "5Dragons", UpdateUrl = "http://121.199.75.142:26011", IsOpen = false, GameSize = "7.00M", ZipVersion = "2.4.0", AnimationName = "wulongzhengbaaabbc", PictureName = "shuanglongbuyu", IsShow = false}
	self.datas[7] = {ID = 7, GameName = "套牛", GamePrefix = "CalfRoping", UpdateUrl = "http://121.199.75.142:26011", IsOpen = false, GameSize = "2.00M", ZipVersion = "0.0.0", AnimationName = "taoniujitai", PictureName = "shuanglongbuyu", IsShow = false}
	self.datas[8] = {ID = 8, GameName = "抓娃娃", GamePrefix = "PrizeClaw", UpdateUrl = "http://121.199.75.142:26011", IsOpen = false, GameSize = "3.00M", ZipVersion = "0.0.0", AnimationName = "WAWAjitai", PictureName = "shuanglongbuyu", IsShow = false}
	self.datas[9] = {ID = 9, GameName = "鳄鱼公园", GamePrefix = "FishPark", UpdateUrl = "http://121.199.75.142:26011", IsOpen = false, GameSize = "2.00M", ZipVersion = "0.0.0", AnimationName = "eyugongyuan", PictureName = "shuanglongbuyu", IsShow = false}
	self.datas[10] = {ID = 10, GameName = "黑红梅方", GamePrefix = "ShcdCards", UpdateUrl = "http://121.199.75.142:26011", IsOpen = false, GameSize = "2.00M", ZipVersion = "2.4.0", AnimationName = "heihongmeifangab", PictureName = "shuanglongbuyu", IsShow = false}
	self.datas[11] = {ID = 11, GameName = "德州扑克", GamePrefix = "TexasPoker", UpdateUrl = "http://121.199.75.142:26011", IsOpen = false, GameSize = "2.00M", ZipVersion = "0.0.0", AnimationName = "BAIJIALEjitai", PictureName = "shuanglongbuyu", IsShow = false}
	self.datas[12] = {ID = 12, GameName = "金鲨银鲨", GamePrefix = "GoldShark", UpdateUrl = "http://121.199.75.142:26011", IsOpen = false, GameSize = "2.00M", ZipVersion = "0.0.0", AnimationName = "heihongmeifangab", PictureName = "shuanglongbuyu", IsShow = false}
	self.datas[13] = {ID = 13, GameName = "欢乐五张", GamePrefix = "SuoHa", UpdateUrl = "http://121.199.75.142:26011", IsOpen = false, GameSize = "2.00M", ZipVersion = "0.0.0", AnimationName = "shuanglongbuyu", PictureName = "shuanglongbuyu", IsShow = false}
	self.datas[14] = {ID = 14, GameName = "欢乐至尊", GamePrefix = "HappySupremacy", UpdateUrl = "http://121.199.75.142:26011", IsOpen = false, GameSize = "2.00M", ZipVersion = "0.0.0", AnimationName = "shuanglongbuyu", PictureName = "shuanglongbuyu", IsShow = false}
	self.datas[15] = {ID = 15, GameName = "斗地主", GamePrefix = "Landlord", UpdateUrl = "http://121.199.75.142:26011", IsOpen = true, GameSize = "2.00M", ZipVersion = "0.0.0", AnimationName = "shuanglongbuyu", PictureName = "shuanglongbuyu", IsShow = true}
end

M_GameCFG:init()
