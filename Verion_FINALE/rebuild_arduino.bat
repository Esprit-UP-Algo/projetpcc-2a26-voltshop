@echo off
echo Cleaning build...
C:\Qt\Tools\llvm-mingw1706_64\bin\mingw32-make.exe -f Makefile.Debug clean

echo Running qmake...
C:\Qt\6.7.3\mingw_64\bin\qmake.exe Version_F.pro

echo Building project...
C:\Qt\Tools\llvm-mingw1706_64\bin\mingw32-make.exe -f Makefile.Debug

echo Build complete!
pause
