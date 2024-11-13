#include <iostream>
#include "binarysearch.h"

int main(int argc, char **argv)
{
    std::vector<int> vec = {0,1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 10;
    int index = binarySearch(vec, target);
    std::cout<<"index:"<<index;

    return 0;
}