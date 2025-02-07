@echo off
set name=bai1
g++ -std=c++20 -D_GLIBCXX_DEBUG gen.cpp -o gen
g++ -std=c++20 -D_GLIBCXX_DEBUG sol.cpp -o sol
g++ -std=c++20 -D_GLIBCXX_DEBUG brute.cpp -o brute
for /l %%i in (1, 1, 111111) do (
    gen>%name%.inp
    sol>%name%.out<%name%.inp
    brute>%name%.ans<%name%.inp
    fc %name%.ans %name%.out ||exit /b
)
