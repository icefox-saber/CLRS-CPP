#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>

namespace CLRS {
enum color { black, red };
template <typename T> struct node_redBlackTree {
  T data;
  color flag;
  node_redBlackTree *parent, *left, *right;
  node_redBlackTree(const T &d, const color &f, node_redBlackTree *p = nullptr,
                    node_redBlackTree *l = nullptr,
                    node_redBlackTree *r = nullptr)
      : data(d), flag(f), parent(p), left(l), right(r) {}
};

/// @brief
/// @tparam T
template <typename T> class redBlackTree {
private:
  node_redBlackTree<T> *root;
  node_redBlackTree<T> *sentinel;
  /// @brief transplant a node v to u,v must be left or right child of u,u must
  /// not be sentinel
  ///
  /// this function will not free the memory of u in heap,
  ///
  /// this function will set u's another child as v's
  /// @param u Target
  /// @param v source
  void transplant(node_redBlackTree<T> *u, node_redBlackTree<T> *v);
  /// @brief fix the break of property of red-black tree
  /// @param n the root of the subtree break property
  void fix_insert(node_redBlackTree<T> *n);
  void fix_remove(node_redBlackTree<T> *n);
  void left_rotation(node_redBlackTree<T> *n);
  void right_rotation(node_redBlackTree<T> *n);

public:
  redBlackTree(/* args */);
  ~redBlackTree();

  void test();

  /// @brief reccurently delete subtree
  /// @param n the sub tree's root
  void clear(node_redBlackTree<T> *n);
  /// @brief insert an element
  /// @param d the element value
  void insert(const T &d);
  /// @brief remove node
  /// @param n the node's pointer
  void remove(node_redBlackTree<T> *n);
  /// @brief remov node
  /// @param d the node's data
  void remove(const T &d);
  /// @brief get mimimum node of a subtree
  /// @param node the subtree's root, default nullptr
  /// @return the mimimum node's pointer
  node_redBlackTree<T> *minimum(node_redBlackTree<T> *const &node) const;

  /// @brief get mimimum node of the tree
  /// @return the mimimum node's pointer
  node_redBlackTree<T> *minimum() const { return minimum(root); };

  /// @brief get maximum node of a subtree
  /// @param node the subtree's root, default nullptr
  /// @return the maximum node's pointer
  node_redBlackTree<T> *maximum(node_redBlackTree<T> *const &node) const;

  /// @brief get maximum node of tree
  /// @return the maximum node's pointer
  node_redBlackTree<T> *maximum() const { return maximum(root); }

  /// @brief inorder walk a subtree
  /// @param node the subtree's root, whole tree's nullptr as default
  void inorder(node_redBlackTree<T> *const &node) const;

  /// @brief inorder walk
  void inorder() const { inorder(root); }
  /// @brief inorder walk a subtree
  /// @param node the subtree's root, whole tree's nullptr as default
  void preorder(node_redBlackTree<T> *const &node) const;

  /// @brief inorder walk
  void preorder() const { preorder(root); }
  /// @brief postorder walk a subtree
  /// @param node the subtree's root, whole tree's nullptr as default
  void postorder(node_redBlackTree<T> *const &node) const;

  /// @brief postorder walk
  void postorder() const { postorder(root); }
  /// @brief search element in subtree
  /// @param x the element's value
  /// @param node the subtree's root, whole tree's nullptr as default
  /// @return pointer to the element's node
  node_redBlackTree<T> *search(const T &x,
                               node_redBlackTree<T> *const &node) const;

  /// @brief search element
  /// @param x the element's value
  /// @return pointer to the element's node
  node_redBlackTree<T> *search(const T &x) const { return search(x, root); }
  /// @brief get the successor of a element
  /// @param x the element's vaule
  /// @return pointer to the successor's node
  node_redBlackTree<T> *successor(const T &x) const;
  /// @brief get the successor of a element
  /// @param x pointer to the element's node
  /// @return pointer to the successor's node
  node_redBlackTree<T> *successor(node_redBlackTree<T> *const &node) const;
  /// @brief get the successor of a element
  /// @param x the element's vaule
  /// @return pointer to the successor's node
  node_redBlackTree<T> *predecessor(const T &x) const;
  /// @brief get the successor of a element
  /// @param x the element's vaule
  /// @return pointer to the successor's node
  node_redBlackTree<T> *predecessor(node_redBlackTree<T> *const &node) const;
};

template <typename T> void redBlackTree<T>::test() {}

template <typename T>
void redBlackTree<T>::fix_insert(node_redBlackTree<T> *n) {
  while (n->parent->flag == color::red) {
    if (n->parent == n->parent->parent->left) {
      node_redBlackTree<T> *y = n->parent->parent->right;
      if (y->flag == color::red) // case 1
      {
        n->parent->flag = color::black;
        y->flag = color::black;
        n->parent->parent->flag = color::red;
        n = n->parent->parent;
      } else {
        if (n == n->parent->right) // case 2
        {
          n = n->parent;
          left_rotation(n);
        }
        n->parent->flag = color::black; // case3
        n->parent->parent->flag = color::red;
        right_rotation(n->parent->parent);
      }

    } else {
      if (n->parent == n->parent->parent->right) {
        node_redBlackTree<T> *y = n->parent->parent->left;
        if (y->flag == color::red) {
          y->flag = color::black;
          n->parent->flag = color::black;
          n->parent->parent->flag = color::red;
          n = n->parent->parent;
        } else {
          if (n == n->parent->left) {
            n = n->parent;
            right_rotation(n);
          }

          n->parent->flag = color::black;
          n->parent->parent->flag = color::red;
          left_rotation(n->parent->parent);
        }
      }
    }
  }

  root->flag = color::black;
}
template <typename T>
void redBlackTree<T>::fix_remove(node_redBlackTree<T> *n) {
  while (n != root && n->flag == color::black) {
    if (n == n->parent->left) {
      node_redBlackTree<T> *w = n->parent->right;
      if (w->flag == color::red) {
        w->flag = color::black;
        n->parent->flag = color::red;
        left_rotation(n->parent);
        w = n->parent->right;
      }
      // w is black
      if (w->left->flag == color::black && w->right->flag == color::black) {
        w->flag = color::red;
        n = n->parent;
      }

      // w has red child
      else {

        // w->right is black
        if (w->right->flag == black) {
          w->left->flag = color::black;
          w->flag = color::red;
          right_rotation(w);
          w = n->parent->right;
        }

        // w->right is red
        w->flag = n->parent->flag;
        n->parent->flag = color::black;
        w->right->flag = color::black;
        left_rotation(n->parent);
        n = root;
      }

    } else {
      node_redBlackTree<T> *w = n->parent->left;
      if (w->flag == color::red) {
        w->flag = color::black;
        n->parent->flag = color::red;
        left_rotation(n->parent);
        w = n->parent->left;
      }
      // w is black
      if (w->right->flag == color::black && w->left->flag == color::black) {
        w->flag = color::red;
        n = n->parent;
      }

      // w has red child
      else {

        // w->left is black
        if (w->left->flag == black) {
          w->right->flag = color::black;
          w->flag = color::red;
          left_rotation(w);
          w = n->parent->left;
        }

        // w->left is red
        w->flag = n->parent->flag;
        n->parent->flag = color::black;
        w->left->flag = color::black;
        right_rotation(n->parent);
        n = root;
      }
    }
  }
  n->flag = color::black;
}
template <typename T>
void redBlackTree<T>::left_rotation(node_redBlackTree<T> *n) {
  if (n != nullptr && n != sentinel) {
    node_redBlackTree<T> *y = n->right;
    if (y != sentinel) {
      n->right = y->left;
      y->left->parent = n;
      y->parent = n->parent;
      if (n == root) {
        root = y;
      } else if (n == n->parent->left) {
        n->parent->left = y;
      } else {
        n->parent->right = y;
      }

      n->parent = y;
      y->left = n;
    }
  }
}
template <typename T>
void redBlackTree<T>::right_rotation(node_redBlackTree<T> *n) {
  if (n != nullptr && n != sentinel) {
    node_redBlackTree<T> *y = n->left;
    if (y != sentinel) {
      n->left = y->right;
      y->right->parent = n;
      y->parent = n->parent;
      if (n == root) {
        root = y;
      } else if (n == n->parent->left) {
        n->parent->left = y;
      } else {
        n->parent->right = y;
      }

      n->parent = y;
      y->right = n;
    }
  }
}

template <typename T> redBlackTree<T>::redBlackTree(/* args */) {
  root = nullptr;
  sentinel = new node_redBlackTree<T>(T(), color::black);
  sentinel->left = sentinel->right = sentinel;
}

template <typename T> void redBlackTree<T>::clear(node_redBlackTree<T> *n) {
  if (n != nullptr && n != sentinel) {
    clear(n->left);
    clear(n->right);
    delete n;
  }
  sentinel->parent = sentinel;
}

template <typename T> void redBlackTree<T>::insert(const T &d) {
  node_redBlackTree<T> *p = root, *q = sentinel; // q is the parent of p
  if (root == nullptr) {
    root =
        new node_redBlackTree<T>(d, color::red, sentinel, sentinel, sentinel);
    p = root;
  } else {
    // the while loop find the location of d(p) and its parent(q)
    while (p != sentinel) {
      if (d <= p->data) {
        q = p;
        p = q->left;
      } else {
        q = p;
        p = q->right;
      }
    }

    // now p is nullptr and q is a leaf, but we still don't kown d will be left
    // or right child
    p = new node_redBlackTree<T>(d, color::red, q, sentinel, sentinel);

    if (d <= q->data) {
      q->left = p;
    } else {
      q->right = p;
    }
  }

  fix_insert(p);
}

template <typename T> void redBlackTree<T>::remove(node_redBlackTree<T> *n) {
  if (n != nullptr && n != sentinel) {
    node_redBlackTree<T> *y = n;
    node_redBlackTree<T> *x = nullptr;
    color y_original_color = y->flag;
    if (n->left == sentinel) {
      transplant(n, n->right);
      x = n->right;
    } else if (n->right == sentinel) {
      transplant(n, n->left);
      x = n->left;
    } else {

      // n has two child
      y = successor(n); // s must be in right subtree of s
      // s and n has right subtree can not transplant directly
      y_original_color = y->flag;
      x = y->right;
      if (y != n->right) {
        transplant(y, y->right);
        y->right = n->right;
        n->right->parent = y;
        y->parent = n;
        n->right = y;
        transplant(n, y);
      }
      //
      else {
        transplant(n, y);
      }
      y->flag = n->flag;
    }

    delete n;
    if (y_original_color == color::black) {
      fix_remove(x);
    }
    if (root == sentinel) {
      root = nullptr;
    }
  }
}
template <typename T> void redBlackTree<T>::remove(const T &d) {
  node_redBlackTree<T> *p = search(d);
  remove(p);
}

template <typename T>
node_redBlackTree<T> *
redBlackTree<T>::minimum(node_redBlackTree<T> *const &node) const {
  node_redBlackTree<T> *res = nullptr; // result pointer

  // if not empty, we continue finding the left child of node until achieve leaf
  if (node != nullptr && node != sentinel) {
    node_redBlackTree<T> *p = node->parent;
    node_redBlackTree<T> *q = node;
    while (q != sentinel) {
      p = q;
      q = p->left;
    }
    res = p;
  }

  return res;
}

template <typename T>
node_redBlackTree<T> *
redBlackTree<T>::maximum(node_redBlackTree<T> *const &node) const {
  node_redBlackTree<T> *res = nullptr; // result pointer

  // if not empty, we continue finding the right child of node until achieve
  // leaf
  if (node != nullptr && node != sentinel) {

    node_redBlackTree<T> *p = node->parent;
    node_redBlackTree<T> *q = node;
    while (q != sentinel) {
      p = q;
      q = p->right;
    }
    res = p;
  }
  return res;
}

template <typename T>
void redBlackTree<T>::inorder(node_redBlackTree<T> *const &node) const {
  if (node != nullptr && node != sentinel) {
    inorder(node->left);
    std::cout << node->data << ' ' << node->flag << ' ';
    inorder(node->right);
  }
}

template <typename T>
void redBlackTree<T>::preorder(node_redBlackTree<T> *const &node) const {
  if (node != nullptr && node != sentinel) {
    std::cout << node->data << ' ' << node->flag << ' ';
    preorder(node->left);
    preorder(node->right);
  }
}

template <typename T>
void redBlackTree<T>::postorder(node_redBlackTree<T> *const &node) const {
  if (node != nullptr && node != sentinel) {
    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << ' ' << node->flag << ' ';
  }
}

template <typename T>
node_redBlackTree<T> *
redBlackTree<T>::search(const T &x, node_redBlackTree<T> *const &node) const {
  node_redBlackTree<T> *res = nullptr;
  node_redBlackTree<T> *p = node;
  while (p != nullptr && p != sentinel) {
    if (p->data > x) {
      p = p->left;
    } else if (p->data < x) {
      p = p->right;
    } else {
      res = p;
      break;
    }
  }

  return res;
}

template <typename T>
node_redBlackTree<T> *redBlackTree<T>::successor(const T &x) const {
  node_redBlackTree<T> *res = nullptr;
  node_redBlackTree<T> *p = search(x);
  if (p != nullptr) {
    res = successor(p);
  }

  return res;
}

template <typename T>
node_redBlackTree<T> *
redBlackTree<T>::successor(node_redBlackTree<T> *const &node) const {
  node_redBlackTree<T> *res = nullptr;
  if (node != nullptr && node != sentinel) {
    if (node->right == sentinel) {
      node_redBlackTree<T> *p = node;
      node_redBlackTree<T> *q = p->parent;
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
      res = minimum(node->right);
    }
  }

  return res;
}

template <typename T>
node_redBlackTree<T> *redBlackTree<T>::predecessor(const T &x) const {
  node_redBlackTree<T> *res = nullptr;
  node_redBlackTree<T> *p = search(x);
  if (p != nullptr) {
    res = predecessor(p);
  }

  return res;
}

template <typename T>
node_redBlackTree<T> *
redBlackTree<T>::predecessor(node_redBlackTree<T> *const &node) const {
  node_redBlackTree<T> *res = nullptr;
  if (node != nullptr && node != sentinel) {

    if (node->left == sentinel) {
      node_redBlackTree<T> *p = node;
      node_redBlackTree<T> *q = p->parent;
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

      res = maximum(node->left);
    }
  }
  return res;
}

template <typename T>
void redBlackTree<T>::transplant(node_redBlackTree<T> *u,
                                 node_redBlackTree<T> *v) {

  if (u != nullptr && u != sentinel && v != nullptr) {
    node_redBlackTree<T> *p = u->parent;
    if (p != sentinel) // u is not root;
    {
      if (p->left == u) {
        p->left = v;
      } else {
        p->right = v;
      }
    } else {
      root = v;
    }

    v->parent = p;
    if (v != sentinel) {
      if (v == u->left) {
        v->right = u->right;
        v->right->parent = v; // v->right probaly sentinel

      } else {
        v->left = u->left;
        v->left->parent = v; // v->left probaly sentinel
      }
    }
  }
}

template <typename T> redBlackTree<T>::~redBlackTree() {
  clear(root);
  delete sentinel;
}

} // namespace CLRS

#endif
