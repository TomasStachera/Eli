#Application 1 
#This application will explain how to use EliLib library
#for creating own consolle application
#Tomas Stachera  email:tomas.stachera@gmail.com
cmake_minimum_required (VERSION 2.6)
project(App1)
SET (VERSION_MAJOR 1)
SET (VERSION_MINOR 0)

# Set aplication files
SET (TARGET_main_FILES
${PROJECT_SOURCE_DIR}/main.cpp)

add_executable(App1 ${TARGET_main_FILES})
#EliLib library must be linked
target_link_libraries(App1 EliLib)

#Set OS macro according your OS __WXMSW__ for Windows
#                               __UNIX__  for Linux
IF (WIN32)
target_compile_definitions(App1 PUBLIC -D__WXMSW__)
ELSE()
target_compile_definitions(App1 PUBLIC -D__UNIX__)
ENDIF(WIN32)






