cmake_minimum_required(VERSION 3.12)
project(gtk1)

set(CMAKE_CXX_STANDARD 17)

# Use the package PkgConfig to detect GTK+ headers/library files

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0 )

link_directories(
        ${GTKMM_LIBRARY_DIRS} )

include_directories(
        ${GTKMM_INCLUDE_DIRS} )

set (SRC
        main.cpp
        #Vos sources
        Led.cpp Led.h LedController.cpp LedController.h)

add_executable(gtk1
        ${SRC} )

target_link_libraries(gtk1
        ${GTKMM_LIBRARIES} pthread)