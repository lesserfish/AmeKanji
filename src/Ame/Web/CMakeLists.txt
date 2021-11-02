file(GLOB SOURCE_FILES "AmeWeb.cpp")

find_library(LibCURL NAMES curl REQUIRED)

add_library(AmeWeb SHARED ${SOURCE_FILES})

target_link_libraries(AmeWeb ${LibCURL})