#include <iostream>
using namespace std;



namespace lsc {
// 类型萃取实现


template <typename>
struct __is_void_helper:public false_type {};


template <>
struct __is_void_helper<void>:public true_type {};



template <typename Ty>
struct  is_void:public __is_void_helper<typename remove_cv<Ty>::type>::type {

};


template<typename Ty>
struct remove_const {
  typedef Ty type;
};

template<typename Ty>
struct remove_const<Ty const> {
  typedef Ty type;
};

template<typename Ty>
struct remove_volatile {
  typedef Ty type;
};

template<typename Ty>
struct remove_volatile<Ty volatile> {
  typedef Ty type;
};


template <typename Ty>
struct remove_cv {
  typedef typename remove_const<typename remove_volatile<Ty>>::type type;
};


}