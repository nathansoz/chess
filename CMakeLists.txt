cmake_minimum_required(VERSION 3.2)
project(chess)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(ChessController)

set(PROJECT_INCLUDE_DIR ChessController/include)
include_directories("${PROJECT_INCLUDE_DIR}")


set(SOURCE_FILES main.cpp)
add_executable(chess ${SOURCE_FILES})
target_link_libraries(chess ChessController)