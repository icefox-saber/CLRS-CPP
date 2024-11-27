#ifndef select_h
#define select_h

#include "../Sort/quicksort.h"
#include <assert.h>
#include <random>
#include <vector>

namespace CLRS {

/// @brief select the ith(begin at 0) smallest element between vec[l] and vec[r]
/// @tparam T
/// @param vec the set
/// @param i the order
/// @param l left bound of set
/// @param r right bound of set
/// @return the index
template <typename T> int select(std::vector<T> &vec, int i, int l, int r) {
  assert(i < r - l + 1);

  if (l == r)
    return l;

  int p = random_partition(vec, l, r);
  if (i == p - l) {
    return p;
  }

  else if (i > p - l) {
    return select(vec, i - p + l - 1, p + 1, r);
  }

  else {
    return select(vec, i, l, p - 1);
  }
}

/// @brief select the ith(begin at 0) object in a set
/// @tparam T
/// @param vec the set
/// @param i the order
/// @return the object
template <typename T> T select(const std::vector<T> &vec, int i) {
  std::vector<T> copy = vec;
  return select(copy, i, 0, copy.size() - 1);
}
} // namespace CLRS

#endif
