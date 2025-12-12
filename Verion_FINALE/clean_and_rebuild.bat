@echo off
echo ================================================
echo Cleaning Qt Project Build Files
echo ================================================

echo Deleting Makefiles...
if exist Makefile del /F /Q Makefile
if exist Makefile.Debug del /F /Q Makefile.Debug
if exist Makefile.Release del /F /Q Makefile.Release
if exist .qmake.stash del /F /Q .qmake.stash

echo Deleting debug and release folders...
if exist debug rmdir /S /Q debug
if exist release rmdir /S /Q release

echo.
echo ================================================
echo Running qmake to regenerate Makefiles...
echo ================================================
C:\Qt\6.7.3\mingw_64\bin\qmake.exe Version_F.pro

echo.
echo ================================================
echo Clean Complete!
echo ================================================
echo.
echo Now you can build in Qt Creator:
echo   Build -^> Build All
echo.
echo Or run: mingw32-make
echo.
pause
