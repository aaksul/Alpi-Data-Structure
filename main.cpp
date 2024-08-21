#include "alpi/linked_list/linked_list.hpp"
#include <initializer_list>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <forward_list>
int main(int, char **) {

    alpi::linked_list<int> lt{1,3,5};
    alpi::linked_list<int> lt2{2,4};

    //lt2.insert_after(lt2.begin(),3);
    //lt2.merge(lt.begin());
}
