@echo off
pushd %~dp0\..\
call vendor\premake\premake5.exe --file=Dark-Tools.lua vs2022
popd
PAUSE