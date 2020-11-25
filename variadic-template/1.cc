#include <iostream>
#include <bitset>
#include <tuple>
#include <complex>
using namespace std;



namespace lsc{

// 递归的复合
template<typename...Types>
class tup;
template<> 
class tup<>{};

template<typename Head, typename...Tail> 
class tup<Head, Tail...> {
using composited = tup<Tail...>;
protected:
  composited m_tail;
  Head m_head;
public:
  tup() {}
  tup(Head v, Tail...vtail):m_head(v),m_tail(vtail...) {}

  Head head() {return m_head;}
  composited& tail() {return m_tail;}
};
}

int main() {
  lsc::tup<int, float, std::string> t1(30,12.5,"helloworld");
  cout << sizeof(t1) << endl;
  cout << t1.head() << endl;
  cout << t1.tail().head() << endl;
  cout << t1.tail().tail().head() << endl;

  lsc::tup<std::string, complex<int>, bitset<16>, double> t2(
    "ace", complex<int>(3,8), bitset<16>(277), 3.1415926);

  cout << sizeof(t2) << endl;
  cout << t2.head() << endl;
  cout << t2.tail().head() << endl;
  cout << t2.tail().tail().head() << endl;
  return 0;
}



#if 0
// 递归调用 处理的都是参数  使用函数模板
// 递归继承 处理的都是类型  使用类模板
namespace lsc {
template <typename...Types>
class tuple;

template <>
class tuple<> {};

template<typename Head, typename... Tail>
class tuple<Head, Tail...> : private tuple<Tail...>
{
  typedef tuple<Tail...> inherited;
  // using inherited = tuple<Tail...>;
public:
  tuple() {}
  tuple(Head v, Tail...vtail):m_head(v),inherited(vtail...) {}


  // typename Head::type head() {return m_head;}  Head::type
  // auto head()->decltype(m_head) {return m_head;}  需要前置声明m_head
  Head head(){return m_head;}
  inherited& tail() {return *this;}
protected:
  Head m_head;
};

template <typename Head, typename...Tail>
ostream& operator<<(ostream&os, lsc::tuple<Head, Tail...>& t) {
  os << t.head() << ",";
  operator<<(os, t.tail());
  return os;
}
template<typename T>
ostream& operator<<(ostream& os, tuple<T>& t) {
  os << t.head();
  return os;
}

}


int main() {
  lsc::tuple<int, float, string> t(233, 12.4, "helloworld");
  cout << t << endl;

  cout << sizeof(t) << endl;
  cout << t.head() << endl;
  cout << t.tail().head() << endl;
  cout << t.tail().tail().head() << endl;
  return 0;
}


#endif


#if 0
template <int IDX, int MAX, typename...Args>
struct PRINT_TUPLE {
  static void print(ostream& os, const tuple<Args...>& t) {
    os <<  get<IDX>(t) << (IDX+1==MAX?"":",");
    PRINT_TUPLE<IDX+1, MAX, Args...>::print(os, t);
  }  
};

template <int MAX, typename...Args>
struct PRINT_TUPLE<MAX,MAX,Args...> {
  static void print(std::ostream& os, const tuple<Args...>& t) {}
};


template <typename ...Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
  os << "[";
  PRINT_TUPLE<0, sizeof...(Args), Args...>::print(os,t);
  return os << "]";
}

int main() {
  cout << make_tuple(12.5, "helloworld", bitset<16>(233), 88) << endl;
  return 0;
}

#endif



#if 0
namespace  lsc{
  int maximum(int n) {
    return n;
  }

  template <typename... Args>
  int maximum(int n, Args...args) {
    return std::max(n, maximum(args...));
  }
}


// consexpr noexcept
int main() {
  std::cout << lsc::maximum(57, 48, 60, 100, 20, 18) << std::endl;
  return 0;
}

#endif


#if 0
namespace lsc{
template <typename _ForwardItetaor, typename _Compare>
_ForwardItetaor __max_element(_ForwardItetaor _first, _ForwardItetaor _last, _Compare _comp) {
  if (_first == _last) return _first;
  _ForwardItetaor res = _first;

  while (++ _first != _last) {
    if (_comp(res, _first)) {
      res = _first;
    }
  }
  return res;
}



struct _Iter_less_iter {
  template <typename _Iterator1, typename _Iterator2>
  bool operator()(_Iterator1 _it1, _Iterator2 _it2) const {
    return *_it1 < *_it2;
  }
};

inline _Iter_less_iter __iter__less_iter() {
  return _Iter_less_iter();
}


template <typename _ForwardItetator>
inline _ForwardItetator max_element(_ForwardItetator _first, _ForwardItetator _last) {
  return __max_element(_first, _last, __iter__less_iter());
}

template <typename Ty>
inline Ty max(initializer_list<Ty> _l) {
  return *max_element(_l.begin(), _l.end());
}

}

int main() {
  cout << lsc::max({33,11,54,78,9,35,68,93,22,35}) << endl;
  return 0;
}


#endif

// 类型和个数都可以变化
/*
参数个数  利用参数个数逐一减少的特性，实现递归函数调用 使用function template完成
参数类型  利用参数个数逐一减少 导致参数类型也逐一减少的特性 实现递归继承和递归复合 以class template完成
*/


// template <typename T, typename... Types>
// void func(const T& firstArg, const Types& ...args) {
//   func(args...);
// }


// void printf(const char *s) {
//   while (*s) {
//     if (*s == '%' && *(++s)!='%') {
//       throw std::runtime_error("invalid format string:missing arguments");
//     }
//     std::cout << *s++;
//   }
// }


// template <typename T, typename ...Args>
// void printf(const char *s, T value, Args ... args) {
//   while (*s) {
//     if (*s == '%' && *(++s)!='%') {
//       std::cout << value;
//       printf(++s, args...);
//       return ;
//     }
//     std::cout << *s++;
//   }
//   throw std::logic_error("extra arguments provided to printf");
// }

// int main() {
//   int *pi = new int;
//   printf("%d %s %p %f\n", 15, "This is Ace.", pi, 3.1415926);
//   delete pi;
//   return 0;
// }


// template<typename T>
// class Task;

// template<typename R, typename...Args>
// class Task<R(Args...)>
// {
// public:
//     Task(std::function<R(Args...)>&& f) : m_fn(std::move(f)) {}
//     Task(std::function<R(Args...)>& f) : m_fn(f) {}

//     R run(Args&&... args)
//     {
//         return m_fn(std::forward<Args>(args)...);
//     }

//     template <typename F>
//     auto then(F&& f) -> Task<typename std::result_of<F(R)>::type(Args...)>
//     {
//         using return_type = typename std::result_of<F(R)>::type;

//         auto func = std::move(m_fn);
//         return Task<return_type(Args...)>([func, &f](Args&&...args) {
//             return f(func(std::forward<Args>(args)...));
//         });
//     }

// private:
//     std::function<R(Args...)> m_fn;
// };

// void tesk()
// {
//   Task<int(int)> task([](int i) {return i; });

//   auto f = task.then([](int i) {return i + 1; })
//       .then([](int i) {return i + 2; })
//       .then([](int i) {return i + 3; });

//   auto result = f.run(0);

//   cout << "run task result:" << result << endl;
// }















#if 0
//#1

// 边界条件
void printX() {}

template <typename T, typename... Types>
void printX(const T& firstArg, const Types&...args) {
  cout << sizeof...(args) << endl;
  cout << firstArg << endl;
  
  printX(args...);
}

int main() {
  printX(7.5, "hello", std::bitset<16>(377), 42);
  return 0;
}
#endif