set(SOURCE_FILES Dictionary.cpp Library.cpp JMDict.cpp Kanjidict.cpp)

find_library(PugiXML NAMES pugixml REQUIRED)

add_library(Jisho ${SOURCE_FILES})

target_link_libraries(Jisho ${PugiXML})