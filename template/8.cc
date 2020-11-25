#include <type_traits>



namespace lsc {
  template<typename T>
  struct is_floating_point {
    static constexpr bool value  = false;
  };

  template<>
  struct is_floating_point<double> {
    static constexpr bool value  = true;
  };

  template<>
  struct is_floating_point<float> {
    static constexpr bool value  = true;
  };

  template<>
  struct is_floating_point<long double> {
    static constexpr bool value  = true;
  };


  template<typename T>
  constexpr bool is_floating_ponit_f() {
    return false;
  }

  template<>
  constexpr bool is_floating_ponit_f<double>() {
    return true;
  }
  template<>
  constexpr bool is_floating_ponit_f<long double>() {
    return true;
  }
  template<>
  constexpr bool is_floating_ponit_f<float>() {
    return true;
  }
}

int main() {
  std::is_floating_point<int>::value;
  lsc::is_floating_point<double>::value;
  lsc::is_floating_point<float>::value;
  lsc::is_floating_point<long double>::value;

  auto res = lsc::is_floating_ponit_f<double>();
  return 0;
}