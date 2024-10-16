#include "alpi/linked_list/linked_list.hpp"
#include <iterator>
#include <gtest/gtest.h>
// Demonstrate some basic assertaions.
TEST(linkedlistTest, InitialIterator) {
  alpi::linked_list<int> lt{};
  EXPECT_EQ(lt.begin(), lt.end());
}

TEST(linkedlistTest, InitialIteratorAndIncerement) {
  alpi::linked_list<int> lt{};
  EXPECT_EQ(++lt.begin(), ++lt.end());
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
  alpi::linked_list<int> lt{1, 2, 3, 4};
  auto it = lt.begin();
  it++; // 2
  it++; // 3
  EXPECT_EQ(*it, 3);
}

TEST(linkedlistTest, CopyOperator) {
  alpi::linked_list<int> lt2{1,5,6};
  alpi::linked_list<int> lt{lt2};
  auto begin_before_copy = lt.begin();
  lt = lt2;
  auto begin_after_copy = lt.begin();
  EXPECT_EQ(*(begin_after_copy),*(lt2.begin()));
  EXPECT_NE(begin_before_copy, begin_after_copy);
}

TEST(linkedlistTest, CopyAssignment) {
  alpi::linked_list<int> lt{1,5,6};
  alpi::linked_list<int> lt2{2,3,4};
  auto begin_before_copy = lt.begin();
  lt = lt2;
  auto begin_after_copy = lt.begin();
  EXPECT_EQ(*(begin_after_copy),*(lt2.begin()));
  EXPECT_NE(begin_before_copy,begin_after_copy);
}

template <typename T> bool IsInAscendingOrder(const alpi::linked_list<T> lt) {

  auto cur = lt.begin();
  auto next = ++cur;

  while (next != lt.end()) {
    if (*cur > *next) {
      return false;
    }
    cur++;
    next++;
  }
  return true;
}

TEST(linkedlistTest, MergeTwoOrderedListByAscendingOrder) {
  alpi::linked_list<int> lt{1, 2, 3, 4};
  alpi::linked_list<int> lt2{5, 6, 7, 8, 9};
  lt.merge(lt2);
  EXPECT_PRED1(IsInAscendingOrder<int>, lt);
}