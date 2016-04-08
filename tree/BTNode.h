#pragma once
#include <sstream>

template<typename T> 
  struct BTNode { // Node for a Binary Tree. T is a generic typename.
  // Data Fields
  T data;
  BTNode<T> *left;
  BTNode<T> *right;

  // Constructor
  BTNode(const T& dat, 
         BTNode<T>* left_val=NULL,
         BTNode<T>* right_val=NULL):
    data(dat), left(left_val), right(right_val) {}
  
  // Destructor (to avoid warning message)
  virtual ~BTNode() {}

  // to_string()
  virtual std::string to_string() {
    std::ostringstream os;
    os << data;
    return os.str();
  }
  
  //virtual std::string to_pretty_string();
};

// operator "<<" overloading for BTNode<T>
template<typename T> 
  std::ostream& operator<<(std::ostream& out, BTNode<T>& node) {
  return out << node.to_string();
}

//template<typename T> 
//  std::string BTNode<T>::to_pretty_string() {
//  //cout << *this->left; // to print out left node
//
//  std::string out;
//
//  std::string dat_l = this->left->to_string();
//  std::string dat_c = data.to_string();
//  std::string dat_r = this->right->to_string();
//
//  out = std::string(dat_l.length()-3,' ') + std::string(3,'_') + dat_c + std::string(3,'_');
//  out += "\n" + dat_l + std::string(dat_c.length(),' ') + dat_r;
//
//  return out;
//}

