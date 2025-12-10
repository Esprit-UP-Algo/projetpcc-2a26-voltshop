Build instructions (friend-ready)

This repository is configured to use an absolute OpenCV path: `C:/OpenCV-VoltShop`.
To reproduce the same working setup on another machine (so the project builds without editing `Version_F.pro`), follow the steps below.

Option 1 — Create a junction (recommended, no copy)
1. Find the full path to the project's OpenCV folder inside the repo, for example:
	`C:\Users\lastg\Desktop\integrationFinal\...\Verion_FINALE\Verion_FINALE\OpenCV-MinGW-Build-OpenCV-4.5.5-x64`
2. In PowerShell run (no admin usually required):

```powershell
cmd /c mklink /J C:\OpenCV-VoltShop "C:\full\path\to\OpenCV-MinGW-Build-OpenCV-4.5.5-x64"
```

3. Build the project from the project root:

```powershell
"C:\Qt\6.7.3\mingw_64\bin\qmake.exe" Version_F.pro
mingw32-make
```

Option 2 — Copy OpenCV into `C:\OpenCV-VoltShop`
1. Copy or mirror the `OpenCV-MinGW-Build-OpenCV-4.5.5-x64` folder to `C:\OpenCV-VoltShop`.
2. Then run `qmake` and `mingw32-make` as above.

Runtime note
- Make sure the OpenCV DLLs from `x64/mingw/bin` are available at runtime: either copy them next to the `.exe` or add that folder to `PATH`.

Why this is needed
- The original project path contains spaces and brackets which can break generated Makefile dependency lines. Using a short no-space path (junction or copy) avoids the "No rule to make target ... cvdef.h" error.

If you want, I can create the junction `C:\OpenCV-VoltShop` on this machine now and run `qmake` + `mingw32-make` for you. Tell me to proceed if you'd like me to build it here.