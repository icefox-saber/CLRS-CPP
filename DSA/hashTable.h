#ifndef hash_table_h
#define hash_table_h

#include "linklist.h"
#include <vector>

namespace CLRS {
template <typename K, typename V> class hash_table {
private:
  std::vector<linklist<std::pair<K, V>>> table;
  size_t current_size;
  size_t max_size;
  size_t hash_function(const K &key) const;
  void extend_table();

public:
  hash_table(const size_t &s = 10);
  ~hash_table();
  void insert(const K &key, const V &value);
  link_node<std::pair<K, V>> *search(const K &key) const;
  void remove(const K &key);
};

template <typename K, typename V>
hash_table<K, V>::hash_table(const size_t &s) {
  current_size = 0;
  max_size = s;
  for (size_t i = 0; i < max_size; i++) {
    linklist<std::pair<K, V>> ls;
    table.push_back(ls);
  }

  return;
}

template <typename K, typename V> hash_table<K, V>::~hash_table() {}

template <typename K, typename V>
size_t hash_table<K, V>::hash_function(const K &key) const {
  std::hash<K> hasher;
  return hasher(key) % max_size;
}

template <typename K, typename V> void hash_table<K, V>::extend_table() {}

template <typename K, typename V>
void hash_table<K, V>::insert(const K &key, const V &value) {
  if (current_size >= max_size) {
    extend_table();
  }

  size_t idx = hash_function(key);
  std::pair<K, V> elm = {key, value};
  linklist<std::pair<K, V>> &ls = table[idx];
  ls.push_back(elm);
  current_size++;
}
template <typename K, typename V>
link_node<std::pair<K, V>> *hash_table<K, V>::search(const K &key) const {
  size_t idx = hash_function(key);
  std::pair<K, V> *elm;
  link_node<std::pair<K, V>> *hd = table[idx].gethead();
  elm = &(hd->key);
  elm->first = key;
  link_node<std::pair<K, V>> *p = hd->next;
  elm = &(p->key);
  while (elm->first != key) {
    p = p->next;
    elm = &(p->key);
  }
  if (p == hd) {
    return nullptr;
  }

  return p;
}
template <typename K, typename V> void hash_table<K, V>::remove(const K &key) {
  link_node<std::pair<K, V>> *p = search(key);
  if (p == nullptr) {
    return;
  }
  size_t idx = hash_function(key);
  linklist<std::pair<K, V>> &ls = table[idx];
  ls.remove(p);
  current_size--;
}
} // namespace CLRS

#endif
