#pragma once
#include <sstream>
#include "mt_tuple.h"

struct MNode {
  // Data Fields
  MTTuple data;
  MNode *left;
  MNode *right;
  MNode *parent;

  // Constructor
  MNode(const MTTuple& dat, 
         MNode* left_val=NULL,
         MNode* right_val=NULL,
         MNode* parent_val=NULL):
    data(dat), left(left_val), right(right_val), parent(parent_val) {}
  
  // Destructor (to avoid warning message)
  virtual ~MNode() {}

  // to_string()
  virtual std::string to_string() {
    std::ostringstream os;
    os << data;
    return os.str();
  }
};

// operator "<<" overloading for MNode<T>
std::ostream& operator<<(std::ostream &out, MNode &node) {
  return out << node.to_string();
}

// operator "<<" overloading for MNode<T>
std::ostream& operator<<(std::ostream &out, MNode *node) {
  return out << (*node).to_string();
}
