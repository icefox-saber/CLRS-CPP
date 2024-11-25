#include "stack.h"
#include <iostream>

int main() {
  CLRS::stack<int> stk;
  stk.push(30);
  std::cout << "after push 30:" << std::endl << stk.top() << std::endl;
  stk.push(20);
  std::cout << "after push 20:" << std::endl << stk.top() << std::endl;
  stk.push(10);
  std::cout << "after push 10:" << std::endl << stk.top() << std::endl;
  stk.pop();
  std::cout << "after pop 10:" << std::endl << stk.top() << std::endl;
  stk.pop();
  std::cout << "after pop 20:" << std::endl << stk.top() << std::endl;
  stk.pop();
  std::cout << "after pop 30:" << std::endl << stk.top() << std::endl;
}