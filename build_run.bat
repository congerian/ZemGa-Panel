
cd ./conan && call "./setup_conan.bat" && ^
cd ../ && ^
if not exist ".\build\" mkdir ".\build\" && ^ 
cd ./build/ && cmake ../ -G Ninja && ^
ninja -j 16 && ^
cls && ^
echo off && ^
cd "..\bin\win32\release" && "Test.exe" && ^
echo on
PAUSE