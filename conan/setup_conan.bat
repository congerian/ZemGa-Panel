if not exist ".\temp\" mkdir ".\temp\" 
cd ".\temp\"
conan install .. --build=missing
cd "..\"