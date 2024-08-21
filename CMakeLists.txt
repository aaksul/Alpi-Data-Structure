cmake_minimum_required(VERSION 3.6.0)
project(DataStructureWS VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wpedantic)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)
add_executable(DataStructureWS main.cpp)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()