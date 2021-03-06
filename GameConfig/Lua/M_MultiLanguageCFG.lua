M_MultiLanguageCFG = {}

function M_MultiLanguageCFG:getData(key)
	if self.datas == nil then
		return nil
	end
	return self.datas[key]
end

function M_MultiLanguageCFG:init()
	self.datas = {}
	self.datas["Version_Check"] = {ID = "Version_Check", Name = "正在检测版本。"}
	self.datas["Version_NetError"] = {ID = "Version_NetError", Name = "老板，网络不给力，换个试试！"}
	self.datas["Version_IsNew"] = {ID = "Version_IsNew", Name = "当前版本已最新"}
	self.datas["Version_DownloadFile"] = {ID = "Version_DownloadFile", Name = "一大波~金币正赶来,老板等等哦~"}
	self.datas["Version_DownloadComplete"] = {ID = "Version_DownloadComplete", Name = "更新完成"}
	self.datas["Version_NeedUpdate"] = {ID = "Version_NeedUpdate", Name = "亲，旧版本赚不了钱，请更新吧！"}
	self.datas["Version_DownloadList"] = {ID = "Version_DownloadList", Name = "正在准备金币，请稍等。"}
	self.datas["Version_UpdateFail"] = {ID = "Version_UpdateFail", Name = "更新文件失败，请稍后重试。"}
	self.datas["Version_Updating"] = {ID = "Version_Updating", Name = "正在准备金币"}
	self.datas["Version_NeedRedownload"] = {ID = "Version_NeedRedownload", Name = "亲，这版本赚不了钱，请去对应平台更新当前版本吧！"}
	self.datas["Version_Downloading"] = {ID = "Version_Downloading", Name = "正在准备金币"}
	self.datas["Login_AccIsEmpty"] = {ID = "Login_AccIsEmpty", Name = "空账号无法提款哦,快填上！"}
	self.datas["Login_AccIsShort"] = {ID = "Login_AccIsShort", Name = "帐号不能少于6个字符。"}
	self.datas["Login_AccIsInvalid"] = {ID = "Login_AccIsInvalid", Name = "帐号只能由字母和数字组成。"}
	self.datas["Login_PwdIsEmpty"] = {ID = "Login_PwdIsEmpty", Name = "密码不能为空。"}
	self.datas["Login_PwdIsShort"] = {ID = "Login_PwdIsShort", Name = "密码不能少于6个字符。"}
	self.datas["Login_AccIsExists"] = {ID = "Login_AccIsExists", Name = "帐号已经存在。"}
	self.datas["Login_AccIsNotExists"] = {ID = "Login_AccIsNotExists", Name = "帐号不存在。"}
	self.datas["Login_AccOrPwdError"] = {ID = "Login_AccOrPwdError", Name = "帐号或密码错误。"}
	self.datas["Login_UnknownError"] = {ID = "Login_UnknownError", Name = "未知错误。"}
	self.datas["Login_NetError"] = {ID = "Login_NetError", Name = "老板，网络不给力，换个试试！"}
	self.datas["Login_IsLogining"] = {ID = "Login_IsLogining", Name = "正在登录中，请稍候。"}
	self.datas["Login_IsRegistering"] = {ID = "Login_IsRegistering", Name = "正在注册帐号，请稍候。"}
	self.datas["Login_RegisterSuccess"] = {ID = "Login_RegisterSuccess", Name = "注册成功。"}
	self.datas["Login_SystemError"] = {ID = "Login_SystemError", Name = "错误"}
	self.datas["Login_NetErrorTitle"] = {ID = "Login_NetErrorTitle", Name = "网络不给力啊，亲！换个网络环境再试试吧。"}
	self.datas["Login_LoginSuccess"] = {ID = "Login_LoginSuccess", Name = "登录成功。"}
	self.datas["Login_NeedRelogin"] = {ID = "Login_NeedRelogin", Name = "登录信息过期，请重新登录。"}
	self.datas["Login_DownloadServerList"] = {ID = "Login_DownloadServerList", Name = "正在为您准备房间，请稍等。"}
	self.datas["Login_DownloadError"] = {ID = "Login_DownloadError", Name = "获取服务器信息失败，请稍后重试。"}
	self.datas["Login_PhoneError"] = {ID = "Login_PhoneError", Name = "手机号码不正确，请输入正确手机号。"}
	self.datas["Login_CodeError"] = {ID = "Login_CodeError", Name = "请输入6位验证码。"}
	self.datas["Login_AskCode"] = {ID = "Login_AskCode", Name = "正在请求验证码…"}
	self.datas["Login_AskCodeSuccess"] = {ID = "Login_AskCodeSuccess", Name = "请求验证码成功。"}
	self.datas["Login_Reset"] = {ID = "Login_Reset", Name = "正在请求重设密码…"}
	self.datas["Login_ResetSuccess"] = {ID = "Login_ResetSuccess", Name = "重设密码成功。"}
	self.datas["Login_Init"] = {ID = "Login_Init", Name = "初始化登录…"}
	self.datas["Login_GetAccount"] = {ID = "Login_GetAccount", Name = "获取账号信息…"}
	self.datas["Login_NotInfo"] = {ID = "Login_NotInfo", Name = "不能获取账号信息，请重新登录。"}
	self.datas["Net_ConnectServer"] = {ID = "Net_ConnectServer", Name = "正在连接服务器。"}
	self.datas["Net_ConnectFail"] = {ID = "Net_ConnectFail", Name = "网络不给力啊，亲！换个网络环境再试试吧。"}
	self.datas["Net_ConnectSuccess"] = {ID = "Net_ConnectSuccess", Name = "服务器连接成功。"}
	self.datas["Net_SelectGate"] = {ID = "Net_SelectGate", Name = "正在选择网关…"}
	self.datas["Net_VerifyLogin"] = {ID = "Net_VerifyLogin", Name = "正在验证帐号信息…"}
	self.datas["Net_AskLogin"] = {ID = "Net_AskLogin", Name = "正在请求玩家信息…"}
	self.datas["Net_VerifyLoginFail"] = {ID = "Net_VerifyLoginFail", Name = "帐号验证失败…"}
	self.datas["Net_ReConnect"] = {ID = "Net_ReConnect", Name = "重新连接服务器。"}
	self.datas["Net_Confirm"] = {ID = "Net_Confirm", Name = "确定"}
	self.datas["Net_Retry"] = {ID = "Net_Retry", Name = "重试"}
	self.datas["Config_InnerUrl"] = {ID = "Config_InnerUrl", Name = "http://192.168.1.11:26001/CheckVersion.aspx?type=default"}
	self.datas["Config_OuterUrl"] = {ID = "Config_OuterUrl", Name = "http://116.231.72.57:26001/CheckVersion.aspx?type=outer"}
	self.datas["Recharge_Success"] = {ID = "Recharge_Success", Name = "充值成功，多赢点哦！"}
	self.datas["SendGiftTitle"] = {ID = "SendGiftTitle", Name = "附带礼物的邮件"}
	self.datas["SendGiftContent"] = {ID = "SendGiftContent", Name = "这是送你的礼物，请收好。"}
	self.datas["GameNotOpen"] = {ID = "GameNotOpen", Name = "暂未开放！亲，尽请期待哦！"}
	self.datas["GoldNotEnough"] = {ID = "GoldNotEnough", Name = "钱包怎么瘪了，金币不够诶"}
	self.datas["BetFull"] = {ID = "BetFull", Name = "押注已满"}
	self.datas["GetOnlineAward"] = {ID = "GetOnlineAward", Name = "领取在线奖励%d金币"}
	self.datas["OnlineAwardIsOver"] = {ID = "OnlineAwardIsOver", Name = "在线奖励已领完"}
	self.datas["TicketNotEnough"] = {ID = "TicketNotEnough", Name = "钻石还差点？充值也可以获得钻石哦！"}
	self.datas["StartBet"] = {ID = "StartBet", Name = "开始押注，祝君赢钱"}
	self.datas["StopBet"] = {ID = "StopBet", Name = "开骰啦！买定离手！"}
	self.datas["WaitNewGame"] = {ID = "WaitNewGame", Name = "老板，先喝口水！游戏马上开始！"}
	self.datas["Big"] = {ID = "Big", Name = "大"}
	self.datas["Small"] = {ID = "Small", Name = "小"}
	self.datas["Leopard"] = {ID = "Leopard", Name = "豹子"}
	self.datas["Point"] = {ID = "Point", Name = "点"}
	self.datas["RoomNotOpen"] = {ID = "RoomNotOpen", Name = "房间暂未开放"}
	self.datas["Msg_Result0"] = {ID = "Msg_Result0", Name = "未知错误"}
	self.datas["Msg_Result1"] = {ID = "Msg_Result1", Name = "成功"}
	self.datas["Msg_Result2"] = {ID = "Msg_Result2", Name = "啊呀好像发生了未知错误，请稍候重试！"}
	self.datas["Msg_Result3"] = {ID = "Msg_Result3", Name = "改变网关"}
	self.datas["Msg_Result4"] = {ID = "Msg_Result4", Name = "连接已满"}
	self.datas["Msg_Result5"] = {ID = "Msg_Result5", Name = "玩家已满"}
	self.datas["Msg_Result6"] = {ID = "Msg_Result6", Name = "转盘奖励已领！不如充值还送钻石哦！"}
	self.datas["Msg_Result7"] = {ID = "Msg_Result7", Name = "老板，非法字符会带来霉运！赶紧换个吧！"}
	self.datas["Msg_Result8"] = {ID = "Msg_Result8", Name = "老板，抱歉！昵称已被使用！"}
	self.datas["Msg_Result9"] = {ID = "Msg_Result9", Name = "文本信息内容过长"}
	self.datas["Msg_Result10"] = {ID = "Msg_Result10", Name = "金币不足，地主家也没余粮了"}
	self.datas["Msg_Result11"] = {ID = "Msg_Result11", Name = "钻石还差点？充值也可以获得钻石哦！"}
	self.datas["Msg_Result12"] = {ID = "Msg_Result12", Name = "房间已满"}
	self.datas["Msg_Result13"] = {ID = "Msg_Result13", Name = "VIP等级低，就这么忍了？"}
	self.datas["Msg_Result14"] = {ID = "Msg_Result14", Name = "等级太低，亲~还需努力"}
	self.datas["Msg_Result15"] = {ID = "Msg_Result15", Name = "亲，好友已达上限！"}
	self.datas["Msg_Result16"] = {ID = "Msg_Result16", Name = "好友已在！约起来~"}
	self.datas["Msg_Result17"] = {ID = "Msg_Result17", Name = "查无此人，会不会被抓了?"}
	self.datas["Msg_Result18"] = {ID = "Msg_Result18", Name = "次数用完"}
	self.datas["Msg_Result19"] = {ID = "Msg_Result19", Name = "时间未到"}
	self.datas["Msg_Result20"] = {ID = "Msg_Result20", Name = "老板，再看看~现在无法押注"}
	self.datas["Msg_Result21"] = {ID = "Msg_Result21", Name = "老板，押注序号错了"}
	self.datas["Msg_Result22"] = {ID = "Msg_Result22", Name = "老板，不能再押了"}
	self.datas["Msg_Result23"] = {ID = "Msg_Result23", Name = "没有找到桌子"}
	self.datas["Msg_Result24"] = {ID = "Msg_Result24", Name = "两次密码不一致"}
	self.datas["Msg_Result25"] = {ID = "Msg_Result25", Name = "格式非法"}
	self.datas["Msg_Result26"] = {ID = "Msg_Result26", Name = "需要设置密码"}
	self.datas["Msg_Result27"] = {ID = "Msg_Result27", Name = "密码错误"}
	self.datas["Msg_Result28"] = {ID = "Msg_Result28", Name = "亲~道具放哪里了？"}
	self.datas["Msg_Result29"] = {ID = "Msg_Result29", Name = "好友离线"}
	self.datas["Msg_Result30"] = {ID = "Msg_Result30", Name = "不在游戏内"}
	self.datas["Msg_Result31"] = {ID = "Msg_Result31", Name = "无法购买"}
	self.datas["Msg_Result32"] = {ID = "Msg_Result32", Name = "无法加自己为好友"}
	self.datas["Msg_Result33"] = {ID = "Msg_Result33", Name = "发言频繁"}
	self.datas["Msg_Result34"] = {ID = "Msg_Result34", Name = "经验不够"}
	self.datas["Msg_Result35"] = {ID = "Msg_Result35", Name = "已经达到最大等级"}
	self.datas["Msg_Result36"] = {ID = "Msg_Result36", Name = "玩家不满足领取救济金的要求"}
	self.datas["Msg_Result37"] = {ID = "Msg_Result37", Name = "您已绑定过手机，或者已经有5个账号绑定过该手机。"}
	self.datas["Msg_Result38"] = {ID = "Msg_Result38", Name = "验证码错误"}
	self.datas["Msg_Result39"] = {ID = "Msg_Result39", Name = "超出限制"}
	self.datas["Msg_Result40"] = {ID = "Msg_Result40", Name = "没有绑定手机"}
	self.datas["Msg_Result41"] = {ID = "Msg_Result41", Name = "不能给自己赠送"}
	self.datas["Msg_Result42"] = {ID = "Msg_Result42", Name = "房间未开放"}
	self.datas["Msg_Result43"] = {ID = "Msg_Result43", Name = "押注已满"}
	self.datas["Msg_Result44"] = {ID = "Msg_Result44", Name = "游戏已经开始"}
	self.datas["Msg_Result45"] = {ID = "Msg_Result45", Name = "庄家不能押注"}
	self.datas["Msg_Result46"] = {ID = "Msg_Result46", Name = "上庄列表已满"}
	self.datas["Msg_Result47"] = {ID = "Msg_Result47", Name = "上庄期间不能离开"}
	self.datas["Msg_Result48"] = {ID = "Msg_Result48", Name = "已领取"}
	self.datas["Msg_Result49"] = {ID = "Msg_Result49", Name = "还没有充值"}
	self.datas["Msg_Result50"] = {ID = "Msg_Result50", Name = "头像冻结中，此时时间内，不能再次上传头像"}
	self.datas["Msg_Result51"] = {ID = "Msg_Result51", Name = "已经是上庄列表的第一个了"}
	self.datas["Msg_Result52"] = {ID = "Msg_Result52", Name = "已经在上庄列表中"}
	self.datas["Msg_Result53"] = {ID = "Msg_Result53", Name = "现在是庄家"}
	self.datas["Msg_Result54"] = {ID = "Msg_Result54", Name = "不是庄家"}
	self.datas["Msg_Result55"] = {ID = "Msg_Result55", Name = "已经申请离开"}
	self.datas["Msg_Result56"] = {ID = "Msg_Result56", Name = "上庄次数不足"}
	self.datas["Msg_Result57"] = {ID = "Msg_Result57", Name = "下注金额已满"}
	self.datas["Msg_Result58"] = {ID = "Msg_Result58", Name = "自己下注金额已满"}
	self.datas["Msg_Result59"] = {ID = "Msg_Result59", Name = "错误游戏状态"}
	self.datas["Msg_Result60"] = {ID = "Msg_Result60", Name = "该宝箱不存在"}
	self.datas["Msg_Result61"] = {ID = "Msg_Result61", Name = "宝箱已经抽过了，处于打开状态"}
	self.datas["Msg_Result62"] = {ID = "Msg_Result62", Name = "谢谢参与个数不足"}
	self.datas["Msg_Result63"] = {ID = "Msg_Result63", Name = "已经是你自己了"}
	self.datas["Msg_Result73"] = {ID = "Msg_Result73", Name = "五龙游戏不能跟随"}
	self.datas["Msg_Result74"] = {ID = "Msg_Result74", Name = "套牛游戏不能跟随"}
	self.datas["Text_Give"] = {ID = "Text_Give", Name = "赠送"}
	self.datas["MaintenanceNotify"] = {ID = "MaintenanceNotify", Name = "重要通知，我们将于 %s，对服务器进行维护。届时您可能无法登录服务器，希望广大亲爱的用户相互转告。并且对您造成的不便敬请谅解！"}
	self.datas["Mail_Title"] = {ID = "Mail_Title", Name = "欢迎您的到来"}
	self.datas["Mail_From"] = {ID = "Mail_From", Name = "电玩城运营团队"}
	self.datas["Mail_Text"] = {ID = "Mail_Text", Name = "各位老板，欢迎您来到电玩城世界。这里有各种政要人物、上流人士、明星期待与您共同尽兴娱乐！愿您幸运永存！"}
	self.datas["Mail_Title_1"] = {ID = "Mail_Title_1", Name = "恭喜加入VIP家庭"}
	self.datas["Mail_Text_1"] = {ID = "Mail_Text_1", Name = "尊敬的玩家，您现在已晋升为VIP用户,祝您越玩越开心，收益翻翻翻。"}
	self.datas["Mail_Title_2"] = {ID = "Mail_Title_2", Name = "VIP专属秘书已赶到您身边！"}
	self.datas["Mail_Text_2"] = {ID = "Mail_Text_2", Name = "您已成为尊贵的高级VIP用户，将享受我们为您定制的专门服务！现在您不但可随意进入所有游戏VIP专场"}
	self.datas["BuyGold"] = {ID = "BuyGold", Name = "您获得了%d"}
	self.datas["BuyTicket"] = {ID = "BuyTicket", Name = "附赠%d"}
	self.datas["System"] = {ID = "System", Name = "系统"}
	self.datas["Loading_Loading"] = {ID = "Loading_Loading", Name = "正在加载资源，请稍候。"}
	self.datas["Setting_Success"] = {ID = "Setting_Success", Name = "密码设置成功"}
	self.datas["pwd_not_same"] = {ID = "pwd_not_same", Name = "两次密码不一致"}
	self.datas["pwd_error"] = {ID = "pwd_error", Name = "密码错误"}
	self.datas["olpwd"] = {ID = "olpwd", Name = "旧密码："}
	self.datas["newpwd"] = {ID = "newpwd", Name = "新密码："}
	self.datas["pwd_6_to_8"] = {ID = "pwd_6_to_8", Name = "输入6-14位密码"}
	self.datas["pwd1"] = {ID = "pwd1", Name = "密码"}
	self.datas["pwd"] = {ID = "pwd", Name = "密       码："}
	self.datas["confirm_pwd"] = {ID = "confirm_pwd", Name = "确认密码："}
	self.datas["cash"] = {ID = "cash", Name = "现金"}
	self.datas["deposit"] = {ID = "deposit", Name = "存款"}
	self.datas["Enter_Money"] = {ID = "Enter_Money", Name = "请输入金额"}
	self.datas["Enter_pwd"] = {ID = "Enter_pwd", Name = "请输入密码"}
	self.datas["Re_enter1"] = {ID = "Re_enter1", Name = "输入的金额超过了现金总额，请重新输入"}
	self.datas["Re_enter2"] = {ID = "Re_enter2", Name = "输入的金额超过了保险箱总额，请重新输入"}
	self.datas["Save_money"] = {ID = "Save_money", Name = "您已存入金币："}
	self.datas["Withdrawals"] = {ID = "Withdrawals", Name = "您已取出金币："}
	self.datas["Repeat_add_friend"] = {ID = "Repeat_add_friend", Name = "好友已在！约起来~"}
	self.datas["Send_add_friend"] = {ID = "Send_add_friend", Name = "约炮信息已发！敬候佳音~"}
	self.datas["NewAccountName"] = {ID = "NewAccountName", Name = "新用户%06d"}
	self.datas["not_add_self"] = {ID = "not_add_self", Name = "老板~别逗了好吗？"}
	self.datas["RoomGoldCondition"] = {ID = "RoomGoldCondition", Name = "要求"}
	self.datas["RoomVipCondition"] = {ID = "RoomVipCondition", Name = "需要VIP%d解锁"}
	self.datas["BuySuccess"] = {ID = "BuySuccess", Name = "购买成功"}
	self.datas["OperationSuccess"] = {ID = "OperationSuccess", Name = "操作成功"}
	self.datas["SendGift"] = {ID = "SendGift", Name = "点击选择礼物，点击确定赠送"}
	self.datas["BetAreaFull"] = {ID = "BetAreaFull", Name = "当前下注区域最大值为x,无法继续下注"}
	self.datas["OldInfo"] = {ID = "OldInfo", Name = "前x局:"}
	self.datas["ChatTooOfen"] = {ID = "ChatTooOfen", Name = "大家正在回味您刚说的话，请休息片刻~"}
	self.datas["YouNowText"] = {ID = "YouNowText", Name = "您当前的"}
	self.datas["LevelText"] = {ID = "LevelText", Name = "等级:"}
	self.datas["YouNextText"] = {ID = "YouNextText", Name = "即可升级到"}
	self.datas["YouNeedText"] = {ID = "YouNeedText", Name = "再充值"}
	self.datas["RMBText"] = {ID = "RMBText", Name = "元"}
	self.datas["BroadcastHelpText"] = {ID = "BroadcastHelpText", Name = "发送小喇叭，可以让大家都看到喔！"}
	self.datas["VipInfo_1"] = {ID = "VipInfo_1", Name = "可领取在线奖励%d次"}
	self.datas["VipInfo_2"] = {ID = "VipInfo_2", Name = "解锁房间:%s"}
	self.datas["VipInfo_3"] = {ID = "VipInfo_3", Name = "解锁捕鱼道具:%s"}
	self.datas["VipInfo_4"] = {ID = "VipInfo_4", Name = "解锁礼物:%s"}
	self.datas["VipInfo_5"] = {ID = "VipInfo_5", Name = "每日送礼上限%s金币"}
	self.datas["VipInfo_6"] = {ID = "VipInfo_6", Name = "尊贵VIP%d标志"}
	self.datas["AlmsIntroduce"] = {ID = "AlmsIntroduce", Name = "总资产少于%d金币才可以领取救济金。"}
	self.datas["AlmsGetOver"] = {ID = "AlmsGetOver", Name = "救济金无法度日，不如充值试试"}
	self.datas["AlmsGetInfo"] = {ID = "AlmsGetInfo", Name = "您获得了%d救济金，今天最多还能领取%d次。"}
	self.datas["not_search_self"] = {ID = "not_search_self", Name = "不能搜索自己"}
	self.datas["AlmsGetFail"] = {ID = "AlmsGetFail", Name = "亲，您还有钱~不能领救济金~"}
	self.datas["Choose_gift"] = {ID = "Choose_gift", Name = "请选择礼物"}
	self.datas["GoldToCharge"] = {ID = "GoldToCharge", Name = "亲，金币不足~充值能获得充足的金币哦！"}
	self.datas["TicketToCharge"] = {ID = "TicketToCharge", Name = "亲，钻石不足~充值能获得充足的钻石哦！"}
	self.datas["VipToCharge"] = {ID = "VipToCharge", Name = "VIP等级不够！老板，是否要提升一下身价?"}
	self.datas["giftSuccess"] = {ID = "giftSuccess", Name = "老板，就属您最慷慨~"}
	self.datas["error_id"] = {ID = "error_id", Name = "请输入正确的ID"}
	self.datas["addFirendSuc"] = {ID = "addFirendSuc", Name = "添加好友成功"}
	self.datas["RoomGoldTip"] = {ID = "RoomGoldTip", Name = "该房间最少需要%d金币才可以进入，是否前往充值？"}
	self.datas["RoomVipTip"] = {ID = "RoomVipTip", Name = "该房间最少需要VIP%d才可以进入，是否前往充值？"}
	self.datas["BetMaxText"] = {ID = "BetMaxText", Name = "单注上限:"}
	self.datas["FishLevelLimit"] = {ID = "FishLevelLimit", Name = "炮台限制:%d级"}
	self.datas["SelfRank"] = {ID = "SelfRank", Name = "我的排名"}
	self.datas["ServerText_1"] = {ID = "ServerText_1", Name = "客服QQ:"}
	self.datas["ServerText_2"] = {ID = "ServerText_2", Name = "微信公众号:"}
	self.datas["ServerText_3"] = {ID = "ServerText_3", Name = "客服电话:"}
	self.datas["ServerInfo_1"] = {ID = "ServerInfo_1", Name = "xxxxxxxxx"}
	self.datas["ServerInfo_2"] = {ID = "ServerInfo_2", Name = "xxxxxxxxx"}
	self.datas["ServerInfo_3"] = {ID = "ServerInfo_3", Name = "xxxxxxxxx"}
	self.datas["ServerTip"] = {ID = "ServerTip", Name = "亲，如遇问题，可联系客服"}
	self.datas["RepeatLogin1"] = {ID = "RepeatLogin1", Name = "您的账号在另一个设备上登录。"}
	self.datas["RepeatLogin2"] = {ID = "RepeatLogin2", Name = "账号验证失败，请重新登录。"}
	self.datas["RepeatLogin3"] = {ID = "RepeatLogin3", Name = "您的账号暂时处于冻结状态，请联系客户服务中心了解详细情况。"}
	self.datas["RepeatLogin4"] = {ID = "RepeatLogin4", Name = "您的账户已被系统踢出，请在5分钟后再登陆。"}
	self.datas["NoNoticeText"] = {ID = "NoNoticeText", Name = "暂无公告"}
	self.datas["PlayerNameOverLong"] = {ID = "PlayerNameOverLong", Name = "昵称限制最长8个字符"}
	self.datas["PhoneNumTip"] = {ID = "PhoneNumTip", Name = "输入手机号"}
	self.datas["VerifyTip"] = {ID = "VerifyTip", Name = "验证码"}
	self.datas["PhoneRepeat"] = {ID = "PhoneRepeat", Name = "您已绑定过手机了"}
	self.datas["PhoneNumError"] = {ID = "PhoneNumError", Name = "您输入的号码有误"}
	self.datas["PhoneTooOfen"] = {ID = "PhoneTooOfen", Name = "请求验证太过频繁"}
	self.datas["BindSuccess"] = {ID = "BindSuccess", Name = "绑定成功"}
	self.datas["VerifyBefore"] = {ID = "VerifyBefore", Name = "您尚未发送手机号码"}
	self.datas["VerifyNull"] = {ID = "VerifyNull", Name = "验证码不能为空"}
	self.datas["VerifyError"] = {ID = "VerifyError", Name = "验证码错误"}
	self.datas["SendGoldTip"] = {ID = "SendGoldTip", Name = "恭喜你获得了%d金币"}
	self.datas["SendGift1"] = {ID = "SendGift1", Name = "赠送的对象："}
	self.datas["SendGift2"] = {ID = "SendGift2", Name = "需要花费：x金币"}
	self.datas["SendGift3"] = {ID = "SendGift3", Name = "TIPS:接受方会获得礼物价值%d"}
	self.datas["SendGift4"] = {ID = "SendGift4", Name = "的金币"}
	self.datas["SendGift5"] = {ID = "SendGift5", Name = "赠送的物品："}
	self.datas["selfSignature"] = {ID = "selfSignature", Name = "这家伙很懒，什么都没留下"}
	self.datas["isFloor"] = {ID = "isFloor", Name = "请输入整数"}
	self.datas["GoldError"] = {ID = "GoldError", Name = "请输入正确金额"}
	self.datas["playername"] = {ID = "playername", Name = "用户名:"}
	self.datas["BeginBet"] = {ID = "BeginBet", Name = "请点击下注区域下注！"}
	self.datas["DiceHelpText"] = {ID = "DiceHelpText", Name = "骰宝是一种古老的中国骰子游戏，在古代尤为盛行。\n玩家押注三个在笼子中转动的骰子的旋转结果。\n您可以同时押注在桌面上的一个或多个数字。\n游戏的牌桌分割成几部分押注“区域”，每一个区域代表不同类的骰子结果或组合。"}
	self.datas["MaxGiftslimit"] = {ID = "MaxGiftslimit", Name = "老板，今日赠送额度已超上限！若想再送，请提升VIP等级，即可再送！"}
	self.datas["GameBroadcast"] = {ID = "GameBroadcast", Name = "恭喜玩家%1%在%2%%3%%6%%7%获得%4%万%5%！"}
	self.datas["FishHitGoldMsg"] = {ID = "FishHitGoldMsg", Name = "恭喜[VIP%1%]%2%捕获%3%，获得金币%4%！"}
	self.datas["FishHitGiftMsg"] = {ID = "FishHitGiftMsg", Name = "恭喜[VIP%1%]%2%击杀%3%，额外获赠钻石%4%！"}
	self.datas["MoneyType1"] = {ID = "MoneyType1", Name = "金币"}
	self.datas["MoneyType2"] = {ID = "MoneyType2", Name = "钻石"}
	self.datas["VipNotice"] = {ID = "VipNotice", Name = "用户[%1%]的VIP等级突破[%2%]级，大家一起来恭喜TA吧！"}
	self.datas["BroadcastCdTip"] = {ID = "BroadcastCdTip", Name = "%d秒后可再次发送"}
	self.datas["BroadcastTooOfen"] = {ID = "BroadcastTooOfen", Name = "发送太过频繁"}
	self.datas["MailTitle"] = {ID = "MailTitle", Name = "邮件标题:"}
	self.datas["MailSendName"] = {ID = "MailSendName", Name = "发件人:"}
	self.datas["SendSuc"] = {ID = "SendSuc", Name = "发送成功！"}
	self.datas["MailReceiveName"] = {ID = "MailReceiveName", Name = "收件人:"}
	self.datas["InputTitle"] = {ID = "InputTitle", Name = "请输入标题"}
	self.datas["InputDesc"] = {ID = "InputDesc", Name = "请输入内容"}
	self.datas["MailDeleteTip"] = {ID = "MailDeleteTip", Name = "这份邮件您尚未阅读，说不定里面有小礼物哦，真的就直接删掉吗？"}
	self.datas["ReplyTip"] = {ID = "ReplyTip", Name = "系统邮件无法回复"}
	self.datas["Get"] = {ID = "Get", Name = "恭喜你获得了"}
	self.datas["getCode"] = {ID = "getCode", Name = "验证码"}
	self.datas["InputPwd1"] = {ID = "InputPwd1", Name = "输入密码"}
	self.datas["InputPwd2"] = {ID = "InputPwd2", Name = "再次输入"}
	self.datas["changPwdText"] = {ID = "changPwdText", Name = "请输入绑定手机短信收到的验证码，以及新密码"}
	self.datas["HeadFrameHaveText"] = {ID = "HeadFrameHaveText", Name = "已拥有"}
	self.datas["HeadFrameEquipText"] = {ID = "HeadFrameEquipText", Name = "已装备"}
	self.datas["GiftText1"] = {ID = "GiftText1", Name = "时间"}
	self.datas["GiftText2"] = {ID = "GiftText2", Name = "赠送对象"}
	self.datas["GiftText3"] = {ID = "GiftText3", Name = "礼物"}
	self.datas["GiftText4"] = {ID = "GiftText4", Name = "数量"}
	self.datas["GetMailGift"] = {ID = "GetMailGift", Name = "获得%s"}
	self.datas["updateCusHead2"] = {ID = "updateCusHead2", Name = "更换自定义头像需要花费%d钻石"}
	self.datas["updateCusHeadFree"] = {ID = "updateCusHeadFree", Name = "更换自定义头像,本次免费"}
	self.datas["updateCusHead1"] = {ID = "updateCusHead1", Name = "更换自定义头像需要花费%d黄金"}
	self.datas["ExChangeTip"] = {ID = "ExChangeTip", Name = "您已成功申请兑换,请耐心等待客服与您联系！"}
	self.datas["ExChangeGoldTip"] = {ID = "ExChangeGoldTip", Name = "您已成功兑换%d金币"}
	self.datas["ExChangeTicketTip"] = {ID = "ExChangeTicketTip", Name = "您已成功兑换%d钻石"}
	self.datas["ExChangePhoneTip"] = {ID = "ExChangePhoneTip", Name = "请输入您的手机号码，以便客服与您沟通发放兑换的奖励事宜。"}
	self.datas["TimeFormat"] = {ID = "TimeFormat", Name = "%d年%d月%d日"}
	self.datas["ChangeNameTip"] = {ID = "ChangeNameTip", Name = "请输入昵称："}
	self.datas["NameNotNull"] = {ID = "NameNotNull", Name = "昵称不能为空"}
	self.datas["ChangeNamePayTip"] = {ID = "ChangeNamePayTip", Name = "本次修改需要消耗"}
	self.datas["ChangeNameFirst"] = {ID = "ChangeNameFirst", Name = "首次修改免费"}
	self.datas["ChargeErrorTip"] = {ID = "ChargeErrorTip", Name = "充值未到账，请稍后登录查看。"}
	self.datas["DataText"] = {ID = "DataText", Name = "日期"}
	self.datas["ExChangeItemName"] = {ID = "ExChangeItemName", Name = "奖品名称"}
	self.datas["ExChangeState"] = {ID = "ExChangeState", Name = "兑换状态"}
	self.datas["ExChangeWait"] = {ID = "ExChangeWait", Name = "审核中"}
	self.datas["ExChangeSend"] = {ID = "ExChangeSend", Name = "已发送"}
	self.datas["ExChangeNoRecord"] = {ID = "ExChangeNoRecord", Name = "当前没有记录"}
	self.datas["betName"] = {ID = "betName", Name = "押注名称"}
	self.datas["betDesc"] = {ID = "betDesc", Name = "描述"}
	self.datas["betOdds"] = {ID = "betOdds", Name = "赔率"}
	self.datas["betExample"] = {ID = "betExample", Name = "范例"}
	self.datas["UpdateGame_Download"] = {ID = "UpdateGame_Download", Name = "该游戏还未下载，是否现在下载？"}
	self.datas["UpdateGame_DownloadInfo"] = {ID = "UpdateGame_DownloadInfo", Name = "下载内容约为%s,建议您在WIFI环境下载。"}
	self.datas["UpdateGame_Update"] = {ID = "UpdateGame_Update", Name = "检测有最新版本，是否现在更新？"}
	self.datas["UpdateGame_UpdateInfo"] = {ID = "UpdateGame_UpdateInfo", Name = "建议您在WIFI环境下载。"}
	self.datas["UpdateGame_Unzip"] = {ID = "UpdateGame_Unzip", Name = "正在解压文件…"}
	self.datas["input_error"] = {ID = "input_error", Name = "密码长度错误或输入错误"}
	self.datas["HitType1"] = {ID = "HitType1", Name = "击杀"}
	self.datas["HitType2"] = {ID = "HitType2", Name = "押中"}
	self.datas["SetPanelText_1"] = {ID = "SetPanelText_1", Name = "音乐:"}
	self.datas["SetPanelText_2"] = {ID = "SetPanelText_2", Name = "音效:"}
	self.datas["SetPanelText_3"] = {ID = "SetPanelText_3", Name = "整体:"}
	self.datas["SetPanelText_4"] = {ID = "SetPanelText_4", Name = "开"}
	self.datas["SetPanelText_5"] = {ID = "SetPanelText_5", Name = "关"}
	self.datas["LoginOut"] = {ID = "LoginOut", Name = "登出账号"}
	self.datas["LoginOutConfirm"] = {ID = "LoginOutConfirm", Name = "是否确认登出账号？"}
	self.datas["Retry"] = {ID = "Retry", Name = "请x秒后重试"}
	self.datas["GoldUpLimit"] = {ID = "GoldUpLimit", Name = "您的金币将超过上限，无法继续购买！"}
	self.datas["SendGoldLimit"] = {ID = "SendGoldLimit", Name = "送礼金额已达上限"}
	self.datas["AccountText"] = {ID = "AccountText", Name = "账号:"}
	self.datas["PasswordText1"] = {ID = "PasswordText1", Name = "输入密码:"}
	self.datas["PasswordText2"] = {ID = "PasswordText2", Name = "再次输入:"}
	self.datas["notOpen"] = {ID = "notOpen", Name = "暂未开放"}
	self.datas["GiftNotReceive"] = {ID = "GiftNotReceive", Name = "老板~您的金币已达上限~无法再获得更多金币~"}
	self.datas["GetMonthCardTip"] = {ID = "GetMonthCardTip", Name = "获得月卡奖励%d金币"}
	self.datas["MonthCardRemainTime"] = {ID = "MonthCardRemainTime", Name = "剩余:%d天"}
	self.datas["MonthCardBuyTip"] = {ID = "MonthCardBuyTip", Name = "亲，月卡陪伴您30天了，难道就忍心说拜拜吗？"}
	self.datas["GoldUpLimitTip"] = {ID = "GoldUpLimitTip", Name = "本游戏金币上限为2000000亿，超过部分将消失"}
	self.datas["online"] = {ID = "online", Name = "在线"}
	self.datas["not_online"] = {ID = "not_online", Name = "离线"}
	self.datas["input_f_id"] = {ID = "input_f_id", Name = "请输入ID"}
	self.datas["gift_num"] = {ID = "gift_num", Name = "礼物统计"}
	self.datas["ExChangeVipTip"] = {ID = "ExChangeVipTip", Name = "VIP%d专属"}
	self.datas["ExChangeTip1"] = {ID = "ExChangeTip1", Name = "点击图片兑换礼品！"}
	self.datas["ExChangeTip2"] = {ID = "ExChangeTip2", Name = "温馨提示:钻石可以在任意游戏中胜利获得哦！"}
	self.datas["ModifyPwd"] = {ID = "ModifyPwd", Name = "修改密码"}
	self.datas["PlayerInfoText1"] = {ID = "PlayerInfoText1", Name = "用户ID:"}
	self.datas["PlayerInfoText2"] = {ID = "PlayerInfoText2", Name = "总资产:"}
	self.datas["PlayerInfoText3"] = {ID = "PlayerInfoText3", Name = "所持钻石:"}
	self.datas["PlayerInfoText4"] = {ID = "PlayerInfoText4", Name = "VIP等级:"}
	self.datas["PlayerInfoText5"] = {ID = "PlayerInfoText5", Name = "月卡时限:"}
	self.datas["NoMonthCard"] = {ID = "NoMonthCard", Name = "暂未获得"}
	self.datas["UsePhotoTip"] = {ID = "UsePhotoTip", Name = "在相册中选择"}
	self.datas["UseCameraTip"] = {ID = "UseCameraTip", Name = "用照相机拍照"}
	self.datas["OnLineCountText"] = {ID = "OnLineCountText", Name = "在线人数:"}
	self.datas["ExperienceVipDayText"] = {ID = "ExperienceVipDayText", Name = "剩余%d天"}
	self.datas["ExperienceVipHourText"] = {ID = "ExperienceVipHourText", Name = "剩余%d小时"}
	self.datas["PlayerNum"] = {ID = "PlayerNum", Name = "当前总人数"}
	self.datas["plyaer_win"] = {ID = "plyaer_win", Name = "赢得x金钱"}
	self.datas["VipInfo_7"] = {ID = "VipInfo_7", Name = "尊贵VIP头像边框"}
	self.datas["DiceHelpLab1"] = {ID = "DiceHelpLab1", Name = "聊天框点击聊天"}
	self.datas["DiceHelpLab2"] = {ID = "DiceHelpLab2", Name = "筹码栏任意选择下注额度"}
	self.datas["DiceHelpLab3"] = {ID = "DiceHelpLab3", Name = "功能按钮栏"}
	self.datas["DiceHelpLab4"] = {ID = "DiceHelpLab4", Name = "点击任意或多个下注区域下注"}
	self.datas["goldout"] = {ID = "goldout", Name = "老板~金币多时可存保险箱，安全有保障~"}
	self.datas["LotteryTip1"] = {ID = "LotteryTip1", Name = "抽奖次数每日中午12点更新"}
	self.datas["LotteryTip2"] = {ID = "LotteryTip2", Name = "今日剩余免费抽奖次数"}
	self.datas["LotteryTip3"] = {ID = "LotteryTip3", Name = "友情提示：如果当天未抽中，宝箱状态不会重置，直到抽中为止！"}
	self.datas["LotteryTip4"] = {ID = "LotteryTip4", Name = "TIPS：累计%d次“鼓励奖”可以兑换%d钻石！"}
	self.datas["LotteryWin"] = {ID = "LotteryWin", Name = "所有人对您投来羡慕的目光，恭喜您~中大奖啦~"}
	self.datas["LotteryThanks"] = {ID = "LotteryThanks", Name = "恭喜您，获得“鼓励奖”"}
	self.datas["LotteryThanksNotEnough"] = {ID = "LotteryThanksNotEnough", Name = "哎哟~亲~“鼓励奖”已领完"}
	self.datas["LotteryUseTicket"] = {ID = "LotteryUseTicket", Name = "亲，免费次数已用完。可使用%d钻石再抽哦~"}
	self.datas["LotteryWinTip"] = {ID = "LotteryWinTip", Name = "恭喜您~中大奖啦~期待您下次再中哦~"}
	self.datas["LotteryFailTip"] = {ID = "LotteryFailTip", Name = "亲~大奖与您失之交臂~下次一定会中的，加油~"}
	self.datas["err_not_phone"] = {ID = "err_not_phone", Name = "手机号码不正确，请输入正确手机号。"}
	self.datas["err_not_bind"] = {ID = "err_not_bind", Name = "手机号码未绑定帐号。"}
	self.datas["err_timecd"] = {ID = "err_timecd", Name = "请求验证码太过频繁，请稍后申请。"}
	self.datas["err_maxcount"] = {ID = "err_maxcount", Name = "今日申请验证码次数已满，请明天再试。"}
	self.datas["err_sendfailed"] = {ID = "err_sendfailed", Name = "请求验证码错误，请稍后重试。"}
	self.datas["err_sign_error"] = {ID = "err_sign_error", Name = "签名错误，请联系游戏管理员。"}
	self.datas["err_data_error"] = {ID = "err_data_error", Name = "数据错误，请联系游戏管理员。"}
	self.datas["err_acc_error "] = {ID = "err_acc_error ", Name = "帐号错误，请联系游戏管理员。"}
	self.datas["err_pwd_error"] = {ID = "err_pwd_error", Name = "密码错误，请联系游戏管理员。"}
	self.datas["err_system_error"] = {ID = "err_system_error", Name = "系统错误，请联系游戏管理员。"}
	self.datas["err_code_error"] = {ID = "err_code_error", Name = "您输入的验证码有误。"}
	self.datas["err_weixin_error"] = {ID = "err_weixin_error", Name = "检测到您尚未安装微信，请先安装微信客户端。"}
	self.datas["ExitGameTip"] = {ID = "ExitGameTip", Name = "是否立即退出游戏？"}
	self.datas["Msg_AppStoreWait"] = {ID = "Msg_AppStoreWait", Name = "连接AppStore服务中……"}
	self.datas["TimeText"] = {ID = "TimeText", Name = "次"}
	self.datas["ContinueSendText2"] = {ID = "ContinueSendText2", Name = "需要支付"}
	self.datas["ContinueSendText3"] = {ID = "ContinueSendText3", Name = "VIP%d以上"}
	self.datas["SendContentNotNull"] = {ID = "SendContentNotNull", Name = "发送内容不能为空"}
	self.datas["ContinueSendTip1"] = {ID = "ContinueSendTip1", Name = "请输入正确次数"}
	self.datas["ContinueSendMaxCount"] = {ID = "ContinueSendMaxCount", Name = "连续发送次数不能大于%d次"}
	self.datas["ContinueSendRemainCount"] = {ID = "ContinueSendRemainCount", Name = "您已经在使用连续发送小喇叭功能，还剩余%d次。"}
	self.datas["Login_AccountInfo"] = {ID = "Login_AccountInfo", Name = "请输入用户名"}
	self.datas["Login_PasswordInfo"] = {ID = "Login_PasswordInfo", Name = "请输入密码"}
	self.datas["Register_AccountInfo"] = {ID = "Register_AccountInfo", Name = "请输6-14位用户名"}
	self.datas["Register_PasswordInfo"] = {ID = "Register_PasswordInfo", Name = "请输入6-14位密码"}
	self.datas["Register_PhoneNum"] = {ID = "Register_PhoneNum", Name = "请输入手机号"}
	self.datas["Register_GetCode"] = {ID = "Register_GetCode", Name = "输入验证码"}
	self.datas["SafeBoxTip"] = {ID = "SafeBoxTip", Name = "亲，最低存款为10万元哦。"}
	self.datas["BcPlayerEnter"] = {ID = "BcPlayerEnter", Name = "天空一声巨响，%s踩着五彩祥云驾到！"}
	self.datas["touchGo"] = {ID = "touchGo", Name = "点击屏幕继续"}
	self.datas["Goldnotenough"] = {ID = "Goldnotenough", Name = "金币不足x，无法进入游戏"}
	self.datas["2016chongfanbiaoti"] = {ID = "2016chongfanbiaoti", Name = "2016年新版本充值返利"}
	self.datas["2016chongfanneirong100"] = {ID = "2016chongfanneirong100", Name = "  您获得了100钻石的充值返利，本次活动将于2016年4月25日23:59结束。凡单笔充值198元即送100钻石，单笔充值328元就送330钻石。不限次数，抓紧机会，再充一次吧！"}
	self.datas["2016chongfanneirong300"] = {ID = "2016chongfanneirong300", Name = "  您获得了330钻石的充值返利，本次活动将于2016年4月25日23:59结束。凡单笔充值198元即送100钻石，单笔充值328元就送330钻石。不限次数，抓紧机会，再充一次吧！"}
	self.datas["20160207denglubiaoti"] = {ID = "20160207denglubiaoti", Name = "2月7日登录奖励"}
	self.datas["20160208denglubiaoti"] = {ID = "20160208denglubiaoti", Name = "2月8日登录奖励"}
	self.datas["20160209denglubiaoti"] = {ID = "20160209denglubiaoti", Name = "2月9日登录奖励"}
	self.datas["20160210denglubiaoti"] = {ID = "20160210denglubiaoti", Name = "2月10日登录奖励"}
	self.datas["20160211denglubiaoti"] = {ID = "20160211denglubiaoti", Name = "2月11日登录奖励"}
	self.datas["20160212denglubiaoti"] = {ID = "20160212denglubiaoti", Name = "2月12日登录奖励"}
	self.datas["20160213denglubiaoti"] = {ID = "20160213denglubiaoti", Name = "2月13日登录奖励"}
	self.datas["20160207dengluneirong"] = {ID = "20160207dengluneirong", Name = "  福禄寿喜报新春，凡2月7日登录游戏，可获得2888金币和一顶非卖品“福”字新帽。请记得在“个性化头像”设置中把它穿戴起来，并祝您猴年——阖家幸福。"}
	self.datas["20160208dengluneirong"] = {ID = "20160208dengluneirong", Name = "  福禄寿喜报新春，凡2月8日登录的玩家，可获得18钻石一份。"}
	self.datas["20160209dengluneirong"] = {ID = "20160209dengluneirong", Name = "  福禄寿喜报新春，凡2月9日登录游戏，可获得3888金币和一顶非卖品“禄”字新帽。请记得在“个性化头像”  设置中把它穿戴起来，并祝您猴年——高官厚禄。"}
	self.datas["20160210dengluneirong"] = {ID = "20160210dengluneirong", Name = "  福禄寿喜报新春，凡2月10日登录的玩家，可获得28钻石一份。"}
	self.datas["20160211dengluneirong"] = {ID = "20160211dengluneirong", Name = "  福禄寿喜报新春，凡2月11日登录游戏，可获得4888金币和一顶非卖品“寿”字新帽。请记得在“个性化头像”设置中把它穿戴起来，并祝您猴年——健康长寿。"}
	self.datas["20160212dengluneirong"] = {ID = "20160212dengluneirong", Name = "  福禄寿喜报新春，凡2月12日登录的玩家，可获得38钻石一份。"}
	self.datas["20160213dengluneirong"] = {ID = "20160213dengluneirong", Name = "  福禄寿喜报新春，凡2月13日登录游戏，可获得5888金币和一顶非卖品“喜”字新帽。请记得在“个性化头像”设置中把它穿戴起来，并祝您猴年——欢喜连连。"}
	self.datas["BuySend"] = {ID = "BuySend", Name = "充值即赠"}
	self.datas["ApplyToCharge"] = {ID = "ApplyToCharge", Name = "申请上庄需要500万金币！\n~充值能获得充足的金币哦！"}
	self.datas["RechargeTip"] = {ID = "RechargeTip", Name = ">= x金币,单注上限:y"}
	self.datas["nowRecharge"] = {ID = "nowRecharge", Name = "是否现在进行充值?"}
	self.datas["BuyItemNeedVIP"] = {ID = "BuyItemNeedVIP", Name = "需要VIP%d才能购买该炮台,是否现在进行充值?"}
	self.datas["GetFirstFrameTip"] = {ID = "GetFirstFrameTip", Name = "获得头像框“魔术礼帽”"}
	self.datas["ActivityGetTip"] = {ID = "ActivityGetTip", Name = "需要VIP%d才可领取"}
	self.datas["OnlineRemainTime"] = {ID = "OnlineRemainTime", Name = "距离下次领取还有%d分钟"}
	self.datas["OnlineOverTimer"] = {ID = "OnlineOverTimer", Name = "今日在线奖励领取已结束"}
	self.datas["OnlineNotBegin"] = {ID = "OnlineNotBegin", Name = "今日在线奖励领取尚未开始"}
	self.datas["DragonsTip1"] = {ID = "DragonsTip1", Name = "您的五龙等级不够,花费x"}
	self.datas["DragonsTip2"] = {ID = "DragonsTip2", Name = "提升等级到%d级"}
	self.datas["DragonsTip3"] = {ID = "DragonsTip3", Name = "当前拥有"}
	self.datas["DragonsTip4"] = {ID = "DragonsTip4", Name = "成功提升等级！"}
	self.datas["DragonsTip5"] = {ID = "DragonsTip5", Name = "是否花费x"}
	self.datas["DragonsTip6"] = {ID = "DragonsTip6", Name = "购买一次机会"}
	self.datas["NoticeSendTime"] = {ID = "NoticeSendTime", Name = "发布时间:"}
	self.datas["NotHave"] = {ID = "NotHave", Name = "暂无"}
	self.datas["DragonsTip7"] = {ID = "DragonsTip7", Name = "您可以前往更高等级的房间进行游戏"}
	self.datas["EnterRoomGold"] = {ID = "EnterRoomGold", Name = "需要%d金币才能开始游戏，是否前往充值？"}
	self.datas["EnterRoomVIP"] = {ID = "EnterRoomVIP", Name = "需要VIP%d才能开始游戏，是否前往充值？"}
	self.datas["PokerGameIdx1"] = {ID = "PokerGameIdx1", Name = "选择红或黑，押中可让奖金X2"}
	self.datas["PokerGameIdx2"] = {ID = "PokerGameIdx2", Name = "选择花色，押中可让奖金X4"}
	self.datas["PokerGameIdx3"] = {ID = "PokerGameIdx3", Name = "最多有5次选择机会。"}
	self.datas["MonthCardSend1"] = {ID = "MonthCardSend1", Name = "解锁捕鱼自动开炮"}
	self.datas["MonthCardSend2"] = {ID = "MonthCardSend2", Name = "月卡专属炮台(30天)"}
	self.datas["MonthCardSend3"] = {ID = "MonthCardSend3", Name = "别忘记在捕鱼商店里装备上哦！"}
	self.datas["ChipNotEnough"] = {ID = "ChipNotEnough", Name = "话费券不足，兑换需要%d元话费券"}
	self.datas["ChipNotEnough2"] = {ID = "ChipNotEnough2", Name = "彩券不足，兑换需要%d彩券"}
	self.datas["FreeGoldInfo"] = {ID = "FreeGoldInfo", Name = "%s元"}
	self.datas["RewardLotteryInfo"] = {ID = "RewardLotteryInfo", Name = "{fontname=Common2/FZY3JW.TTF,color=0xFFE86008,fontsize=36}%d秒{color=0xFFFFFFFF}内点击GO按钮可提前停止转盘。"}
	self.datas["ReportTip"] = {ID = "ReportTip", Name = "举报成功，我们将尽快对您举报的信息进行处理！"}
	self.datas["FreeLotteryNotStar1"] = {ID = "FreeLotteryNotStar1", Name = "捕获图鉴中标记星星的鱼可得到星星，积攒星星可抽奖"}
	self.datas["FreeLotteryStar1"] = {ID = "FreeLotteryStar1", Name = "捕获更多鱼提升奖池才能抽更高的奖"}
	self.datas["FreeLotteryNotStar4"] = {ID = "FreeLotteryNotStar4", Name = "每局胜利可得到星星"}
	self.datas["FreeLotteryStar4"] = {ID = "FreeLotteryStar4", Name = "赢得更多的金币提升奖池才能抽更高的奖"}
	self.datas["FreeLotteryNotStar2"] = {ID = "FreeLotteryNotStar2", Name = "每局胜利可得到星星"}
	self.datas["FreeLotteryStar2"] = {ID = "FreeLotteryStar2", Name = "赢得更多的金币提升奖池才能抽更高的奖"}
	self.datas["FreeLotteryNotStar3"] = {ID = "FreeLotteryNotStar3", Name = "每局胜利可得到星星"}
	self.datas["FreeLotteryStar3"] = {ID = "FreeLotteryStar3", Name = "赢得更多的金币提升奖池才能抽更高的奖"}
	self.datas["FreeLotteryNotStar5"] = {ID = "FreeLotteryNotStar5", Name = "每局胜利可得到星星"}
	self.datas["FreeLotteryStar5"] = {ID = "FreeLotteryStar5", Name = "赢得更多的金币提升奖池才能抽更高的奖"}
	self.datas["FreeLotteryNotStar6"] = {ID = "FreeLotteryNotStar6", Name = "摇奖中奖金额超过单注即可赢得星星"}
	self.datas["FreeLotteryStar7"] = {ID = "FreeLotteryStar7", Name = "赢得更多的金币提升奖池才能抽更高的奖"}
	self.datas["FreeLotteryNotStar9"] = {ID = "FreeLotteryNotStar9", Name = "捕获图鉴中标记星星的鱼可得到星星，积攒星星可抽奖"}
	self.datas["FreeLotteryStar9"] = {ID = "FreeLotteryStar9", Name = "捕获更多鱼提升奖池才能抽更高的奖"}
	self.datas["FreeLotteryClick"] = {ID = "FreeLotteryClick", Name = "请点击任意一张牌"}
	self.datas["FreeLotteryNotStar"] = {ID = "FreeLotteryNotStar", Name = "您的星星不足，还需要%d个星星才能抽奖"}
	self.datas["FreeLotteryStar"] = {ID = "FreeLotteryStar", Name = "再累计%d金币至奖池可抽更高级奖，确认抽奖？"}
	self.datas["CowsBroadcast"] = {ID = "CowsBroadcast", Name = "恭喜[VIP%1%]%2%在万人牛牛中获得%3%金币！"}
	self.datas["RechargeLotteryNotice"] = {ID = "RechargeLotteryNotice", Name = "恭喜[%1%]在充值摇奖中鸿运当头，获得充值金额的%2%倍奖励！"}
	self.datas["StarLotteryNotice"] = {ID = "StarLotteryNotice", Name = "恭喜[%1%]在免费抽奖中鸿运当头，抽中话费券%2%元！"}
	self.datas["rechargeNotify"] = {ID = "rechargeNotify", Name = "恭喜VIP%1%[%2%]充值%3%得到%4%钻石，附赠%5%钻石！"}
	self.datas["RechargeNotify01"] = {ID = "RechargeNotify01", Name = "恭喜VIP%1%[%2%]充值%3%得到%4%金币，附赠%5%金币！"}
	self.datas["RechargeNotify02"] = {ID = "RechargeNotify02", Name = "恭喜VIP%1%[%2%]充值%3%得到%4%钻石！"}
	self.datas["RechargeNotify03"] = {ID = "RechargeNotify03", Name = "恭喜VIP%1%[%2%]充值%3%得到%4%金币！"}
	self.datas["RechargeNotify04"] = {ID = "RechargeNotify04", Name = "恭喜VIP%1%[%2%]充值%3%成为尊贵月卡玩家！"}
	self.datas["RobotNotice01"] = {ID = "RobotNotice01", Name = "用户[%1%]的VIP等级突破3级，大家一起来恭喜TA吧！"}
	self.datas["RobotNotice02"] = {ID = "RobotNotice02", Name = "用户[%1%]的VIP等级突破4级，大家一起来恭喜TA吧！"}
	self.datas["RobotNotice03"] = {ID = "RobotNotice03", Name = "用户[%1%]的VIP等级突破5级，大家一起来恭喜TA吧！"}
	self.datas["RobotNotice04"] = {ID = "RobotNotice04", Name = "用户[%1%]的VIP等级突破6级，大家一起来恭喜TA吧！"}
	self.datas["RobotNotice05"] = {ID = "RobotNotice05", Name = "恭喜[%1%]在充值摇奖中鸿运当头，获得充值金额的2倍奖励！"}
	self.datas["RobotNotice06"] = {ID = "RobotNotice06", Name = "恭喜[%1%]在充值摇奖中鸿运当头，获得充值金额的3倍奖励！"}
	self.datas["RobotNotice07"] = {ID = "RobotNotice07", Name = "恭喜[%1%]在充值摇奖中鸿运当头，获得充值金额的6倍奖励！"}
	self.datas["RobotNotice08"] = {ID = "RobotNotice08", Name = "恭喜[%1%]在充值摇奖中鸿运当头，获得充值金额的8倍奖励！"}
	self.datas["RobotNotice09"] = {ID = "RobotNotice09", Name = "恭喜[%1%]在充值摇奖中鸿运当头，获得充值金额的10倍奖励！"}
	self.datas["RobotNotice10"] = {ID = "RobotNotice10", Name = "恭喜[%1%]在免费抽奖中鸿运当头，抽中话费券2元！"}
	self.datas["RobotNotice11"] = {ID = "RobotNotice11", Name = "恭喜[%1%]在免费抽奖中鸿运当头，抽中话费券5元！"}
	self.datas["RobotNotice12"] = {ID = "RobotNotice12", Name = "恭喜[%1%]在免费抽奖中鸿运当头，抽中话费券2元！"}
	self.datas["ExchangeTelCharge"] = {ID = "ExchangeTelCharge", Name = "恭喜玩家[%1%]成功兑换了30元话费！"}
	self.datas["AutoRegister"] = {ID = "AutoRegister", Name = "正在自动注册帐号……"}
	self.datas["TenThousand"] = {ID = "TenThousand", Name = "万"}
	self.datas["SendGiftLimitTip"] = {ID = "SendGiftLimitTip", Name = "所持金币必须大于%d万才可以进行送礼！"}
	self.datas["ConfirmPayment"] = {ID = "ConfirmPayment", Name = "充值确认中，请稍候……"}
	self.datas["PriceRMBText"] = {ID = "PriceRMBText", Name = "价格：%d元"}
	self.datas["PriceGemText"] = {ID = "PriceGemText", Name = "价格：%d钻石"}
	self.datas["FirstGiveGold"] = {ID = "FirstGiveGold", Name = "首冲送%d金币"}
	self.datas["GiveGold"] = {ID = "GiveGold", Name = "送%d金币"}
	self.datas["HaveBoughtItem"] = {ID = "HaveBoughtItem", Name = "您已购买这个商品。"}
	self.datas["RechargeHistory"] = {ID = "RechargeHistory", Name = "{fontname=Common2/FZY3JW.TTF,color=0xFFFF0000,fontsize=20}%1%{color=0xFF000000}购买了%2%。"}
	self.datas["UISafeBoxNew_receiverIDStr"] = {ID = "UISafeBoxNew_receiverIDStr", Name = "输入ID       转账收取2%手续费"}
	self.datas["UISafeBoxNew_transferNumStr"] = {ID = "UISafeBoxNew_transferNumStr", Name = "剩余转账金额："}
	self.datas["UISafeBoxNew_oldPassWordStr"] = {ID = "UISafeBoxNew_oldPassWordStr", Name = "请输入原银行密码"}
	self.datas["UISafeBoxNew_newPassWordStr"] = {ID = "UISafeBoxNew_newPassWordStr", Name = "请输入6-20位新密码"}
	self.datas["UISafeBoxNew_againPassWordStr"] = {ID = "UISafeBoxNew_againPassWordStr", Name = "请再输入一次新密码"}
	self.datas["UISafeBoxNewReminder_passWordStr"] = {ID = "UISafeBoxNewReminder_passWordStr", Name = "输入银行密码"}
	self.datas["RoomEnterLimit"] = {ID = "RoomEnterLimit", Name = "最低带入:%s"}
	self.datas["transferDtailsStringFormat"] = {ID = "transferDtailsStringFormat", Name = "赠送人用户名：%s赠送人ID：%s接收人用户名：%s接收人ID：%s赠送金额：%s大写：%s赠送日期：%s"}
	self.datas["TransferAffirmDesc"] = {ID = "TransferAffirmDesc", Name = "请确认转账给用户ID为：%d，昵称为：%s，金币：%d"}
	self.datas["GoldIsNotEnough"] = {ID = "GoldIsNotEnough", Name = "金币不足"}
	self.datas["TicketIsNotEnough"] = {ID = "TicketIsNotEnough", Name = "钻石不足"}
	self.datas["FindNotGame"] = {ID = "FindNotGame", Name = "游戏正在维护中，请稍后重试。"}
	self.datas["CowsGoldNotEnough"] = {ID = "CowsGoldNotEnough", Name = "亲，您当前所持有的金币不足以赔付本次下注，充值能获得充足的金币哦"}
	self.datas["RelieveSuccess"] = {ID = "RelieveSuccess", Name = "解绑成功"}
	self.datas["FishLevelEnough"] = {ID = "FishLevelEnough", Name = "需要捕鱼等级%s"}
	self.datas["FishGoldEnough"] = {ID = "FishGoldEnough", Name = "需要金币%s万"}
	self.datas["Player_AutoEnter"] = {ID = "Player_AutoEnter", Name = "捕鱼等级过低，自动进入低等级房间。"}
	self.datas["FishLevelInfo"] = {ID = "FishLevelInfo", Name = "捕鱼等级%s"}
end

M_MultiLanguageCFG:init()
