#include "mergesort.h"

#include "../resourse/print.h"

int main() {
  std::vector<int> vec = {4, 5, 3, 6, 2, 7, 1, 8};

  CLRS::print(vec);
  CLRS::MergeSort(vec);
  std::cout << "after mergesort:\n";
  CLRS::print(vec);

  return 0;
}