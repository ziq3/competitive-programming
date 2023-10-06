@echo off
set name=bai1
for /l %%i in (1,1,2) do (
    copy %name%_%%i.inp %name%.inp
    sol.exe
    fc %name%.out %name%_%%i.ans || break
)