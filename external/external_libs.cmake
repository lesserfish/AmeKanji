# Get PugiXML from Github
include(FetchContent)
FetchContent_Populate(
    pugixml

    GIT_REPOSITORY https://github.com/zeux/pugixml.git
    GIT_TAG 08b3433180727ea2f78fe02e860a08471db1e03c
    SOURCE_DIR external_libs/PugiXML
    BINARY_DIR external_bin/PugiXML
    SUBBUILD_DIR external_sub/PugiXML
)

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/external_libs/PugiXML)
include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_BINARY_DIR}/external_libs/PugiXML/src)
set(PugiXML pugixml)
