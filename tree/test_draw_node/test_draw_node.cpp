#include <iostream>
#include "../mt_tuple.h"
#include "../Binary_Tree.h"
#include "../print_tree.h"
#include "../MNode.h"

using namespace std;

int main() {

  MTTuple tup_root;
  MTTuple tup_c(4,5,6);
  MTTuple tup_l(1,2,3);
  MTTuple tup_r(7,8,9);
  BTNode<MTTuple> node_root(tup_root);
  BTNode<MTTuple> node_l(tup_l);
  BTNode<MTTuple> node_r(tup_r);
  BTNode<MTTuple> node_center(tup_c,&node_l,&node_r);

  //cout << node_center.to_pretty_string() << endl;;
  Binary_Tree<MTTuple> lT(tup_l);
  Binary_Tree<MTTuple> rT(tup_r);
  Binary_Tree<MTTuple> cT(tup_c);
  Binary_Tree<MTTuple> big(tup_c,lT,cT);

  Binary_Tree<MTTuple> rbig(tup_c,big,rT);
  Binary_Tree<MTTuple> rrbig(tup_root,lT,rbig);

  cout << "\nrrbig Tree:\n" << endl;
  cout << rrbig;

  rrbig.print();

  return 0;
}
