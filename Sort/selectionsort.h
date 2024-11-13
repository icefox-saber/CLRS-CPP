#ifndef selectionsort_h
#define selectionsort_h

#include <vector>
using namespace std;
//   SELECTION-SORT(A)
//   - Time: O(n^2)
template <typename T>
void selectionsort(vector<T> & vec)
{
    int n= static_cast<int>(vec.size());
    for(int i=0;i<n;i++)
    {
        int minvarindex=i;
        for(int j=i+1;j<n;j++)
        {
            if(vec[j]<vec[minvarindex])
            {
                minvarindex=j;
            }
        }
        swap(vec[i],vec[minvarindex]);
    }
};

#endif