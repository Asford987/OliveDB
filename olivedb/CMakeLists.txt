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

# Create a target to run tests
enable_testing()

# Find all test files with the extension ".cpp" in the tests directory
file(GLOB test_files RELATIVE PATH ${PROJECT_SOURCE_DIR}/tests "*.cpp")

# Loop through each test file and create a test target
foreach(test_file ${test_files})
  get_filename_component(test_name ${test_file} NAME_WE)
  add_executable(${test_name} ${PROJECT_SOURCE_DIR}/tests/${test_file})
  target_link_libraries(${test_name} PRIVATE olivedb)
  add_test(NAME ${test_name} COMMAND ${test_name})
endforeach(test_file)

# (Optional) Add a target to run all tests
add_test(NAME all_tests COMMAND make test)

