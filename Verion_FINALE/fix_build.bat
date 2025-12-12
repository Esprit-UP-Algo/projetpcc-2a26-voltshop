@echo off
echo ================================================
echo FIXING CORRUPTED BUILD
echo ================================================

echo.
echo Step 1: Deleting corrupted exe...
if exist debug\Integration25.exe del /F /Q debug\Integration25.exe
if exist release\Integration25.exe del /F /Q release\Integration25.exe
echo Done!

echo.
echo Step 2: Cleaning build files...
if exist Makefile del /F /Q Makefile
if exist Makefile.Debug del /F /Q Makefile.Debug
if exist Makefile.Release del /F /Q Makefile.Release
if exist .qmake.stash del /F /Q .qmake.stash
echo Done!

echo.
echo Step 3: Deleting all object files...
if exist debug\*.o del /F /Q debug\*.o
if exist release\*.o del /F /Q release\*.o
echo Done!

echo.
echo Step 4: Running qmake...
C:\Qt\6.7.3\mingw_64\bin\qmake.exe Version_F.pro
echo Done!

echo.
echo Step 5: Building with mingw32-make...
mingw32-make clean
mingw32-make

echo.
echo ================================================
echo BUILD COMPLETE!
echo ================================================
echo.
echo Check if Integration25.exe exists in debug folder
echo If successful, run it from there
echo.
pause
