#include <iostream> // cin, cout
#include <fstream> // ofstream, streambuf
#include "../Binary_Tree.h"
#include "../mt_tuple.h"


using namespace std;

int main() {

  std::ofstream out("mytree.o");
  std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
  std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

  Binary_Tree<int> lT(1222);
  Binary_Tree<int> rT(3000);
  Binary_Tree<int> big(2,lT,rT);
  Binary_Tree<int> rbig(0,lT,big);
  Binary_Tree<int> rrbig(0,rbig,big);
  Binary_Tree<int> rrrbig(0,rbig,rrbig);
  Binary_Tree<int> rrrrbig(0,rrrbig, Binary_Tree<int>(0,rbig,rrrbig));

  cout << rrrrbig.to_string();

  std::cout.rdbuf(coutbuf); //reset to standard output again
  return 0;
}

// then in R/test_draw.R
//   use the draw_tree(readLines("../tmp.o")) to print
