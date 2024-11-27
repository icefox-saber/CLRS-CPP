#ifndef select5_h
#define select5_h

#include "../Sort/quicksort.h"
#include <algorithm>
#include <array>
#include <assert.h>
#include <cmath>
#include <vector>

namespace CLRS {

template <typename T> int min(const std::vector<T> &vec) {
  int p = 0;
  std::size_t size = vec.size();
  for (size_t i = 1; i < size; i++) {
    if (vec[p] > vec[i]) {
      p = i;
    }
  }

  return p;
}

template <typename T>
int min(const std::vector<T> &vec, std::size_t l, std::size_t r) {
  std::size_t p = l;
  std::size_t size = vec.size();
  assert(r < size);
  for (size_t i = l + 1; i <= r; i++) {
    if (vec[p] > vec[i]) {
      p = i;
    }
  }

  return p;
}

template <typename T> int partition(std::vector<T> &vec, int l, int r, int p) {
  std::swap(vec[r], vec[p]);
  return partition(vec, l, r);
}

/// @brief select the ith element in vec
/// @tparam T element type
/// @param vec element vec
/// @param i the order of the element(begin at 0)
/// @param l left bounds index of vec
/// @param r right bounds index of vec
/// @return the index of the ith element
template <typename T> int select5(std::vector<T> &vec, int i, int l, int r) {
  assert(i < r - l + 1);
  while (((r - l + 1) % 5) != 0) {
    int mindex = min(vec, l, r);
    std::swap(vec[mindex], vec[l]);

    if (i == 0) {
      return l;
    }
    l++;
    i--;
  }

  assert(((r - l + 1) % 5) == 0);

  int g = (r - l + 1) / 5;

  for (int j = l, k = 0; k < g; j++, k++) {
    std::vector<T> vec_5 = {vec[j], vec[j + g], vec[j + 2 * g], vec[j + 3 * g],
                            vec[j + 4 * g]};
    quickSort(vec_5);
    for (int i = 0; i < 5; i++) {
      vec[j + i * g] = vec_5[i];
    }
  }

  int x = select5(vec, g / 2, l + 2 * g, l + 3 * g - 1);

  int p = partition(vec, l, r, x);
  if (i == p - l) {
    return p;
  }

  else if (i > p - l) {
    return select5(vec, i - p + l - 1, p + 1, r);
  }

  else {
    return select5(vec, i, l, p - 1);
  }

  return -1;
}

/// @brief select the ith element in vec
/// @tparam T element type
/// @param vec element vec
/// @param i the order of the element(begin at 0)
/// @return the ith element
template <typename T> T select5(const std::vector<T> &vec, std::size_t i) {
  assert(i < vec.size());
  std::vector<T> copy = vec;
  int x = select5(copy, i, 0, copy.size() - 1);
  return copy[x];
}
} // namespace CLRS

#endif
