#pragma once
#include <sstream>

template<typename T> 
  struct BTNode { // Node for a Binary Tree. T is a generic typename.
  // Data Fields
  T data;
  BTNode<T> *left;
  BTNode<T> *right;
  BTNode<T> *parent;

  // Constructor
  BTNode(const T& dat, 
         BTNode<T>* left_val=NULL,
         BTNode<T>* right_val=NULL,
         BTNode<T>* parent_val=NULL) :
    data(dat), left(left_val), right(right_val), parent(parent_val) {}
  
  // Destructor (to avoid warning message)
  virtual ~BTNode() {}

  // to_string()
  virtual std::string to_string() {
    std::ostringstream os;
    os << data;
    return os.str();
  }
};

// operator "<<" overloading for BTNode<T>
template<typename T> 
  std::ostream& operator<<(std::ostream& out, BTNode<T>& node) {
  return out << node.to_string();
}
