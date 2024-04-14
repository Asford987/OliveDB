cmake_minimum_required(VERSION 3.28.3)

project(OliveDB)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

file(GLOB CMAKE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/CMake/*.cmake)

foreach(CMAKE_FILE ${CMAKE_FILES})
    include(${CMAKE_FILE})
endforeach()
