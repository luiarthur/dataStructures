#include <iostream> // cin, cout
#include <fstream> // ofstream, streambuf
#include "../Binary_Tree.h"


using namespace std;

int main() {

  Binary_Tree<int> lT(1);
  Binary_Tree<int> rT(3);
  Binary_Tree<int> big(2,lT,rT);
  Binary_Tree<int> rbig(0,lT,big);
  Binary_Tree<int> rrbig(0,rbig,big);
  Binary_Tree<int> rrrbig(0,rbig,rrbig);


  std::ofstream out("mytree.o");
  std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
  std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

  cout << rrrbig.to_string();
  std::cout.rdbuf(coutbuf); //reset to standard output again

  return 0;
}

// then in R/test_draw.R
//   use the draw_tree(readLines("../tmp.o")) to print
