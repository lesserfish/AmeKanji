file(GLOB SOURCE_FILES "Library.cpp" "Dictionary.cpp")

add_subdirectory(Parsers)

add_library(Jisho SHARED ${SOURCE_FILES})

target_link_libraries(Jisho Parsers)