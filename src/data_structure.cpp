#include <accctrl.h>
#include "data_structure.hpp"

// файл с определениями

namespace itis {

  node::node(int key){
    this->key=key;
  }

  void fib_heap::add(node *newNode, node **sibl, node *par) {
    if (*sibl == NULL) {
      *sibl = newNode;
      newNode->left = newNode;
      newNode->right = newNode;
    }
    else {
      newNode->right = (*sibl)->right;
      newNode->right->left = newNode;
      newNode->left = *sibl;
      (*sibl)->right = newNode;
    }
    if (isLess(newNode, *sibl))
      *sibl = newNode;
    if(*sibl == min) {
      roots_amount++;
      newNode->parent = NULL;
    }
    if (par){
      par->degree++;
      newNode->parent = par;
    }
  }

  node *fib_heap::add(int key) {
      node* newNode = new node(key);
      add(newNode,&min);
      return newNode;
  }

  bool fib_heap::isLess(node* first, node* second) {
    return first->key<second->key;
  }
  bool fib_heap::union_root(node *newNode, int nodes_amount) {
      if (newNode == NULL)
        return false;

      if (min == NULL) {
        min = newNode;
        roots_amount = nodes_amount;
      }
      else {
        node *L = newNode->left;
        node *R = min->right;
        min->right = newNode;
        newNode->left = min;
        L->right = R;
        R->left = L;
        roots_amount += nodes_amount;
      }
      return true;
  }


  /*void fib_heap::union_fib_heap(fib_heap &fb) {
    if(union_root(fb.min,fb.roots_amount)) {
      if ((min == nullptr) || ((fb.min != nullptr) && isLess(fb.min, min)))
        min = fb.min;
    }
  }*/
}  // namespace itis