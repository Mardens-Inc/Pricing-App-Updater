cmake_minimum_required(VERSION 3.27)
project(pricing_app_updater)

set(CMAKE_CXX_STANDARD 17)

add_executable(pricing_app_updater main.cpp)

# set the exe output directory
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
# set the debug output directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/obj)
#set executable name
set_target_properties(pricing_app_updater PROPERTIES OUTPUT_NAME "updater")