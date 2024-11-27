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
  linklist(const linklist<T> &other);

  ~linklist();
  link_node<T> *search(const T &x);
  void insert(link_node<T> *p, const T &x);
  void insert(const T &y, const T &x);
  void remove(const T &x);
  void remove(link_node<T> *p);
  void display();
  bool empty();
  link_node<T> *gethead() const { return head; };
  /// @brief get first element
  /// @return the value of first element
  T front() const { return head->next->key; };
  /// @brief get last element
  /// @return the value of first element
  T back() const { return head->pre->key; };
  /// @brief push new element x in the first place
  /// @param x
  void push_front(const T &x) { insert(head, x); };
  /// @brief push new element x in the last place
  /// @param x
  void push_back(const T &x) { insert(head->pre, x); };
  /// @brief delete the first element
  void pop_front() { remove(head->next); };
  /// @brief delete the last element
  void pop_back() { remove(head->pre); };
  /// @brief clear the linklist, but no delete it
  void clear();
  /// @brief copy linklist
  /// @param other copied linklist
  /// @return a linklist reference
  linklist<T> &operator=(const linklist<T> &other);
};

template <typename T> linklist<T>::linklist() {
  head = new link_node<T>();
  head->pre = head;
  head->next = head;
}

template <typename T> linklist<T>::~linklist() {
  if (head == nullptr) {
    return;
  }

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

/// @brief insert x, p->next = x
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
template <typename T> void linklist<T>::clear() {

  link_node<T> *p = head->next;
  link_node<T> *q = p->next;
  while (p != head) {
    delete p;
    p = q;
    q = p->next;
  }
  head->pre = head;
  head->next = head;
}

template <typename T>
linklist<T> &linklist<T>::operator=(const linklist<T> &other) {
  clear();
  link_node<T> *head_cpy = other.head;
  link_node<T> *p_cpy = head_cpy->next;
  while (p_cpy != head_cpy) {
    push_back(p_cpy->key);
    p_cpy = p_cpy->next;
  }
  return *this;
}

template <typename T> linklist<T>::linklist(const linklist<T> &other) {
  head = new link_node<T>(); // 创建新链表的哨兵节点
  head->pre = head;
  head->next = head;

  // 遍历 other 链表并深拷贝每个节点
  link_node<T> *current = other.head->next;
  while (current != other.head) {
    push_back(current->key); // 将节点数据插入到新链表中
    current = current->next;
  }
}

} // namespace CLRS
#endif
