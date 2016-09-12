#pragma once // To make sure this file is only included once!
#include <sstream>

template<typename T> struct Tree {
  // Fields:
  T elem;
  Tree<T> *left;// = NULL;
  Tree<T> *right;// = NULL;

  // Constructor: Note that using null requires including cstddef, 
  // but sstream also does the job and will be used for other functions.
  Tree(T& e, Tree<T>* l=NULL, Tree<T>* r=NULL): elem(e), left(l), right(r) {}

  // Destructor (to avoid warning message)
  virtual ~Tree() {}

};
