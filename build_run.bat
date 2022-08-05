cd ./conan && call "./setup_conan.bat" && ^
cd ../ && ^
if not exist ".\build\" mkdir ".\build\" && ^ 
cd ./build/ && cmake -S ../ -B . -G Ninja && ^
ninja -j 16 && ^
cls && ^
echo off && ^
cd "..\bin\win32\release" && ".\App.exe" && ^
echo on