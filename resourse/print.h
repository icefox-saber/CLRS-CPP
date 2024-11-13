#ifndef print_h
#define print_h

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(vector<T> &vec)
{
    for (size_t i = 0; i < vec.size();i++)
    {
        cout << vec[i] << ' ';
    }
    cout << endl;
};

#endif