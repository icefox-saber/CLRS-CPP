#include "linklist.h"

#include <iostream>

int main() {
  CLRS::linklist<int> list;

  // 测试 push_front
  list.push_front(10);
  list.push_front(20);
  list.push_front(30);
  CLRS::linklist<int> ls = list;
  ls = list;
  std::cout << "After push_front 30, 20, 10:" << std::endl;
  list.display();

  // 测试 insert
  ls.insert(20, 25);
  std::cout << "After insert 25 after 20:" << std::endl;
  ls.display();

  // 测试 search
  CLRS::link_node<int> *node = ls.search(25);
  if (node != nullptr) {
    std::cout << "Search 25: Found " << node->key << std::endl;
  } else {
    std::cout << "Search 25: Not found" << std::endl;
  }

  // 测试 remove
  ls.remove(20);
  std::cout << "After remove 20:" << std::endl;
  ls.display();

  return 0;
}