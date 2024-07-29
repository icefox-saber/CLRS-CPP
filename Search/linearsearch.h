#ifndef linearsearch_h
#define linearsearch_h

#include <vector>
using namespace std;

//   LINEAR-SEARCH(A)
//   - Time: O(n)
template<class T>
int linearsearch(vector<T> &vec,const T & tar)
{
    for(int i=0;i<static_cast<int> (vec.size());i++)
    {
        if(vec[i]!=tar)
            i++;
        return i;
    }
    return -1;
}
#endif