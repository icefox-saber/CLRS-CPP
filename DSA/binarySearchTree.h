#ifndef binary_search_tree_h
#define binary_search_tree_h

#include <iostream>

namespace CLRS {
template <typename T> struct node_binarySearchTree {
  T data;
  node_binarySearchTree *parent, *left, *right;
  node_binarySearchTree(const T &d, node_binarySearchTree *p = nullptr,
                        node_binarySearchTree *l = nullptr,
                        node_binarySearchTree *r = nullptr)
      : data(d), parent(p), left(l), right(r) {}
};

/// @brief
/// @tparam T
template <typename T> class binarySearchTree {
private:
  node_binarySearchTree<T> *root;

  /// @brief transplant a node v to u,v must be left or right child of u
  ///
  /// this function will not free the memory of u in heap,
  ///
  /// this function will set u's another child as v's
  /// @param u Target
  /// @param v source
  void transplant(node_binarySearchTree<T> *u, node_binarySearchTree<T> *v);

public:
  binarySearchTree(/* args */);
  ~binarySearchTree();

  /// @brief reccurently delete subtree
  /// @param n the sub tree's root
  void clear(node_binarySearchTree<T> *n);
  /// @brief insert an element
  /// @param d the element value
  void insert(const T &d);
  /// @brief remove node
  /// @param n the node's pointer
  void remove(node_binarySearchTree<T> *n);
  /// @brief remov node
  /// @param d the node's data
  void remove(const T &d);
  /// @brief get mimimum node of a subtree
  /// @param node the subtree's root, default nullptr
  /// @return the mimimum node's pointer
  node_binarySearchTree<T> *
  minimum(node_binarySearchTree<T> *const &node) const;

  /// @brief get mimimum node of the tree
  /// @return the mimimum node's pointer
  node_binarySearchTree<T> *minimum() const { return minimum(root); };

  /// @brief get maximum node of a subtree
  /// @param node the subtree's root, default nullptr
  /// @return the maximum node's pointer
  node_binarySearchTree<T> *
  maximum(node_binarySearchTree<T> *const &node) const;

  /// @brief get maximum node of tree
  /// @return the maximum node's pointer
  node_binarySearchTree<T> *maximum() const { return maximum(root); }

  /// @brief inorder walk a subtree
  /// @param node the subtree's root, whole tree's nullptr as default
  void inorder(node_binarySearchTree<T> *const &node) const;

  /// @brief inorder walk
  void inorder() const { inorder(root); }
  /// @brief inorder walk a subtree
  /// @param node the subtree's root, whole tree's nullptr as default
  void preorder(node_binarySearchTree<T> *const &node) const;

  /// @brief inorder walk
  void preorder() const { preorder(root); }
  /// @brief postorder walk a subtree
  /// @param node the subtree's root, whole tree's nullptr as default
  void postorder(node_binarySearchTree<T> *const &node) const;

  /// @brief postorder walk
  void postorder() const { postorder(root); }
  /// @brief search element in subtree
  /// @param x the element's value
  /// @param node the subtree's root, whole tree's nullptr as default
  /// @return pointer to the element's node
  node_binarySearchTree<T> *search(const T &x,
                                   node_binarySearchTree<T> *const &node) const;

  /// @brief search element
  /// @param x the element's value
  /// @return pointer to the element's node
  node_binarySearchTree<T> *search(const T &x) const { return search(x, root); }
  /// @brief get the successor of a element
  /// @param x the element's vaule
  /// @return pointer to the successor's node
  node_binarySearchTree<T> *successor(const T &x) const;
  /// @brief get the successor of a element
  /// @param x pointer to the element's node
  /// @return pointer to the successor's node
  node_binarySearchTree<T> *
  successor(node_binarySearchTree<T> *const &node) const;
  /// @brief get the successor of a element
  /// @param x the element's vaule
  /// @return pointer to the successor's node
  node_binarySearchTree<T> *predecessor(const T &x) const;
  /// @brief get the successor of a element
  /// @param x the element's vaule
  /// @return pointer to the successor's node
  node_binarySearchTree<T> *
  predecessor(node_binarySearchTree<T> *const &node) const;
};

template <typename T> binarySearchTree<T>::binarySearchTree(/* args */) {
  root = nullptr;
}

template <typename T>
void binarySearchTree<T>::clear(node_binarySearchTree<T> *n) {
  if (n != nullptr) {
    clear(n->left);
    clear(n->right);
    delete n;
  }
}

template <typename T> void binarySearchTree<T>::insert(const T &d) {
  node_binarySearchTree<T> *p = root, *q = nullptr; // q is the parent of p
  if (root == nullptr) {
    root = new node_binarySearchTree<T>(d, q);
    return;
  }

  // the while loop find the location of d(p) and its parent(q)
  while (p != nullptr) {
    if (d <= p->data) {
      q = p;
      p = q->left;
    } else {
      q = p;
      p = q->right;
    }
  }

  // now p is nullptr and q is a leaf, but we still don't kown d will be left or
  // right child
  p = new node_binarySearchTree<T>(d, q);

  if (d <= q->data) {
    q->left = p;
  } else {
    q->right = p;
  }
}
template <typename T>
void binarySearchTree<T>::remove(node_binarySearchTree<T> *n) {
  if (n->left == nullptr) {
    transplant(n, n->right);
  } else if (n->right == nullptr) {
    transplant(n, n->left);
  }
  // n has two child
  node_binarySearchTree<T> *s = successor(n); // s must be in right subtree of s
  // s and n has right subtree can not transplant directly
  if (s != n->right) {
    transplant(s, s->right);
    s->right = n->right;
    n->right->parent = s;
    s->parent = n;
    transplant(n, s);
  }
  //
  else {
    transplant(n, s);
  }

  delete n;
}
template <typename T> void binarySearchTree<T>::remove(const T &d) {
  node_binarySearchTree<T> *p = search(d);
  remove(p);
}

template <typename T>
node_binarySearchTree<T> *
binarySearchTree<T>::minimum(node_binarySearchTree<T> *const &node) const {
  node_binarySearchTree<T> *res; // result pointer
  // empty tree, return nullptr
  if (node == nullptr) {
    res = nullptr;
  }

  // if not empty, we continue finding the left child of node until achieve leaf
  else {
    node_binarySearchTree<T> *p = node->parent;
    node_binarySearchTree<T> *q = node;
    while (q != nullptr) {
      p = q;
      q = p->left;
    }
    res = p;
  }

  return res;
}

template <typename T>
node_binarySearchTree<T> *
binarySearchTree<T>::maximum(node_binarySearchTree<T> *const &node) const {
  node_binarySearchTree<T> *res; // result pointer
  // empty tree, return nullptr
  if (node == nullptr) {
    res = nullptr;
  }

  // if not empty, we continue finding the right child of node until achieve
  // leaf
  else {
    node_binarySearchTree<T> *p = node->parent;
    node_binarySearchTree<T> *q = node;
    while (q != nullptr) {
      p = q;
      q = p->right;
    }
    res = p;
  }

  return res;
}

template <typename T>
void binarySearchTree<T>::inorder(node_binarySearchTree<T> *const &node) const {
  if (node != nullptr) {
    inorder(node->left);
    std::cout << node->data << ' ';
    inorder(node->right);
  }
}

template <typename T>
void binarySearchTree<T>::preorder(
    node_binarySearchTree<T> *const &node) const {
  if (node != nullptr) {
    std::cout << node->data << ' ';
    preorder(node->left);
    preorder(node->right);
  }
}

template <typename T>
void binarySearchTree<T>::postorder(
    node_binarySearchTree<T> *const &node) const {
  if (node != nullptr) {
    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << ' ';
  }
}

template <typename T>
node_binarySearchTree<T> *
binarySearchTree<T>::search(const T &x,
                            node_binarySearchTree<T> *const &node) const {
  node_binarySearchTree<T> *res = nullptr;
  if (node != nullptr) {
    node_binarySearchTree<T> *p = node;
    while (p != nullptr) {
      if (p->data > x) {
        p = p->left;
      } else if (p->data < x) {
        p = p->right;
      } else {

        break;
      }
    }
    res = p;
  }

  return res;
}

template <typename T>
node_binarySearchTree<T> *binarySearchTree<T>::successor(const T &x) const {
  node_binarySearchTree<T> *res = nullptr;
  node_binarySearchTree<T> *p = search(x);
  if (p != nullptr) {
    res = successor(p);
  }

  return res;
}

template <typename T>
node_binarySearchTree<T> *
binarySearchTree<T>::successor(node_binarySearchTree<T> *const &node) const {
  node_binarySearchTree<T> *res = nullptr;
  if (node == nullptr) {
    return nullptr;
  }

  if (node->right == nullptr) {
    node_binarySearchTree<T> *p = node;
    node_binarySearchTree<T> *q = p->parent;
    while (q != nullptr) {
      if (q->left == p) {
        res = q;
        break;
      } else {
        p = q;
        q = p->parent;
      }
    }

  } else {
    node_binarySearchTree<T> *p = node->right; // must not be nullptr
    node_binarySearchTree<T> *q = p->left;
    while (q != nullptr) {
      p = q;
      q = p->left;
    }
    res = p;
  }

  return res;
}

template <typename T>
node_binarySearchTree<T> *binarySearchTree<T>::predecessor(const T &x) const {
  node_binarySearchTree<T> *res = nullptr;
  node_binarySearchTree<T> *p = search(x);
  if (p != nullptr) {
    res = predecessor(p);
  }

  return res;
}

template <typename T>
node_binarySearchTree<T> *
binarySearchTree<T>::predecessor(node_binarySearchTree<T> *const &node) const {
  node_binarySearchTree<T> *res = nullptr;
  if (node == nullptr) {
    return res;
  }

  if (node->left == nullptr) {
    node_binarySearchTree<T> *p = node;
    node_binarySearchTree<T> *q = p->parent;
    while (q != nullptr) {
      if (q->right == p) {
        res = q;
        break;
      } else {
        p = q;
        q = p->parent;
      }
    }

  } else {
    node_binarySearchTree<T> *p = node->left; // must not be nullptr
    node_binarySearchTree<T> *q = p->right;
    while (q != nullptr) {
      p = q;
      q = p->right;
    }
    res = p;
  }

  return res;
}

template <typename T>
void binarySearchTree<T>::transplant(node_binarySearchTree<T> *u,
                                     node_binarySearchTree<T> *v) {

  if (u != nullptr && v!=nullptr) {
    node_binarySearchTree<T> *p = u->parent;
    if (p != nullptr) // u is not root;
    {
      if (p->left == u) {
        p->left = v;
      } else {
        p->right = v;
      }
    }
    else
    {
      root = v;
    }
    
    v->parent = p;
    if (v == u->left) {
      v->right = u->right;
      if (v->right != nullptr) {
        v->right->parent = v;
      }

    } else {
      v->left = u->left;
      if (v->left != nullptr) {
        v->left->parent = v;
      }
    }
  }
}

template <typename T> binarySearchTree<T>::~binarySearchTree() { clear(root); }
} // namespace CLRS

#endif
