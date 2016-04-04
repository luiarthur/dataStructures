#include <iostream>
#include "../Binary_Tree.h"

using namespace std;

int main() {
  cout << "Results: ###############################################" << endl;

  Binary_Tree<int> lT(1);
  Binary_Tree<int> rT(3);
  Binary_Tree<int> big(2,lT,rT);
  Binary_Tree<int> rbig(0,lT,big);

  cout << rbig << endl;
  cout << rbig.to_pretty_string() << endl;

  return 0;
}
