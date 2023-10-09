@echo off
set name=bai1
for /l %%i in (1, 1, 111111) do (
    gen>%name%.inp
    sol
    brute>%name%.ans<%name%.inp
    fc %name%.ans %name%.out ||exit /b
)
type %name%.ans
