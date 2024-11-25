#include "queue.h"
#include <iostream>

int main() {
  CLRS::queue<int> que;
  que.enQueue(30);
  std::cout << "after enQueue 30:" << std::endl << que.front() << std::endl;
  que.enQueue(20);
  std::cout << "after enQueue 20:" << std::endl << que.front() << std::endl;
  que.enQueue(10);
  std::cout << "after enQueue 10:" << std::endl << que.front() << std::endl;
  que.deQueue();
  std::cout << "after deQueue 30:" << std::endl << que.front() << std::endl;
  que.deQueue();
  std::cout << "after deQueue 20:" << std::endl << que.front() << std::endl;
  que.deQueue();
  std::cout << "after deQueue 10:" << std::endl << que.front() << std::endl;
}