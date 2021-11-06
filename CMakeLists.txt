cmake_minimum_required(VERSION 3.20.5)

project(AmeKanji)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED)

# Get PugiXML from Github
include(FetchContent)
FetchContent_Populate(
    pugixml

    GIT_REPOSITORY https://github.com/zeux/pugixml.git
    SOURCE_DIR libs/PugiXML
)

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/libs/PugiXML)

include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_BINARY_DIR}/libs/PugiXML/src)

set(PugiXML pugixml)

add_subdirectory(src)
add_subdirectory(tests)
