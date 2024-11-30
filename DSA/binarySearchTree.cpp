#include "binarySearchTree.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  CLRS::binarySearchTree<int> tr{};
  tr.insert(10);
  tr.insert(7);
  tr.insert(6);
  tr.insert(11);
  tr.insert(12);

  tr.inorder();
  cout << endl;
  tr.preorder();
  cout << endl;
  tr.postorder();
  cout << endl;

  int mx = tr.maximum()->data;
  int mi = tr.minimum()->data;

  cout << "max:" << mx << endl;
  cout << "min:" << mi << endl;

  tr.remove(10);
  if (tr.search(10) != nullptr) {
    cout << "10:" << tr.search(10)->data << endl;
  }
  if (tr.search(11) != nullptr) {
    cout << "11:" << tr.search(11)->data << endl;
  }
  if (tr.predecessor(7) != nullptr) {
    cout << "6:" << tr.predecessor(7)->data << endl;
  }

  if (tr.predecessor(11)) {
    cout << "7:" << tr.predecessor(11)->data << endl;
  }
}