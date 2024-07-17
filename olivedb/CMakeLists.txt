cmake_minimum_required(VERSION 3.28.3)

project(OliveDB)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*/*.cpp)
file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*/*.h)


add_library(olivedb ${SRC_FILES})

target_include_directories(olivedb PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/*)



file(GLOB CMAKE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/CMake/*.cmake)

foreach(CMAKE_FILE ${CMAKE_FILES})
    include(${CMAKE_FILE})
endforeach()

find_package(Catch2 REQUIRED HINTS "${PROJECT_SOURCE_DIR}/libs")
include_directories(${PROJECT_SOURCE_DIR}/libs/Catch2/single_include)
# find_package(pybind11 REQUIRED HINTS "${PROJECT_SOURCE_DIR}/libs")
# include_directories()
enable_testing()

add_executable(teste ${PROJECT_SOURCE_DIR}/tests/tests.cpp)
target_link_libraries(teste PRIVATE olivedb Catch2::Catch2)
add_test(NAME teste COMMAND teste)


