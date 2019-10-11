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
* **wxWidgets:** [wxWidgets](http://www.wxwidgets.org)
* **OpenCV:** [OpenCv](http://opencv.org/)
### Compilation instructions
#### Windows
* Install wxWidgets
* Install OpenCv
* Clone Eli: **git clone https://github.com/TomasStachera/Eli**
* Go to Eli directory: cd ../Eli
* Open CMakeLists.txt
* Set wxWidgtes instaled directory:
Find part **Declare wxWidgets directory** *and change this directory according your instalation directory*
* Set CPACK generator to **NSIS** *( In the end of CmakeLists)*
* Create build directory: **mkdir build**
* Go to the build directory: **cd build**
* Create directory dlls : **mkdir dlls**. *Copy to this directory all wxWidgtes Dll and all OpenCv dll* (Only if you want to distrubute this applicatio with compiled wxWidgets and OpneCv)



