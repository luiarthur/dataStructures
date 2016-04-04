#include <iostream>
#include "../Binary_Tree.h"

using namespace std;

int main() {
  cout << "Results: ###############################################" << endl;

  //Binary_Tree<int> lT(1);
  //Binary_Tree<int> rT(3);
  //Binary_Tree<int> big(2,lT,rT);
  //Binary_Tree<int> rbig(0,lT,big);

  //cout << rbig << endl;
  //cout << rbig.to_pretty_string() << endl;



  BTNode<int> lN(1);
  BTNode<int> rN(3);
  BTNode<int> node_c(2,&lN,&rN);
  cout << node_c << endl;

  return 0;
}
