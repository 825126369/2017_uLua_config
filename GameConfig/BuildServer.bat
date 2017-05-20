ExeclExport.exe auto
FileCompare.exe .\Xml ..\Config
FileCompare.exe .\Code\Server ..\..\server\sshare
@echo off
if "%nopause%" == "true" (@echo on) else (pause)