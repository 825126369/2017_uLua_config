ExeclExport.exe auto

FileCompare.exe .\Code\Server ..\..\server\games\game_HappySupremacy

copy Xml\HappySupremacy_BaseCFG.xml ..\Config
copy Xml\HappySupremacy_BetMaxCFG.xml ..\Config
copy Xml\HappySupremacy_RoomCFG.xml ..\Config
copy Xml\HappySupremacy_RobAICFG.xml ..\Config
copy Xml\HappySupremacy_RobCFG.xml ..\Config
copy Xml\HappySupremacy_RoomStockCFG.xml ..\Config
copy Xml\HappySupremacy_RateCFG.xml ..\Config
@echo off
if "%nopause%" == "true" (@echo on) else (pause)
