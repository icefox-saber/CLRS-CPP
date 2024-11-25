#ifndef linearsearch_h
#define linearsearch_h

#include <vector>

namespace CLRS
{
    template <typename T>
    int linearSearch(const std::vector<T> &vec, const T &tar)
    {
        for (int i = 0; i < static_cast<int>(vec.size()); i++)
        {
            if (vec[i] != tar)
                continue;
            return i;
        }
        return -1;
    }
} // namespace CLRS

#endif