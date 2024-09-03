#pragma once

#include<list>
#include<vector>
#include<cmath>
#include "alpi/linked_list/linked_list.hpp"

namespace alpi
{
    static constexpr float LIMIT_LOAD_FACTOR = 1.0;

    class nextPrimeNumber {
        bool IsPrime(const size_t& number){
            if (number == 1){
                return false;
            }
            auto upper_dividend{number-1};
            for (size_t i = 2; i <= upper_dividend ;i++){
                if (IsPrime(i) && (number % i == 0) ){
                    return false;
                }
                upper_dividend = ceil((float) number  / (float) i); 
            }
            return true;
        }

        public:
        
        size_t operator()(const size_t& number){
            auto number_l = number;
            while (!IsPrime(number_l)){
                number_l++;
            }
            return number_l; 
        }

    };

    template<typename K,typename V>
    class hash_map
    {
    private:
        using value_type = std::pair<const K, V>;
        using bucket_t = alpi::linked_list<value_type>; 
        std::vector<bucket_t> buckets_;
        u_int bucket_num_{};
        size_t size_{};

        u_int hash(const K& key) {
            return (key % size_);
        }

        bool rehashing() { 
            float load_factor = (float) bucket_num_ / (float) size_;
            if ( load_factor >= LIMIT_LOAD_FACTOR ){
                hash_map<K,V> new_hash_map(nextPrimeNumber{}(size_*2));
                for (auto bucket : buckets_) {
                    for (auto key_value : bucket) {
                        new_hash_map.insert(key_value.first,key_value.second);        
                    }
                }
                *this = std::move(new_hash_map);
                return true;
            }
            return false;
        }

    public:
        hash_map(size_t size = 2) : buckets_(size), size_{size} {}

        //hash_map(std::initializer_list<value_type> pairs) {}
        
        bool remove(const K& key) {return true;}

        bool search(const K& key) {return true;}

        bool insert(const K& key,const V& value) {
            bucket_num_++;
            if (rehashing()){
                std::cout << "rehashing\n";
            }
            auto& bucket = buckets_[hash(key)];
            bucket.add(value_type{key,value});
            return true;    
        }

        V& operator[](const K& key) {
            bucket_t& bucket = buckets_[hash(key)];
            for (value_type& key_value : bucket){
                if (key_value.first == key){
                    return key_value.second;
                }
            }
            std::terminate();
        }

        size_t size() {
            return size_;
        }
    };

} // namespace alpi



//hashing
//resolving hashing collision
//maintaing load factor under limit 
//removing
//inserting
    // check if already present in bucket, no add linked list
    // update size 
    // (rehashing) allocate new portion if load_factor close to limit
    // hash value
//searching
//rehashing
    // cal load_factor with new size
    // if load_factor > 1/2, allocate new buckets
    // insert current elements into new buckets

