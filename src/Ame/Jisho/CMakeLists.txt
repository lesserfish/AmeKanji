set(SOURCE_FILES Jisho.cpp)

find_library(PugiXML NAMES pugixml REQUIRED)

add_library(Jisho ${SOURCE_FILES})

target_link_libraries(Jisho ${pugiXML})