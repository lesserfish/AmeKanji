file(GLOB SOURCE_FILES "AmeWeb.cpp")

add_library(AmeWeb SHARED ${SOURCE_FILES})

target_link_libraries(AmeWeb ${Curl})