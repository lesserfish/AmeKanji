set(SOURCE_FILES main.cpp)

add_subdirectory(Core)
add_subdirectory(Ame)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} Core Ame Regex)