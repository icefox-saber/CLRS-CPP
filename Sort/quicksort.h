#ifndef quicksort_h
#define quicksort_h

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

template <typename T> void quickSort(std::vector<T> &vec, int l, int r) {
  if (l > r) {
    return;
  }

  int pivot_index = partition(vec, l, r);
  quickSort(vec, l, pivot_index - 1);
  quickSort(vec, pivot_index + 1, r);
}

template <typename T> void quickSort(std::vector<T> &vec) {
  quickSort(vec, 0, vec.size() - 1);
}

template <typename T> int random_partition(std::vector<T> &vec, int l, int r) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(l, r);
  int p = dis(gen);
  std::swap(vec[r], vec[p]);
  return partition(vec, l, r);
}

template <typename T> void random_quickSort(std::vector<T> &vec, int l, int r) {
  if (l > r) {
    return;
  }

  int pivot_index = random_partition(vec, l, r);
  random_quickSort(vec, l, pivot_index - 1);
  random_quickSort(vec, pivot_index + 1, r);
}

template <typename T> void random_quickSort(std::vector<T> &vec) {
  random_quickSort(vec, 0, vec.size() - 1);
}

} // namespace CLRS

#endif