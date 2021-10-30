set(SOURCE_FILES AmeWeb.cpp)

find_library(LibCURL NAMES curl REQUIRED)

add_library(AmeWeb ${SOURCE_FILES})

target_link_libraries(AmeWeb ${LibCURL})