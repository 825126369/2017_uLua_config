ExeclExport.exe auto
mkdir ..\..\Client\GameData_HappySupremacy\src

::FileCompare.exe .\Xml ..\..\Client\Fish_GameData\res\
::FileCompare.exe .\Code\Client ..\..\Client\frameworks\runtime-src\Classes\CrocodileGame

copy Lua\HappySupremacy_RoomCFG.lua ..\..\Client\GameData_HappySupremacy\src\config
copy Lua\HappySupremacy_BaseCFG.lua ..\..\Client\GameData_HappySupremacy\src\config
copy Lua\HappySupremacy_MultiLanguageCFG.lua ..\..\Client\GameData_HappySupremacy\src\config
copy Lua\HappySupremacy_SoundCFG.lua ..\..\Client\GameData_HappySupremacy\src\config
copy Lua\HappySupremacy_BetMaxCFG.lua ..\..\Client\GameData_HappySupremacy\src\config

@echo off
if "%nopause%" == "true" (@echo on) else (pause)
