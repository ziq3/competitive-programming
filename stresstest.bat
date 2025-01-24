@echo off
set name=bai1
for %%f in (*.cpp) do (
    g++ -std=c++20 -D_GLIBCXX_DEBUG %%f -o %%~nf.exe
)
for /l %%i in (1, 1, 111111) do (
    gen>%name%.inp
    sol>%name%.out<%name%.inp
    brute>%name%.ans<%name%.inp
    fc %name%.ans %name%.out ||exit /b
)
