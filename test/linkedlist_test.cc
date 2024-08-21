#include "alpi/linked_list/linked_list.hpp"
#include <gtest/gtest.h>
// Demonstrate some basic assertaions.
TEST(linkedlistTest, InitialIterator) {
  alpi::linked_list<int> lt{};
  EXPECT_EQ(lt.begin(), lt.end());
}

TEST(linkedlistTest, IteratorAfterElementAdd) {
  alpi::linked_list<int> lt{};
  lt.add(3);
  EXPECT_NE(lt.begin(), lt.end());
}

TEST(linkedlistTest, IteratorIncrement) {
  alpi::linked_list<int> lt{};
  lt.add(3);
  lt.add(5);
  lt.add(1);
  auto it = lt.begin();
  it++; // 2
  it++; // 3
  it++; // end
  EXPECT_EQ(it, lt.end());
}

TEST(linkedlistTest, DereferenceIterator) {
  alpi::linked_list<int> lt{1,2,3,4};
  auto it = lt.begin();
  it++; // 2
  it++; // 3
  EXPECT_EQ(*it,3);
}