#include "select5.h"

#include <iostream>

int main() {
  int i = 13;
  std::vector<int> v = {
      4, 10, 6,  9,  2,  9,  7,
      8, 4,  14, 15, 11, 12, 13}; // 2,4,4,6,  7,8,9,9,  10,11,12,13  ,14,15
  std::cout << "select the " << i << "th smallest:" << CLRS::select5(v, i)
            << std::endl;
}