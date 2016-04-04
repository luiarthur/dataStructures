#pragma once
#include <tuple>
#include <sstream>

struct MTTuple {
  int d;
  double x;
  double t;
  
  MTTuple() : d(-1), x(0), t(0) {}
  MTTuple(int dd, double xx, double tt) : d(dd), x(xx), t(tt) {}

  // to_string()
  virtual std::string to_string() {
    std::ostringstream os;
    os << d << "," << x << "," << t;
    return "(" + os.str() + ")";
  }
};

// operator "<<" overloading for MTTuple => string: (d,x,t)
std::ostream& operator<<(std::ostream& out, MTTuple& tup) {
  return out << tup.to_string();
}
