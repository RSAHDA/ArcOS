cmake_minimum_required(VERSION 3.21)
project(ArcOS)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(computation-module)
include_directories(computation-module/modules)

add_executable(ArcOS
        computation-module/modules/file_system.h
        computation-module/computation-module.ino)
