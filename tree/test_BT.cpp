#include <iostream>
#include <tuple>
#include "BTNode.h"

using namespace std;

int main() {

  //tuple<int,double,double> dat(1,2,3);
  //tuple<int,double,double> dat1(2,4,6);
  //tuple<int,double,double> dat2(1,3,5);

  BTNode<int> bt_p(0);
  BTNode<int> bt_l(2);
  BTNode<int> bt_r(-1);
  BTNode<int> bt(4,&bt_l,&bt_r,&bt_p);

  cout << bt << endl;
  cout << "Check Parent:" << bt_p << " == " << *bt.parent << "?" << endl;
  cout << "Check Left:" << bt_l << " == " << *bt.left << "?" << endl;
  cout << "Check Right:" << bt_r << " == " << *bt.right << "?" << endl;

  //BTNode<int>* tom = new BTNode<int>(1);
  tuple<int,double,double> tup(1,2,3);
  BTNode< tuple<int,double,double> > bt_tup( tup );

  return 0;
}
