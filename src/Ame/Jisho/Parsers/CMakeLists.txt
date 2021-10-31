set(SOURCE_FILES Dictionary.cpp Edict.cpp JMdict.cpp Kanjidic.cpp NewKanjidic.cpp)

find_library(PugiXML NAMES pugixml REQUIRED)

add_library(Parsers ${SOURCE_FILES})

target_link_libraries(Parsers ${PugiXML})