#ifndef bucketsort_h
#define bucketsort_h

#include <vector>
#include <assert.h>
#include "quicksort.h"

void bucketSort(std::vector<double> &src)
{
    int n = src.size();
    std::vector<std::vector<double>> bk(n);
    for (int i = 0; i < n; i++)
    {
        assert(0 < src[i] && src[i] < 1);
        int index = src[i]*n;
        bk[index].push_back(src[i]);
    }

    for (int i = 0; i < n; i++)
    {
        quickSort(bk[i]);
    }
    
    src.clear();
    for (int i = 0; i < n; i++)
    {
        src.insert(src.end(),bk[i].begin(),bk[i].end());
    }
    
}

#endif
