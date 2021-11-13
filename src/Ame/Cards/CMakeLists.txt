file(GLOB SOURCE_FILES "Kanji.cpp" "Word.cpp" "Default.cpp")

add_subdirectory(Template)
add_subdirectory(Deck)

add_library(Cards SHARED ${SOURCE_FILES})

target_link_libraries(Cards Templates Deck)