#ifndef binarysearch_h
#define binarysearch_h

#include <vector>

namespace CLRS {
template <typename T>
int binarySearch(const std::vector<T> &vec, const T &tar, int l, int r) {
  if (l > r)
    return -1;
  int mid = (l + r) / 2;

  if (vec[mid] == tar) {
    return mid;
  }

  else if (vec[mid] < tar) {
    return binarySearch(vec, tar, mid + 1, r);
  }

  else {
    return binarySearch(vec, tar, l, mid - 1);
  }

  return -1;
}

template <typename T>
int binarySearch(const std::vector<T> &vec, const T &tar) {
  return binarySearch(vec, tar, 0, vec.size() - 1);
}
} // namespace CLRS

#endif