#ifndef queue_h
#define queue_h

#include "linklist.h"

namespace CLRS {
template <typename T> class queue {
private:
  linklist<T> list;

public:
  queue(/* args */);
  ~queue();
  bool empty();
  void enQueue(const T &x);
  void deQueue();
  T front() const;
};

template <typename T> queue<T>::queue(/* args */) {}

template <typename T> queue<T>::~queue() {}

template <typename T> bool queue<T>::empty() { return list.empty(); };
template <typename T> void queue<T>::enQueue(const T &x) { list.prepend(x); };
template <typename T> void queue<T>::deQueue() {
  list.remove(list.gethead()->pre);
}
template <typename T> T queue<T>::front() const {
  return list.gethead()->pre->key;
};
} // namespace CLRS

#endif