#include <iostream>
#include <tuple>
#include "BTNode.h"
#include "mt_tuple.h"
#include "Binary_Tree.h"
#include "print_tree.h"
#include "MNode.h"

using namespace std;

int main() {

  cout << "Results: ###############################################" << endl;

  MTTuple tup_root;
  MTTuple tup_c(4,5,6);
  MTTuple tup_l(1,2,3);
  MTTuple tup_r(7,8,9);
  BTNode<MTTuple> node_root(tup_root);
  BTNode<MTTuple> node_l(tup_l);
  BTNode<MTTuple> node_r(tup_r);
  BTNode<MTTuple> node_center(tup_c,&node_l,&node_r);

  cout <<"Center Node => Left:          "<< *node_center.left << endl;
  cout <<"Center Node => Left => delta: "<< node_center.left->data.d << endl;
  cout <<"Center Node:                  "<< node_center << endl;

  Binary_Tree<MTTuple> lT(tup_l);
  Binary_Tree<MTTuple> rT(tup_r);
  Binary_Tree<MTTuple> cT(tup_c);
  Binary_Tree<MTTuple> big(tup_c,lT,cT);

  Binary_Tree<MTTuple> rbig(tup_c,big,rT);
  Binary_Tree<MTTuple> rrbig(tup_root,lT,rbig);

  cout << "\nrrbig Tree:\n" << endl;
  cout << rrbig;

  cout << "\n\nLeft subtree:\n" << rrbig.get_left_tree().to_string();
  cout << "\n\nRight subtree:\n" << rrbig.get_right_tree().to_string();
  cout << "\n\ndata: " << rrbig.get_data() << endl;

  //Binary_Tree<MTTuple> empty_Tree();
  //cout << "\n\nEmpty: " << empty_Tree << endl;

  cout << "\n\nTest Mondrian Node:" << endl;
  MNode mn_root(tup_root);
  MNode mn_c(tup_c);
  MNode mn_r(tup_r);
  MNode mn_l(tup_l);
  cout << "     mn_root:  " << mn_root << endl;
  cout << "        mn_c:  " << mn_c << endl;
  cout << "        mn_l:  " << mn_l << endl;
  cout << "        mn_r:  " << mn_r << endl;
  cout << "mn_root.data:  " << mn_root.data << endl;
  MNode mn_cluster(tup_c,&mn_l,&mn_r,&mn_root);
  cout << endl;
  cout << "mn_cluster.p:  " << mn_cluster.parent << endl;
  cout << "mn_cluster.d:  " << mn_cluster << endl;
  cout << "mn_cluster.l:  " << mn_cluster.left << endl;
  cout << "mn_cluster.r:  " << mn_cluster.right << endl;

  return 0;
}
