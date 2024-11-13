#ifndef select_h
#define select_h

#include <vector>
#include <assert.h>
#include <random>

template <typename T>
int partition(std::vector<T> &vec, int l, int r)
{
    T pivot = vec[r];
    int i = l, j;
    for (j = l; j < r; j++)
    {
        if (vec[j] <= pivot)
        {
            std::swap(vec[i], vec[j]);
            i++;
        }
    }
    assert(j == r);
    std::swap(vec[i], vec[j]);
    return i;
}

template <typename T>
int random_partition(std::vector<T> &vec, int l, int r)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(l, r);
    int p = dis(gen);
    std::swap(vec[r],vec[p]);
    return partition(vec,l,r);
}

template <

#endif
