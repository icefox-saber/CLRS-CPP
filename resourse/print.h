#ifndef print_h
#define print_h

#include <iostream>
#include <vector>

namespace CLRS {
template <typename T> void print(std::vector<T> &vec) {
  for (std::size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << ' ';
  }
  std::cout << std::endl;
};
} // namespace CLRS

#endif