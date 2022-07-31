cd ./conan && call "./setup_conan.bat" && ^
cd ../ && ^
if not exist ".\build\" mkdir ".\build\" && ^ 
cd ./build && ^
cmake ../ -G Ninja && ^
ninja -j 16