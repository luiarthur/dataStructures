#pragma once
#include <tuple>
#include <sstream>

struct MTTuple {
  int d;
  double x;
  double t;
  
  MTTuple() : d(-1), x(0), t(0) {}
  MTTuple(int dd, double xx, double tt) : d(dd), x(xx), t(tt) {}
};

// operator "<<" overloading for MTTuple
std::ostream& operator<<(std::ostream& out, MTTuple& tup) {
  std::ostringstream os;
  os << tup.d << "," << tup.x << "," << tup.t;
  return out << "(" + os.str() + ")";
}
