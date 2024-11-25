#ifndef linklist_h
#define linklist_h

#include <iostream>

namespace CLRS {
/// @brief node struct for linklist
/// @tparam T
template <typename T> struct link_node {
  T key;
  link_node<T> *pre;  // pointer to pre node
  link_node<T> *next; // pointer to next node
  link_node(){};
  link_node(const T &k, link_node<T> *p = nullptr, link_node<T> *n = nullptr);
  ~link_node(){};
};

template <typename T>
link_node<T>::link_node(const T &k, link_node<T> *p, link_node<T> *n)
    : key(k), pre(p), next(n){};

/// @brief double linked list template
/// @tparam T
template <typename T> class linklist {
private:
  link_node<T> *head; // pointer to first node(sentinel)

public:
  linklist();
  ~linklist();
  link_node<T> *search(const T &x);
  void prepend(const T &x);
  void insert(link_node<T> *p, const T &x);
  void insert(const T &y, const T &x); // insert x after y
  void remove(const T &x);
  void remove(link_node<T> *p);
  void display();
  bool empty();
  link_node<T>* gethead(){return head;};
};

template <typename T> linklist<T>::linklist() {
  head = new link_node<T>();
  head->pre = head;
  head->next = head;
}

template <typename T> linklist<T>::~linklist() {
  link_node<T> *p = head;
  link_node<T> *q = p;
  p->pre->next = nullptr;
  while (p != nullptr) {
    q = q->next;
    delete p;
    p = q;
  }
}

/// @brief search the node whose key is x
/// @tparam T template
/// @param x key value to search
/// @return the pointer to the first node with key x, nullptr if not found
template <typename T> link_node<T> *linklist<T>::search(const T &x) {
  head->key = x;
  link_node<T> *p = head->next;
  while (p->key != x) {
    p = p->next;
  }
  if (p == head) {
    return nullptr;
  }

  return p;
}

/// @brief insert a node after head(sentinel)
/// @tparam T
/// @param x new node's key value
template <typename T> void linklist<T>::prepend(const T &x) {
  link_node<T> *p = new link_node<T>(x, head, head->next);
  head->next->pre = p;
  head->next = p;
}

/// @brief insert x after node pointed by p
/// @tparam T
/// @param p pointer to existing node
/// @param x new node's key
template <typename T> void linklist<T>::insert(link_node<T> *p, const T &x) {
  link_node<T> *q = new link_node<T>(x, p, p->next);
  p->next->pre = q;
  p->next = q;
}

/// @brief insert node with key x behind node with key y
/// @tparam T
/// @param y existed node's key
/// @param x new node's key
template <typename T> void linklist<T>::insert(const T &y, const T &x) {
  link_node<T> *p = search(y);
  if (p != nullptr) {
    insert(p, x);
  }
}

/// @brief remove the object pointed by p
/// @tparam T
/// @param p pointer to the object to delete
template <typename T> void linklist<T>::remove(link_node<T> *p) {
  if (p == head || p == nullptr) {
    return;
  }

  p->pre->next = p->next;
  p->next->pre = p->pre;

  delete p;
}

/// @brief remove the object with key x
/// @tparam T
/// @param x key value
template <typename T> void linklist<T>::remove(const T &x) {
  link_node<T> *p = search(x);
  if (p != nullptr) {
    remove(p);
  }
}

/// @brief display the list by order head->next
/// @tparam T
template <typename T> void linklist<T>::display() {
  link_node<T> *p = head->next;
  while (p != head) {
    std::cout << p->key << ' ';
    p = p->next;
  }
  std::cout << std::endl;
}

/// @brief check if the list is empty
/// @tparam T
/// @return return ture if list is emptr, else false
template <typename T> bool linklist<T>::empty() { return head->next == head; }

} // namespace CLRS
#endif
