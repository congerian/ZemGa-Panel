cd ./conan && call "./setup_conan.bat" && ^
cd ../ && ^
if not exist ".\build\" mkdir ".\build\" && ^ 
cd ./build/ && cmake --build . --target update_translations