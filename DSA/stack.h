#ifndef stack_h
#define stack_h

#include "linklist.h"

namespace CLRS {
/// @brief stack implemented by linked list
/// @tparam T
template <typename T> class stack {
private:
  linklist<T> list;

public:
  stack();
  ~stack();
  bool empty();
  void push(const T &x);
  void pop();
  T top() const;
};

template <typename T> stack<T>::stack() {}

template <typename T> stack<T>::~stack() {}

template <typename T> bool stack<T>::empty() { return list.empty(); }

/// @brief push a value into stack
/// @tparam T
/// @param x the value to be pushed
template <typename T> void stack<T>::push(const T &x) { list.push_back(x); }

/// @brief pop the top element out, no return
/// @tparam T
template <typename T> void stack<T>::pop() {
  list.pop_back();
}

/// @brief get the top element
/// @tparam T
/// @return return the top element's key
template <typename T> T stack<T>::top() const {
  return list.back();
}

} // namespace CLRS

#endif