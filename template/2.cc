#include <iostream>
#include <string>
using namespace std;

namespace lsc {
template <typename T>
inline bool max(const T a, const T b) {
  return a>b?a:b;
}

template <int N, int M>
struct add {
  static const int value = N+M;
};

using ull=uint64_t;
template<ull N>
struct Fib {
  enum {Value = Fib<N-1>::Value + Fib<N-2>::Value};
};

template<>
struct Fib<1> {
  enum {Value = 1};
};

template<>
struct Fib<2> {
  enum {Value = 1};
};

}

// cat main.c | wc -l

int main() {
  cout << lsc::max(1,2) << endl;
  cout << lsc::max(12.3, 22.4) << endl;
  cout << lsc::max("hello", "world") << endl;
  lsc::add<10,20>::value;
  lsc::Fib<500>::Value;
  return 0;
}