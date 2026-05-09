cmake_minimum_required(VERSION 3.25)
project(Сalculator LANGUAGES CXX)

enable_testing()

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

add_executable(unit-tests src/Calculator.cpp test/test_calculator.cpp)

target_compile_features(unit-tests PRIVATE cxx_std_17)

#
target_compile_options(unit-tests PRIVATE
  -Wall
  -Wextra
  -Wpedantic
  -Werror
)

target_include_directories(unit-tests PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
 )

target_link_libraries(unit-tests PRIVATE
  GTest::gtest
  GTest::gtest_main
  Threads::Threads
)

add_test(NAME unit_tests COMMAND $<TARGET_FILE:unit-tests>)
