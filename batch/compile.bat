@echo off
REM Batch script to compile all C++ files in the current directory and generate executables with the same names
for %%f in (*.cpp) do (
    g++ -std=c++11 -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fno-sanitize-recover -Wl,--stack,66060288 %%f -o %%~nf.exe
)
pause
