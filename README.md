# Eli
![Eli Logo](/share/Eli/icons/eli_icon.png)
## Computer vission application for simple detection objects on camera, video or picture.
Eli application consist from:
* **GUI application:**
User can easy create own program. This program can be executed, debugging and checking.
* **Library:**
Library can executed .eli program with user application
## 
![Screenshot Logo](/share/Eli/help/pictures/screenshot_1.png)
### OS support
Aplication works on Windows and Linux platforms. Application is written in C++.
### Requirements for compilation from source code
* **Cmake:** Version 2.6 or higher
* **C++ compiler**
* **wxWidgets:** [wxWidgets](https://www.wxwidgets.org)
* **OpenCV:** [OpenCv](https://opencv.org/)
* **NSIS (Only for windows):** [NSIS](https://sourceforge.net/projects/nsis/)
### Compilation instructions
#### Windows
* Install Cmake
* Install wxWidgets
* Install OpenCv
* Instal mingw compiler or other C++ compiler
* Install NSIS for setup package generator
* Open windows terminal
* Clone Eli: **git clone https://github.com/TomasStachera/Eli**
* Go to Eli directory: cd ../Eli
* Open CMakeLists.txt
* Set wxWidgtes instaled directory:
Find part **Declare wxWidgets directory** *and change this directory according your instalation directory*
* Set CPACK generator to **NSIS** *( In the end of CmakeLists)*
* Create build directory: **mkdir build**
* Go to the build directory: **cd build**
* Create directory dlls : **mkdir dlls**. *Copy to this directory all wxWidgtes Dll and all OpenCv dll* (Only if you want to distrubute this application with compiled wxWidgets and OpneCv)
* Stay in directory build
* Run Cmake command (Or use cmake gui):
  * Mingw: **cmake -G "MinGW Makefiles" ..**
* Compile aplication:
  * Mingw: **mingw32-make**
* Compilation create exe application and 2 library files
* Create setup package:
  * Mingw: **mingw32-make package**
* Run Eli setup package for instaling Eli to the system
#### Linux
* Open terminal
* Install Cmake
* Install wxWidgets (wxGtk). Instal from your distribution repositories or from source code
* Install OpenCv. Instal from your distribution repositories or from source code. If you want to use Read/Write video file commands install it with FFMPEG support. Check if your distribution package is compiled with FFMPEG. If not, compile it from source code. You can use also OpenCv CV without FFMPEG support but some types of video file  will not working.Videos in example directory will work also without FFMPEG support.
* Install gcc (g++) compiller
* Clone Eli: **git clone https://github.com/TomasStachera/Eli**
* Go to Eli directory: cd ../Eli
* Open CMakeLists.txt
* Set CPACK generator according your distribution
* Create build directory: **mkdir build**
* Go to the build directory: **cd build**
* Run Cmake command: **cmake ..**
* Compile application: **make**
* Compilation will create executable application and 2 shared library
* Create package: **make package**
* Install package to your system



