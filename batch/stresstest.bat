@echo off
set name=bai1
for /l %%i in (1, 1, 111111) do (
    gen.exe>%name%.inp
    sol.exe
    brute.exe>%name%.ans<%name%.inp
    fc %name%.ans %name%.out ||break
)
type %name%.ans
pause
