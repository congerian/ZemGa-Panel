mkdir .\build\
cd ./build && ^
cmake ../ -G Ninja && ^
ninja -j 16
PAUSE