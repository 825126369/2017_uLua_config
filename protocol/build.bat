@echo off
set PROTO_FILE=proto 
cd proto

for /f "delims=" %%a in ('dir /b/a-d/oN *.proto') do (
echo %%a
"../protoc.exe" --cpp_out=./ %%a
"../protoc.exe" --plugin=protoc-gen-lua="..\protoc-gen-lua\protoc-gen-lua.bat" --lua_out=./ %%a
)

cd ..\
for /r %PROTO_FILE% %%i in (*.lua) do (
	XCOPY  %%i client\  /r /h /c /e /y
)
for /r %PROTO_FILE% %%i in (*.h *.cc) do (
	XCOPY  %%i server\  /r /h /c /e /y
)

for /r %PROTO_FILE% %%i in (*.lua *h *.cc) do (
	del  %%i
)
pause