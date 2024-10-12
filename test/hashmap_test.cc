#include "alpi/hash_map/hash_map.hpp"
#include "gtest/gtest.h"
#include <algorithm>
#include <cstdlib>

TEST(HashMapTest, InsertElement){
    std::array<std::pair<int,int>,5> key_value;
    std::srand(std::time(nullptr));
    std::transform(key_value.begin(),key_value.end(),key_value.begin(),
        [](std::pair<int,int> x){
            return std::pair<int,int>{std::rand(),std::rand()};
        });
    alpi::hash_map<int,int> hmap{};
    std::for_each(key_value.begin(),key_value.end(),[&](const std::pair<int,int> k_v){
        hmap.insert(k_v.first,k_v.second);
    });
    std::for_each(key_value.begin(),key_value.end(),[&](const std::pair<int,int> k_v){
        EXPECT_EQ(hmap[k_v.first],k_v.second);
    });
}