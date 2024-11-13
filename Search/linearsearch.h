#ifndef linearsearch_h
#define linearsearch_h

#include <vector>
using namespace std;

//   LINEAR-SEARCH(A)
//   - Time: O(n)
template<typename T>
int linearSearch(const vector<T> &vec,const T & tar)
{
    for(int i=0;i<static_cast<int> (vec.size());i++)
    {
        if(vec[i]!=tar)
            continue;
        return i;
    }
    return -1;
}
#endif