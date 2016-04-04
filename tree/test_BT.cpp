#include <iostream>
#include <tuple>
#include "BTNode.h"
#include "mt_tuple.h"
#include "Binary_Tree.h"
#include "print_tree.h"

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

  cout << *node_center.left << endl;
  cout << node_center.left->data.d << endl;
  cout << node_center << endl;

  cout << "\nAnother Example:\n" << endl;

  Binary_Tree<MTTuple> lT(tup_l);
  Binary_Tree<MTTuple> rT(tup_r);
  Binary_Tree<MTTuple> big(tup_c,lT,rT);

  Binary_Tree<MTTuple> rbig(tup_c,big,rT);
  Binary_Tree<MTTuple> rrbig(tup_root,lT,rbig);

  cout << rrbig;

  cout << "\n\nLeft subtree:\n" << rrbig.get_left_tree().to_string();
  cout << "\n\nRight subtree:\n" << rrbig.get_right_tree().to_string();
  cout << "\n\ndata: " << rrbig.get_data() << endl;

  //Binary_Tree<MTTuple> empty_Tree();
  //cout << "\n\nEmpty: " << empty_Tree << endl;

  return 0;
}
