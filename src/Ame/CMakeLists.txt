set(SOURCE_FILES Ame.cpp AmeLoad.cpp)

include_directories(../Core)

add_library(Ame ${SOURCE_FILES})

target_link_libraries(Ame Core pugixml)