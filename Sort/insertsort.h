#ifndef insertsort_h
#define insertsort_h

#include <vector>

//   INSERTION-SORT(A)
//   - Time: O(n^2)

namespace CLRS
{
    template <typename T>
    void insertsort(std::vector<T> &vec)
    {
        for (int i = 1; i < static_cast<int>(vec.size()); i++)
        {
            T tmp = vec[i];
            int j = i - 1;
            while (j >= 0 && vec[j] > tmp)
            {
                vec[j + 1] = vec[j];
                j--;
            }
            vec[j + 1] = tmp;
        }
    };

    //   NONINCREASING-INSERTION-SORT(A)
    //   - Time: O(n^2)
    template <typename T>
    void insertsort_nonincrease(std::vector<T> &vec)
    {
        for (int i = 1; i < static_cast<int>(vec.size()); i++)
        {
            T tmp = vec[i];
            int j = i - 1;
            while (j >= 0 && vec[j] < tmp)
            {
                vec[j + 1] = vec[j];
                j--;
            }
            vec[j + 1] = tmp;
        }
    };
} // namespace CLRS

#endif