enable_testing()

add_executable(
  linkedlist_test
  linkedlist_test.cc
)
target_link_libraries(
  linkedlist_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(linkedlist_test)