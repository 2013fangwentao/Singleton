cmake_minimum_required(VERSION 2.8)
project(Singleton)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")
include_directories( ${PROJECT_SOURCE_DIR}/include )
add_definitions(-std=c++11)

add_library( ConfigInfo SHARED ./src/Single.cpp)

add_executable(${PROJECT_NAME} ./test/testSingle.cpp)
target_link_libraries(${PROJECT_NAME} ConfigInfo)