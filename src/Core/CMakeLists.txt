file(GLOB SOURCE_FILES "ArgsParser.cpp" "ConfigParser.cpp")

add_library(Core SHARED ${SOURCE_FILES})
