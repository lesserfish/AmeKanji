cmake_minimum_required(VERSION 3.20.5)

project(AmeKanji)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED)

include(external/external_libs.cmake)

add_subdirectory(src)
add_subdirectory(tests)
