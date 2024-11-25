#include "radixsort.h"

#include "../resourse/print.h"

int main() {
  std::vector<int> vec2 = {10, 8, 6, 1, 4, 3, 7, 5, 5, 20};

  CLRS::print(vec2);
  CLRS::radixSort(vec2, 2);
  std::cout << "after radixsort:\n";
  CLRS::print(vec2);
  return 0;
}