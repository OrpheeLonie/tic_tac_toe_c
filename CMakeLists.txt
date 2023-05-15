cmake_minimum_required(VERSION 3.14)
project(tic_tac_toe)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Werror -pedantic)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(source_files
    src/tic_tac_toe.cc)

add_executable(
    tic_tac_toe
    main.cc
    ${source_files}
)

enable_testing()

add_executable(
    ttt_test
    test/ttt_test.cc
    ${source_files}
)
target_link_libraries(
    ttt_test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ttt_test)

