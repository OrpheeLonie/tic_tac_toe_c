cmake_minimum_required(VERSION 3.14)
project(tic_tac_toe)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
    tic_tac_toe
    main.cc
    # src/state.hh
    src/tic_tac_toe.cc
    # src/tic_tac_toe.hh
)

enable_testing()

add_executable(
    ttt_test
    test/ttt_test.cc
)
target_link_libraries(
    ttt_test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ttt_test)

