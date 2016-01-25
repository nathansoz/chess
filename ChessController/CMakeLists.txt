cmake_minimum_required(VERSION 3.2)
project(ChessController)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(PROJECT_INCLUDE_DIR include)


file(GLOB SOURCES src/*.cpp)
include_directories("${PROJECT_INCLUDE_DIR}")

add_library(${PROJECT_NAME} SHARED ${SOURCES})