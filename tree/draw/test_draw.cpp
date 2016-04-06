#include <iostream>
#include "../Binary_Tree.h"


using namespace std;

int main() {

  Binary_Tree<int> lT(1);
  Binary_Tree<int> rT(3);
  Binary_Tree<int> big(2,lT,rT);
  Binary_Tree<int> rbig(0,lT,big);
  Binary_Tree<int> rrbig(0,rbig,big);

  cout << rrbig.to_pretty_string();

  return 0;
}
