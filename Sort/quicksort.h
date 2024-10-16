#ifndef quicksort_h
#define quicksort_h

#include <vector>
#include <assert.h>

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
void quickSort(std::vector<T> &vec, int l, int r)
{
    if (l > r)
    {
        return;
    }

    int pivot_index = partition(vec, l, r);
    quickSort(vec, l, pivot_index - 1);
    quickSort(vec, pivot_index + 1, r);
}

template <typename T>
void quickSort(std::vector<T> &vec)
{
    quickSort(vec, 0, vec.size() - 1);
}

#endif