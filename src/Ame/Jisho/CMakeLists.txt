set(SOURCE_FILES Library.cpp)

add_subdirectory(Parsers)


add_library(Jisho ${SOURCE_FILES})

target_link_libraries(Jisho Parsers)