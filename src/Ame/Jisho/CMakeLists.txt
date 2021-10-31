set(SOURCE_FILES Dictionary.cpp Library.cpp Vocabdict.cpp Kanjidict.cpp)

add_subdirectory(Regex)

find_library(PugiXML NAMES pugixml REQUIRED)

add_library(Jisho ${SOURCE_FILES})

target_link_libraries(Jisho ${PugiXML})