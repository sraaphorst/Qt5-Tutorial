# From: http://zetcode.com/gui/qt5

cmake_minimum_required(VERSION 3.10)
project(qtplay VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# Find includes in corresponding build directories.
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# see https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

set (CMAKE_PREFIX_PATH "/Applications/Qt-5.9.4/5.9.4/clang_64/lib/cmake/Qt5")
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

#set (CMAKE_PREFIX_PATH "/Applications/Qt/5.10.1/clang_64/lib/cmake/Qt5Widgets")
#set(Qt5Widgets_DIR "/Applications/Qt/5.10.1/clang_64/lib/cmake/Qt5Widgets" CACHE PATH "")
#find_package(Qt5Widgets REQUIRED)

add_subdirectory(1_introduction)
add_subdirectory(2_strings)
add_subdirectory(3_date_and_time)
add_subdirectory(4_containers)
add_subdirectory(5_files_and_directories)
add_subdirectory(6_first_programs)
add_subdirectory(7_menus_and_toolbars)
add_subdirectory(8_layout_management)
add_subdirectory(Extras)