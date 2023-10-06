@echo off
REM Batch script to compile all C++ files in the current directory and generate executables with the same names
for %%f in (*.cpp) do (
    g++ -std=c++11 -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fno-sanitize-recover -Wconversion -Wshadow -Wunused-variable -pedantic -Wall -Wextra %%f -o %%~nf.exe
)
pause
