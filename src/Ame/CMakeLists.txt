set(SOURCE_FILES Ame.cpp AmeLoad.cpp)

include_directories(../Core)

find_library(PugiXML NAMES pugixml REQUIRED)

add_library(Ame ${SOURCE_FILES})

target_link_libraries(Ame Core ${pugiXML})