#include "select.h"
#include <iostream>

int main()
{
    std::vector<int> v={4,10,6,9,2,9,7,8,4};

    std::cout<<"select the 3th smallest:"<<CLRS::select(v,4)<<std::endl;
}