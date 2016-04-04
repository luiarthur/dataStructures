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
};

// operator "<<" overloading for BTNode<T>
template<typename T> 
  std::ostream& operator<<(std::ostream& out, BTNode<T>& node) {
  return out << node.to_string();
}


/////////////////////////////////////////////////////////////////////////
// print integers
int length_int (int x) {
  int len = 0;
  for(; x != 0; x /= 10, len++);
  return len;
}
// Work in Progress
std::string pretty_string(BTNode<int> &node) {
  std::ostringstream os;
  std::string s="I AM PRETTY: \n";
  int c_node = length_int(node.data);
  int l_node = length_int((node.left)->data);
  int r_node = length_int((node.right)->data);

  os << s << "Length of c_node: " << c_node
        << "\nLength of l_node: " << l_node
        << "\nLength of r_node: " << r_node;

  return os.str();
}
