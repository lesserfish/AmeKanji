file(GLOB SOURCE_FILES "Ame.cpp" "AmeLoad.cpp")

add_subdirectory(Jisho)
add_subdirectory(Web)
add_subdirectory(Cards)

include_directories(../Core)

#find_library(PugiXML NAMES pugixml REQUIRED)

add_library(Ame SHARED ${SOURCE_FILES})

target_link_libraries(Ame Core Jisho Cards ${pugiXML})