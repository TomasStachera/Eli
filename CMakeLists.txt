#Eli SW in cmake
#Tomas Stachera
cmake_minimum_required (VERSION 2.6)
project(Eli)
SET (VERSION_MAJOR 1)
SET (VERSION_MINOR 0)
# Create shared library
SET(ELI_LIB OFF CACHE BOOL "Create eli lib?")
#Create gui application
SET(ELI_GUI ON CACHE BOOL "Create eli gui?")
if(WIN32)
# Set installation directory for Windows
SET(INSTAL_DIR ${PROJECT_SOURCE_DIR}/install)
else()
# Set instalation directory for Linux
SET(INSTAL_DIR /usr/local/Eli)
ENDIF()
# Declare wxWidgets directory
IF(WIN32)
SET(wxWidgets_ROOT_DIR C:/prog_linux/wx)
SET(wxWidgets_LIB_DIR C:/prog_linux/wx/lib/gcc_dll)
SET(wxWidgets_LIBRARIES C:/prog_linux/wx/lib/gcc_dll)
SET(wxWidgets_INCLUDE_DIRS C:/prog_linux/wx/include)
ENDIF()
# At least one option must be selected
if((NOT ELI_LIB) AND (NOT ELI_GUI))
 message( FATAL_ERROR "At least one of ELI_LIB or ELI_GUI must be selected")
ENDIF()
IF(WIN32)
SET(wxWidgets_CONFIGURATION mswu)
ENDIF()
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
# Set gui aplication files
SET (TARGET_main_FILES
${PROJECT_SOURCE_DIR}/src/eliApp.cpp
  ${PROJECT_SOURCE_DIR}/src/eliMain.cpp
 ${PROJECT_SOURCE_DIR}/src/CameraCalibration.cpp
${PROJECT_SOURCE_DIR}/src/CameraProperties.cpp
 ${PROJECT_SOURCE_DIR}/src/commands_main.cpp
  ${PROJECT_SOURCE_DIR}/src/commands1.cpp
 ${PROJECT_SOURCE_DIR}/src/commands2.cpp
  ${PROJECT_SOURCE_DIR}/src/commands3.cpp
  ${PROJECT_SOURCE_DIR}/src/ContourDescript.cpp
  ${PROJECT_SOURCE_DIR}/src/ContourDescript2.cpp
  ${PROJECT_SOURCE_DIR}/src/ContourDescript3.cpp
  ${PROJECT_SOURCE_DIR}/src/ContourDescript4.cpp
 ${PROJECT_SOURCE_DIR}/src/editPicture.cpp
 ${PROJECT_SOURCE_DIR}/src/MaskPictureEdit.cpp
  ${PROJECT_SOURCE_DIR}/src/LoopDialog.cpp
 ${PROJECT_SOURCE_DIR}/src/ExportParam.cpp
 ${PROJECT_SOURCE_DIR}/src/VariableWindow.cpp
${PROJECT_SOURCE_DIR}/src/LOGMES.cpp
  ${PROJECT_SOURCE_DIR}/src/resource.rc )

 # Set export library files
 SET( LIBRARY_MAIN_FILES
  ${PROJECT_SOURCE_DIR}/src/libmain.cpp
 ${PROJECT_SOURCE_DIR}/src/commands_main.cpp
  ${PROJECT_SOURCE_DIR}/src/commands1.cpp
 ${PROJECT_SOURCE_DIR}/src/commands2.cpp
  ${PROJECT_SOURCE_DIR}/src/commands3.cpp
  ${PROJECT_SOURCE_DIR}/src/ContourDescript3.cpp
  ${PROJECT_SOURCE_DIR}/src/CameraCalibration.cpp
 )

SET(wxWidgets_USE_LIBS)
IF(ELI_LIB)
add_definitions(-DELI_SHARED_LIB)
ENDIF(ELI_LIB)
find_package(wxWidgets REQUIRED net core base adv html)
find_package( OpenCV REQUIRED )
include(${wxWidgets_USE_FILE})
if(ELI_GUI)
IF (WIN32)
add_executable(Eli WIN32 ${TARGET_main_FILES})
ELSE()
add_executable(Eli ${TARGET_main_FILES})
ENDIF(WIN32)
target_link_libraries(Eli ${wxWidgets_LIBRARIES} ${OpenCV_LIBS} )
ENDIF(ELI_GUI)
IF(ELI_LIB)
 ADD_LIBRARY(EliLib SHARED ${LIBRARY_MAIN_FILES})
 target_link_libraries(EliLib ${wxWidgets_LIBRARIES} ${OpenCV_LIBS} )
ENDIF(ELI_LIB)

install(TARGETS Eli DESTINATION ${INSTAL_DIR})
install(DIRECTORY icons/ DESTINATION ${INSTAL_DIR}/icons)
install(DIRECTORY help/ DESTINATION ${INSTAL_DIR}/help)
