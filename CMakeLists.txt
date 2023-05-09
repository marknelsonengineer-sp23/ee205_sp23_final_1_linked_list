
cmake_minimum_required(VERSION 3.26)

project(ee205_sp23_final_1_linked_list
      VERSION 1.0
      DESCRIPTION "EE 205 - Spr 2023 - Final Exam 1 - Linked List"
      LANGUAGES CXX)

message(STATUS "CMAKE_SOURCE_DIR = [${CMAKE_SOURCE_DIR}]")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

set (Boost_USE_STATIC_LIBS OFF)

find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

if (Boost_UNIT_TEST_FRAMEWORK_FOUND)
   message(STATUS "Generating unit tests using BOOST Unit Test Framework")

   add_executable ( All_Boost_Tests test_Final.cpp Node.h List.cpp List.h)
   target_link_libraries (All_Boost_Tests ${Boost_LIBRARIES})

else (Boost_UNIT_TEST_FRAMEWORK_FOUND)
   message("BOOST Test needs to be installed to do unit testing")
endif (Boost_UNIT_TEST_FRAMEWORK_FOUND)

add_executable(ee205_sp23_final_1_linked_list main.cpp Node.h List.cpp List.h)
