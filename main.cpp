#include "alpi/linked_list/linked_list.hpp"
#include <initializer_list>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <forward_list>
int main(int, char **) {

  alpi::linked_list<int> lt{1,2,3,4};
  alpi::linked_list<int> lt2{5,6,7,8,9};

    //lt2.insert_after(lt2.begin(),3);
    lt2.merge(lt);

    for(auto x = lt.begin(); x != lt.end(); x++){
        std::cout << *x << "\n";
    }
}
