rmdir /s/q Code
rmdir /s/q Xml
rmdir /s/q Lua
del CFG.check
ExeclExport.exe auto
mkdir ..\..\Client\GameData\Config\

FileCompare.exe .\Lua ..\..\Client\GameData\Script\Config
FileCompare.exe .\Code\Client ..\..\Client\frameworks\runtime-src\Classes
FileCompare.exe .\Xml ..\Config
FileCompare.exe .\Code\Server ..\..\server\sshare
pause