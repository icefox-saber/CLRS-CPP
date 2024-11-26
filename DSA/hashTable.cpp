#include <iostream>
#include "hashTable.h"

int main()
{
    CLRS::hash_table<char,int> hs;
    hs.insert('a',3);
    hs.insert('b',2);
    std::cout<<"a:"<<hs.search('a')->key.second<<std::endl;
    std::cout<<"b:"<<hs.search('b')->key.second<<std::endl;
    hs.remove('a');
    if (! hs.search('a'))
    {
        std::cout<<"no a"<<std::endl;
    }

    return 0;
}