#include "bucketsort.h"

#include "../resourse/print.h"

using namespace std;

int main() {
  vector<double> vec2 = {0.10, 0.8, 0.6, 0.1, 0.4, 0.3, 0.7, 0.5, 0.5, 0.20};

  CLRS::print(vec2);
  CLRS::bucketSort(vec2);
  cout << "after bucketsort:\n";
  CLRS::print(vec2);
  return 0;
}