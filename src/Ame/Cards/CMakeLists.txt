file(GLOB SOURCE_FILES "Kanji.cpp" "Word.cpp")

add_library(Cards SHARED ${SOURCE_FILES})