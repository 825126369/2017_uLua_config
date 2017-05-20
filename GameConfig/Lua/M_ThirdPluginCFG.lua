M_ThirdPluginCFG = {}

function M_ThirdPluginCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_ThirdPluginCFG:init()
	self.datas = {}
	self.datas["999000"] = {ChannelID = "999000", Platform = "baiduview", LuaFilePath = "plugin.baiduViewPCPlugin", Remark = "棋牌官网PC"}
	self.datas["999001"] = {ChannelID = "999001", Platform = "baiduview", LuaFilePath = "plugin.baiduViewPCPlugin", Remark = "影音官网PC"}
	self.datas["999002"] = {ChannelID = "999002", Platform = "baiduview", LuaFilePath = "plugin.baiduViewPCPlugin", Remark = "影音吊起PC"}
	self.datas["999003"] = {ChannelID = "999003", Platform = "otherpc", LuaFilePath = "plugin.PCWebPlugin", Remark = "金山软件管家"}
	self.datas["999004"] = {ChannelID = "999004", Platform = "baiduview", LuaFilePath = "plugin.baiduViewPCPlugin", Remark = "影音静默PC"}
	self.datas["999005"] = {ChannelID = "999005", Platform = "otherpc", LuaFilePath = "plugin.PCWebPlugin", Remark = "360软件管家"}
	self.datas["991000"] = {ChannelID = "991000", Platform = "pc360", LuaFilePath = "plugin.PC360Plugin", Remark = "360PC"}
	self.datas["990001"] = {ChannelID = "990001", Platform = "otherpc", LuaFilePath = "plugin.PCWebPlugin", Remark = "其他PC"}
	self.datas["800017"] = {ChannelID = "800017", Platform = "baiduview", LuaFilePath = "plugin.baiduViewAndroidPlugin", Remark = "7091百度安卓"}
	self.datas["800018"] = {ChannelID = "800018", Platform = "iapppay", LuaFilePath = "plugin.iapppayPlugin", Remark = "爱贝web支付"}
	self.datas["800021"] = {ChannelID = "800021", Platform = "iapppay", LuaFilePath = "plugin.iapppayPlugin", Remark = "爱贝web支付"}
	self.datas["800033"] = {ChannelID = "800033", Platform = "iapppay", LuaFilePath = "plugin.iapppayPlugin", Remark = "爱贝web支付"}
end

M_ThirdPluginCFG:init()
