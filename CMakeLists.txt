cmake_minimum_required(VERSION 3.27)
project(pricing_app_updater)

set(CMAKE_CXX_STANDARD 17)

add_executable(pricing_app_updater main.cpp)

# set the exe output directory
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
# set the debug output directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/obj)
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "-debug")
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "updater-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}")
# include the necessary libraries
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -static -lpthread -s -Os")
# Disable the console from opening on windows
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-mwindows")
