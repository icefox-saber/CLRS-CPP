#ifndef countingsort_h
#define countingsort_h

#include <vector>

namespace CLRS {
void countingSort(std::vector<std::size_t> &vec, std::size_t max_num) {
  std::vector<std::size_t> Ctr;
  Ctr.assign(max_num + 1, 0);
  for (std::size_t i = 0; i < vec.size(); i++) {
    Ctr[vec[i]]++;
  }

  for (std::size_t i = 0; i < Ctr.size() - 1; i++) {
    Ctr[i + 1] += Ctr[i];
  }

  std::vector<std::size_t> tmp(vec.size(), 0);

  for (int i = vec.size() - 1; i >= 0; i--) {
    tmp[Ctr[vec[i]] - 1] = vec[i];
    Ctr[vec[i]]--;
  }
  vec = tmp;
}
} // namespace CLRS

#endif
