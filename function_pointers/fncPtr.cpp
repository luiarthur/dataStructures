#include <iostream>

using namespace std;

double f_double(double x) {return x * 2;}
double f_triple(double x) {return x * 3;}

double f_flex (double x, double (*f)(double)) {
  return f(x);
}

int main() {

  cout << f_double(3) << endl;
  cout << f_triple(3) << endl;
  cout << f_flex(3,f_double) << endl;
  cout << f_flex(3,f_triple) << endl;

  return 0;
}

// To Compile: g++ fncPtr.cpp
// To run: ./a.out
