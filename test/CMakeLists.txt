enable_testing()

add_executable(
  tests
  hashmap_test.cc
  linkedlist_test.cc
)

target_link_libraries(
  tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)