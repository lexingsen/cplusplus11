template <int N>
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


template <int T1, int T2> 
struct sum
{
  enum {value = T1+T2};
};


template <int N, int M> 
struct add : public sum<N, M> {

};

int main() {
  Fib<20>::Value;
  add<10,20>::value;
  return 0;
}