ExeclExport.exe auto
mkdir ..\..\Client\GameData\src\Config

::FileCompare.exe .\Xml ..\..\Client\GameData\Config\
::FileCompare.exe .\Code\Client ..\..\Client\frameworks\runtime-src\Classes
copy Lua\M_MultiLanguageCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_GameCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_ItemCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_CommodityCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_DialLotteryCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_RecordCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_BaseInfoCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_VIPProfitCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_ExchangeCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_RechangeCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_RechangeExCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_SoundCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_FaceCFG.lua ..\..\Client\GameData\src\config\
copy Lua\SensitiveWordCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_GiftCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_GiftRewardCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_ShieldGame.lua ..\..\Client\GameData\src\config\
copy Lua\M_DailyLoginCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_ActivityCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_ActivityMultiLanguageCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_OnlineRewardCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_FreeLotteryCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_QuestCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_ThirdPluginCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_ChipCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_ShopCFG.lua ..\..\Client\GameData\src\config\
copy Lua\M_FishRoomCFG.lua ..\..\Client\GameData\src\config\
@echo off
if "%nopause%" == "true" (@echo on) else (pause)