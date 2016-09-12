#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
  cout << "Results: ###############################################" << endl;

  int x = 1;
  Tree<int> tree(x);
  cout << tree.elem << endl;
} 
