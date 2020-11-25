#include <type_traits>
#include <functional>
// 模板的特化相当于分支语句  if else

template <typename T>
struct demo {
  using const T*=T;
  typedef type T;
};


template <typename T>
struct demo<T*> {
  using const T=T;
};

int main() {
  // 1.检查类型
  std::is_integral<int>::value;
  std::is_integral<bool>::value;
  std::is_integral<char>::value;
  std::is_integral<long>::value;

  std::is_floating_point<double>::value;
  std::is_floating_point<float>::value;
  std::is_floating_point<long double>::value;

  std::is_void<void>::value;


  //2.数组  类 枚举 联合体 指针 函数 左值引用 右值引用
  int a[10] = {0};
  struct b {};
  enum c {};
  union d{};
  int *f = nullptr;
  std::function<void(int)> g;
  const int &h = 20;
  int i=30;
  int &j=i;
  int &&k=30;

  std::is_array<int[]>::value;
  std::is_class<b>::value;
  std::is_enum<c>::value;
  std::is_union<d>::value;
  std::is_pointer<int*>::value;
  std::is_function<void(int,int)>::value;

  using left_ref = int&;
  using right_ref = int&&;
  std::is_lvalue_reference<left_ref>::value;
  std::is_rvalue_reference<right_ref>::value;
  return 0;
}