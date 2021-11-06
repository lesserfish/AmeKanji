include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

find_library(PugiXML NAMES pugixml REQUIRED)

set(SOURCE_FILES test_template.cpp test_librarian.cpp test_eventchain.cpp test_regex.cpp)
add_executable(TEST ${SOURCE_FILES})

target_link_libraries(TEST gtest_main Ame Core ${PugiXML})

include(GoogleTest)
gtest_discover_tests(TEST WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/tests)