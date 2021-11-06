file(GLOB SOURCE_FILES "Edict.cpp" "JMdict.cpp" "Kanjidic.cpp" "NewKanjidic.cpp")

#find_library(PugiXML NAMES pugixml REQUIRED)

add_library(Parsers SHARED ${SOURCE_FILES})

target_link_libraries(Parsers ${PugiXML})