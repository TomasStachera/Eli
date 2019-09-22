#Application 1 
#This application will explain how to use EliLib library
#for creating own consolle application
#Tomas Stachera  email:tomas.stachera@gmail.com
cmake_minimum_required (VERSION 2.6)
project(wxGuiApp2)
SET (VERSION_MAJOR 1)
SET (VERSION_MINOR 0)

# Declare wxWidgets directory
IF(WIN32)
SET(wxWidgets_ROOT_DIR C:/prog_linux/wx64)
SET(wxWidgets_LIB_DIR C:/prog_linux/wx64/lib/gcc_dll)
SET(wxWidgets_LIBRARIES C:/prog_linux/wx64/lib/gcc_dll)
SET(wxWidgets_INCLUDE_DIRS C:/prog_linux/wx64/include)
ENDIF()

IF(WIN32)
SET(wxWidgets_CONFIGURATION mswu)
ENDIF()
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

# Set aplication files
SET (TARGET_main_FILES
${PROJECT_SOURCE_DIR}/src/gui_applicationApp.cpp
${PROJECT_SOURCE_DIR}/src/gui_applicationMain.cpp)

SET(wxWidgets_USE_LIBS)

find_package(wxWidgets REQUIRED net core base adv html)
find_package( OpenCV REQUIRED )
include(${wxWidgets_USE_FILE})

IF (WIN32)
add_executable(wxGuiApp2 WIN32 ${TARGET_main_FILES})
ELSE()
add_executable(wxGuiApp2 ${TARGET_main_FILES})
ENDIF(WIN32)

#EliLibwx library must be linked
target_link_libraries(wxGuiApp2 ${wxWidgets_LIBRARIES} ${OpenCV_LIBS} EliLibwx)


target_compile_definitions(wxGuiApp2 PUBLIC -DELI_WITH_WXWIDGETS -DELI_WITH_OPENCV)







