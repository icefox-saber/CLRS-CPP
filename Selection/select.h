#ifndef select_h
#define select_h

#include <assert.h>
#include <random>
#include <vector>

namespace CLRS {
template <typename T> int partition(std::vector<T> &vec, int l, int r) {
  T pivot = vec[r];
  int i = l, j;
  for (j = l; j < r; j++) {
    if (vec[j] <= pivot) {
      std::swap(vec[i], vec[j]);
      i++;
    }
  }
  assert(j == r);
  std::swap(vec[i], vec[j]);
  return i;
}

template <typename T> int random_partition(std::vector<T> &vec, int l, int r) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(l, r);
  int p = dis(gen);
  std::swap(vec[r], vec[p]);
  return partition(vec, l, r);
}

template <typename T> T select(std::vector<T> &vec, int i, int l, int r) {
  assert(i <= r - l + 1);

  if (l == r)
    return vec[l];

  int p = random_partition(vec, l, r);
  if (i == p - l + 1) {
    return vec[p];
  }

  else if (i > p - l + 1) {
    return select(vec, i - p + l - 1, p + 1, r);
  }

  else {
    return select(vec, i, l, p - 1);
  }
}

template <typename T> T select(const std::vector<T> &vec, int i) {
  std::vector<T> copy = vec;
  return select(copy, i, 0, copy.size() - 1);
}
} // namespace CLRS

#endif
