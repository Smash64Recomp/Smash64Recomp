@echo off
echo Building Smash64 Recomp...
cmake --build out/build/x64-Debug --config Debug
if %ERRORLEVEL% NEQ 0 (
    echo Build failed!
    pause
    exit /b 1
)

echo Build successful! Running with console...
cd out\build\x64-Debug
Smash64Recompiled.exe --show-console
pause
