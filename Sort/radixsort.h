#ifndef radixsort_h
#define radixsort_h

#include <cmath>
#include <vector>

void countingSort(std::vector<int> &vec, std::vector<int> &D, int max_num)
{
    std::vector<int> Ctr;
    Ctr.assign(max_num + 1, 0);
    for (int i = 0; i < vec.size(); i++)
    {
        Ctr[D[i]]++;
    }

    for (int i = 0; i < Ctr.size() - 1; i++)
    {
        Ctr[i + 1] += Ctr[i];
    }

    std::vector<int> tmp(vec.size(), 0);

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        tmp[Ctr[D[i]] - 1] = vec[i];
        Ctr[D[i]]--;
    }
    vec = tmp;
}

void radixSort(std::vector<int> &A, int d, int k = 9)
{
    for (int i = 0; i < d; i++)
    {
        std::vector<int> digit(A.size(), 0);
        for (int j = 0; j < A.size(); j++)
        {
            digit[j] = A[j] / (int)std::pow(10, i) % 10;
        }
        countingSort(A, digit, k);
    }
}

#endif
