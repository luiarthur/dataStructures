#pragma once
#include <iostream>
#include <cstddef>     // for Binary_Tree::to_string()
#include <sstream>     // for Binary_Tree::to_string()
#include <stdexcept>   // for Binary_Tree::to_string()
#include <string>      // for Binary_Tree::to_string()
#include "BTNode.h"

// When working with Template Classes and Functions, put
// all code in one file. Otherwise, compiler will not
// compile successfully.

template<typename T> class Binary_Tree {
    public:
        // Constructors:
        Binary_Tree() : root(NULL) {}
        Binary_Tree(const T& dat, 
                    const Binary_Tree<T>& left_child  = Binary_Tree(),
                    const Binary_Tree<T>& right_child = Binary_Tree()) :
          root(new BTNode<T>(dat, left_child.root, right_child.root)) {}

        // Destructor (To avoid warning message. Does nothing.)
        virtual ~Binary_Tree() {}

        // Get subtrees
        Binary_Tree<T> get_left_tree();
        Binary_Tree<T> get_right_tree();

        // Other Member functions
        //const T& dat() const;
        bool is_leaf();
        bool is_null();
        virtual std::string to_string(); // draw the tree

    protected:
        Binary_Tree(BTNode<T>* new_root) : root(new_root) {}
        BTNode<T> *root;
};


template<typename T>
  Binary_Tree<T> Binary_Tree<T>::get_left_tree() {
  if (root == NULL) {
    throw std::invalid_argument("Cannot get left subtree of Empty Tree.");
  }
  return Binary_Tree<T>(root->left);
}

template<typename T>
  Binary_Tree<T> Binary_Tree<T>::get_right_tree() {
  if (root == NULL) {
    throw std::invalid_argument("Cannot get right subtree of Empty Tree.");
  }
  return Binary_Tree<T>(root->right);
}

template<typename T>
  bool Binary_Tree<T>::is_leaf() {
  if (root != NULL) {
    return root->left == NULL && root->right == NULL;
  } else {
    return true;
  }
}

template<typename T>
  bool Binary_Tree<T>::is_null() {
  return root == NULL;
}

template<typename T>
  std::string Binary_Tree<T>::to_string() {
  std::ostringstream os;

  if (is_null()) {
    os << "NULL\n";
  } else {
    os << (*root).to_string() << "\n";
    os << get_left_tree().to_string();
    os << get_right_tree().to_string();
  }
  return os.str();
}

template<typename T>
  std::ostream& operator<<(std::ostream& out, Binary_Tree<T>& tree) {
  return out << tree.to_string();
}
