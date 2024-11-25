#include "countingsort.h"

#include "../resourse/print.h"

int main() {
  std::vector<size_t> vec2 = {10, 8, 6, 1, 4, 3, 7, 5, 5};

  CLRS::print(vec2);
  CLRS::countingSort(vec2, 10);
  std::cout << "after countingsort:\n";
  CLRS::print(vec2);
  return 0;
}