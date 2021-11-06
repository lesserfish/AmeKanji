file(GLOB SOURCE_FILES "Ame.cpp" "AmeLoad.cpp")

add_subdirectory(Jisho)
add_subdirectory(Web)
add_subdirectory(Cards)

include_directories(../Core)

add_library(Ame SHARED ${SOURCE_FILES})

target_link_libraries(Ame Core Jisho Cards ${pugiXML})