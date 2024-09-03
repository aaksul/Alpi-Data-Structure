#include "alpi/hash_map/hash_map.hpp"
#include "gtest/gtest.h"

TEST(HashMapTest, InsertOneElement){
    alpi::hash_map<int,int> hmap;
    hmap.insert(2,4);
    EXPECT_EQ(hmap[2],4);
}