#ifndef select5_h
#define select5_h

#include <vector>
#include <assert.h>
#include <array>
#include <algorithm>
#include <cmath>

namespace CLRS
{
    // 可变参数模板排序函数，直接接受多个引用参数
    template <typename T, typename... Args>
    void sort(T &a, T &b, Args &...args)
    {
        // 使用 std::array 存储引用的指针
        std::array<T *, sizeof...(args) + 2> elements = {&a, &b, &args...};

        // 使用标准库排序，并解引用进行比较
        std::sort(elements.begin(), elements.end(), [](T *lhs, T *rhs)
                  { return *lhs < *rhs; });
    }

    template <typename T>
    int min(const std::vector<T> &vec)
    {
        int p = 0;
        std::size_t size = vec.size();
        for (size_t i = 1; i < size; i++)
        {
            if (vec[p] > vec[i])
            {
                p = i;
            }
        }

        return p;
    }

    template <typename T>
    int min(const std::vector<T> &vec, std::size_t l, std::size_t r)
    {
        std::size_t p = l;
        std::size_t size = vec.size();
        assert(r < size);
        for (size_t i = l + 1; i <= r; i++)
        {
            if (vec[p] > vec[i])
            {
                p = i;
            }
        }

        return p;
    }

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
    int partition(std::vector<T> &vec, int l, int r, int p)
    {
        std::swap(vec[r], vec[p]);
        return partition(vec, l, r);
    }

    /// @brief select the ith element in vec
    /// @tparam T element type
    /// @param vec element vec
    /// @param i the order of the element
    /// @param l left bounds index of vec
    /// @param r right bounds index of vec
    /// @return the index of the ith element
    template <typename T>
    int select5(std::vector<T> &vec, int i, int l, int r)
    {
        assert(i <= r - l + 1);
        while (((r - l + 1) % 5) != 0)
        {
            int mindex = min(vec, l, r);
            std::swap(vec[mindex], vec[l]);

            if (i == 1)
            {
                return l;
            }
            l++;
            i--;
        }

        assert(((r - l + 1) % 5) == 0);

        int g = (r - l + 1) / 5;

        for (int j = l; j < r; j += 5)
        {
            sort(vec[j], vec[j + g], vec[j + 2 * g], vec[j + 3 * g], vec[j + 4 * g]);
        }

        int x = select5(vec, std::ceil(g / 2.0), l + 2 * g, l + 3 * g - 1);

        int p = partition(vec, l, r, x);
        if (i == p - l + 1)
        {
            return p;
        }

        else if (i > p - l + 1)
        {
            return select5(vec, i - p + l - 1, p + 1, r);
        }

        else
        {
            return select5(vec, i, l, p - 1);
        }

        return -1;
    }

    template <typename T>
    T select5(const std::vector<T> &vec, std::size_t i)
    {
        assert(i <= vec.size());
        std::vector<T> copy = vec;
        int x = select5(copy, i, 0, copy.size() - 1);
        return copy[x];
    }
} // namespace CLRS

#endif
