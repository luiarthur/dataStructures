#include <iostream>
#include <tuple>
#include "BTNode.h"
#include "mt_tuple.h"
#include "Binary_Tree.h"
#include "print_tree.h"

using namespace std;

int main() {

  MTTuple mt_p;
  MTTuple mt(1,2,3);
  MTTuple mt_l(4,5,6);
  MTTuple mt_r(7,8,9);
  BTNode<MTTuple> bmt_p(mt_p);
  BTNode<MTTuple> bmt_l(mt_l);
  BTNode<MTTuple> bmt_r(mt_r);
  BTNode<MTTuple> bmt(mt,&bmt_l,&bmt_r,&bmt_p);

  cout << *bmt.left << endl;
  cout << bmt.left->data.d << endl;
  cout << bmt << endl;

  cout << "\nAnother Example:\n" << endl;

  Binary_Tree<MTTuple> lT(mt_l);
  Binary_Tree<MTTuple> rT(mt_r);
  Binary_Tree<MTTuple> big(mt,lT,rT);

  cout << big;
  //Binary_Tree<MTTuple> rbig(dat,big,rT);
  //Binary_Tree<MTTuple> rrbig(dat,lT,rbig);

  //cout << rrbig;

  return 0;
}
