file(GLOB SOURCE_FILES "ArgsParser.cpp" "ConfigParser.cpp")

find_library(PugiXML NAMES pugixml REQUIRED)

add_library(Core SHARED ${SOURCE_FILES})
