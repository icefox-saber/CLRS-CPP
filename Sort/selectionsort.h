#ifndef selectionsort_h
#define selectionsort_h

#include <vector>

namespace CLRS
{
    template <typename T>
    void selectionsort(std::vector<T> &vec)
    {
        int n = static_cast<int>(vec.size());
        for (int i = 0; i < n; i++)
        {
            int minvarindex = i;
            for (int j = i + 1; j < n; j++)
            {
                if (vec[j] < vec[minvarindex])
                {
                    minvarindex = j;
                }
            }
            std::swap(vec[i], vec[minvarindex]);
        }
    };
} // namespace CLRS

#endif