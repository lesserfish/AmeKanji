# Get PugiXML from Github

find_library(pugixml pugixml)

if(NOT pugixml)
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
endif()
set(PugiXML pugixml)

# Get libCurl


find_library(curl curl)

if(NOT curl)
    include(FetchContent)
    FetchContent_Populate(
        curl

        GIT_REPOSITORY https://github.com/curl/curl.git
        GIT_TAG c7aef0a945f9b6fb6d3f91716a21dfe2f4ea635f
        SOURCE_DIR external_libs/Curl
        BINARY_DIR external_bin/Curl
        SUBBUILD_DIR external_sub/Curl
    )

    add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/external_libs/Curl)
    link_directories(${PROJECT_NAME} ${CMAKE_CURRENT_BINARY_DIR}/external_libs/Curl/libs/)
    include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_BINARY_DIR}/external_libs/Curl/include)
endif()
set(Curl libcurl)
