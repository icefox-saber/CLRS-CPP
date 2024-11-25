#include "minimum.h"
#include <iostream>

int main()
{
    std::vector<int> v={4,10,6,9,2,9,7,8,4};

    std::cout<<"min:"<<CLRS::min(v)<<std::endl;
}