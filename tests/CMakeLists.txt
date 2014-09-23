cmake_minimum_required(VERSION 2.6)

# ==== UNIT-TEST CONFIGURATION ====

# Test files must have a ".cpp" suffix.
# Put the name of each file in this list without any path or the suffix.
set(unit_tests
  test_foo
  test_bar
)

# Include directories required for building the tests.
include_directories(
  ${PROJECT_SOURCE_DIR}/include
)

# Libraries the tests are linked against. 
set(unit_test_libs
  ${PROJECT_NAME}
)

# Additional source files with testing utilities and such
set(unit_test_utils
)

# ===== UNIT-TEST MAGIC ====

# Prepare unit-testing with googletest.
# (no `enable_testing(true)` since we add our own test target)
add_custom_target(test)
include_directories(${gtest_SOURCE_DIR}/include ${gmock_SOURCE_DIR}/include)

# Builds each test into an executable and adds them to the `test` target.
foreach(unit_test ${unit_tests})
  add_executable(${unit_test} "${unit_test}.cpp" ${unit_test_utils})
  target_link_libraries(${unit_test} gtest_main gmock ${unit_test_libs})
  add_custom_target(${unit_test}_runtest COMMAND ${unit_test} DEPENDS ${unit_test} WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")
  add_dependencies(test ${unit_test}_runtest)
endforeach(unit_test)


