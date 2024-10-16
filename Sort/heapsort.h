#ifndef heapsort_h
#define heapsort_h

#include <vector>
#include <error.h>
#include <stdexcept>

using std::vector;

template <typename T>
class heap : public vector<T>
{
public:
    using vector<T>::vector;
    using vector<T>::operator[];
    using vector<T>::size;

    int heapsize;
    void setheapsize();
    int left(int i)const { return 2 * i + 1; }
    int right(int i)const { return 2 * i + 2; }
    int parent(int i)const { return (i - 1) / 2; }
};
template <typename T>
void heap<T>::setheapsize()
{
    heapsize = this->size();
};

template <typename T>
void max_heapify(heap<T> &h, int i)
{
    int size = h.heapsize;
    if (i > size - 1)
    {
        throw std::out_of_range("vector out-of-bounds");
    }

    int max_index = i;
    int l = h.left(i);
    int r = h.right(i);
    if (l < size  && h[l] > h[max_index])
    {
        max_index = l;
    }

    if (r < size  && h[r] > h[max_index])
    {
        max_index = r;
    }
    if (max_index != i)
    {
        std::swap(h[i], h[max_index]);
        max_heapify(h, max_index);
    }
};

template <typename T>
void build_max_heap(heap<T> &h)
{
    h.setheapsize();
    for (int i = h.parent(h.heapsize-1); i >= 0; i--)
    {
        max_heapify(h, i);
    }
};

template <typename T>
void heapsort(heap<T> &h)
{
    build_max_heap(h);
    for (int i = h.heapsize - 1; i >= 1; i--)
    {
        std::swap(h[i], h[0]);
        h.heapsize--;
        max_heapify(h, 0);
    }
};

#endif