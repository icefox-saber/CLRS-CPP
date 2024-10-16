#ifndef mergesort_h
#define mergesort_h

#include <vector>

template <typename T>
void Merge(std::vector<T> &vec, int l, int mid, int r)
{
    std::vector<T> L, R;
    typename std::vector<T>::iterator b = vec.begin();
    L.assign(b + l, b + mid + 1); // 注意这里的区间是左闭右开
    R.assign(b + mid + 1, b + r + 1);// 注意这里的区间是左闭右开

    int j = 0, k = 0;
    int nl = L.size();
    int nr = R.size();
    for (int i = l; i <= r; i++)
    {
        if (j >= nl)
        {
            vec[i] = R[k++];
        }
        else if (k >= nr)
        {
            vec[i] = L[j++];
        }
        else if (L[j] < R[k])
        {
            vec[i] = L[j++];
        }
        else
        {
            vec[i] = R[k++];
        }
    }
    return;
}

template <typename T>
void MergeSort(std::vector<T> &vec, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = (l + r) / 2;

    MergeSort(vec, l, mid);
    MergeSort(vec, mid + 1, r);
    Merge(vec, l, mid, r);
}

template <typename T>
void MergeSort(std::vector<T> &vec)
{
    MergeSort(vec, 0,vec.size()-1);
}

#endif