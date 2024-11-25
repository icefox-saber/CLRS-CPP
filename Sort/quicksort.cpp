#include "quicksort.h"

#include "../resourse/print.h"

int main() {
  std::vector<char> vec = {'s', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
  std::vector<int> vec2 = {10, 8, 6, 1, 4, 3, 7, 5, 5};
  CLRS::print(vec);
  CLRS::quickSort(vec);
  std::cout << "after quicksort:\n";
  CLRS::print(vec);

  CLRS::print(vec2);
  CLRS::random_quickSort(vec2);
  std::cout << "after random_quicksort:\n";
  CLRS::print(vec2);
  return 0;
}