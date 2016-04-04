#include <iostream>
#include "../MNode.h"

using namespace std;

int main() {

  cout << "Results: ###############################################" << endl;

  MTTuple tup_root;
  MTTuple tup_c(4,5,6);
  MTTuple tup_l(1,2,3);
  MTTuple tup_r(7,8,9);

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
  cout << "mn_cluster.r:  " << mn_cluster.right<< endl;


  return 0;
}
