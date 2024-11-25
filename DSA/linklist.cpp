#include "linklist.h"
#include <iostream>

int main() {
  CLRS::linklist<int> list;

  // 测试 prepend
  list.prepend(10);
  list.prepend(20);
  list.prepend(30);

  std::cout << "After prepend 30, 20, 10:" << std::endl;
  for (CLRS::link_node<int> *p = list.search(30); p != nullptr; p = p->next) {
    std::cout << p->key << " ";
    if (p->next == list.search(30))
      break; // 避免无限循环
  }
  std::cout << std::endl;

  // 测试 insert
  list.insert(20, 25);
  std::cout << "After insert 25 after 20:" << std::endl;
  for (CLRS::link_node<int> *p = list.search(30); p != nullptr; p = p->next) {
    std::cout << p->key << " ";
    if (p->next == list.search(30))
      break; // 避免无限循环
  }
  std::cout << std::endl;

  // 测试 search
  CLRS::link_node<int> *node = list.search(25);
  if (node != nullptr) {
    std::cout << "Search 25: Found " << node->key << std::endl;
  } else {
    std::cout << "Search 25: Not found" << std::endl;
  }

  // 测试 remove
  list.remove(20);
  std::cout << "After remove 20:" << std::endl;
  for (CLRS::link_node<int> *p = list.search(30); p != nullptr; p = p->next) {
    std::cout << p->key << " ";
    if (p->next == list.search(30))
      break; // 避免无限循环
  }
  std::cout << std::endl;

  return 0;
}