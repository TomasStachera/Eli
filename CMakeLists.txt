#Eli SW in cmake
#Tomas Stachera
cmake_minimum_required (VERSION 2.6)
project(Eli)
SET (VERSION_MAJOR 1)
SET (VERSION_MINOR 0)
# Create shared library
SET(ELI_LIB ON CACHE BOOL "Create eli lib?")
#Create gui application
SET(ELI_GUI ON CACHE BOOL "Create eli gui?")

SET(INSTAL_DIR Eli)

# Declare wxWidgets directory
IF(WIN32)
SET(wxWidgets_ROOT_DIR C:/prog_linux/wx64)
SET(wxWidgets_LIB_DIR C:/prog_linux/wx64/lib/gcc_dll)
SET(wxWidgets_LIBRARIES C:/prog_linux/wx64/lib/gcc_dll)
SET(wxWidgets_INCLUDE_DIRS C:/prog_linux/wx64/include)
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
#set_target_properties(Eli PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

ENDIF(ELI_GUI)
IF(ELI_LIB)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
ADD_LIBRARY(EliLib SHARED ${LIBRARY_MAIN_FILES})
target_link_libraries(EliLib ${wxWidgets_LIBRARIES} ${OpenCV_LIBS} )
target_compile_definitions(EliLib PUBLIC -DELI_SHARED_LIB)

ADD_LIBRARY(EliLibwx SHARED ${LIBRARY_MAIN_FILES})
target_link_libraries(EliLibwx ${wxWidgets_LIBRARIES} ${OpenCV_LIBS} )
target_compile_definitions(EliLibwx PUBLIC -DELI_SHARED_LIB -DELI_SHARED_WITHWX)
ENDIF(ELI_LIB)

#Set instalation directory for CPACK

install(TARGETS Eli EliLib EliLibwx RUNTIME DESTINATION bin 
                                    LIBRARY DESTINATION lib)
install(DIRECTORY share/Eli/icons/ DESTINATION share/Eli/icons)
install(DIRECTORY share/Eli/help/ DESTINATION share/Eli/help)
install(DIRECTORY share/Eli/calibration/ DESTINATION share/Eli/calibration)
if(WIN32)
install(DIRECTORY build/dlls/ DESTINATION bin)
install(FILES build/libEliLib.dll.a DESTINATION bin)
install(FILES build/libEliLibwx.dll.a DESTINATION bin)
ENDIF(WIN32)
install(FILES include/EliLib.h DESTINATION include)


set(CPACK_PACKAGE_NAME "Eli")
set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
set(CPACK_PACKAGE_EXECUTABLES
  "Eli" "Eli"
)
set(CPACK_CREATE_DESKTOP_LINKS "Eli")
set(CPACK_NSIS_MODIFY_PATH "ON")
#Set CPACK generator RPM for Fedora
#Set CPACK generator NSIS for Windows
#Set CPACK generator DEB for debian and Ubuntu
#if DEB package will be used add follow line
#set(CPACK_DEBIAN_PACKAGE_MAINTAINER "My")
set(CPACK_GENERATOR "RPM")
set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${VERSION_MAJOR}.${VERSION_MINOR}")

include(CPack)

