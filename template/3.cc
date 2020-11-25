#include <iostream>
#include <type_traits>
#include <vector>
#include <list>
#include <complex>
using std::cout;
using std::endl;
using std::basic_string;
using namespace std;

namespace lsc {
  template <typename T>
  void type_traits_output(const T& x) {
    cout << "type name\t" << typeid(x).name() << endl;
    cout << "is_void\t" << is_void<T>::value << endl;
    cout << "is_integral\t" << is_integral<T>::value << endl;
    cout << "is_float_point\t" << is_floating_point<T>::value << endl;
    cout << "is_arithmetic\t" << is_arithmetic<T>::value << endl;
    cout << "is_signed\t" << is_signed<T>::value << endl;
    cout << "is_unsigned\t" << is_unsigned<T>::value << endl;
    cout << "is_const\t" << is_const<T>::value << endl;
    cout << "is_volatile\t" << is_volatile<T>::value << endl;
    cout << "is_class\t" << is_class<T>::value << endl;
    cout << "is_function\t" << is_function<T>::value << endl;
    cout << "is_reference\t" << is_reference<T>::value << endl;
    cout << "is_pod\t" << is_pod<T>::value << endl;
    cout << "is_lvalue_reference\t" << is_lvalue_reference<T>::value << endl;
    cout << "is_rvalue_reference\t" << is_rvalue_reference<T>::value << endl;
    cout << "is_pointer\t" << is_pointer<T>::value << endl;
    cout << "is_member_pointer\t" << is_member_pointer<T>::value << endl;
    cout << "is_member_object_pointer\t" << is_member_object_pointer<T>::value << endl;
    cout << "is_member_function_pointer\t" << is_member_function_pointer<T>::value << endl;
    cout << "is_fundamental\t" << is_fundamental<T>::value << endl;
    cout << "is_scalar\t" << is_scalar<T>::value << endl;
    cout << "is_object\t" << is_object<T>::value << endl;
    cout << "is_compound\t" << is_compound<T>::value << endl;
    cout << "is_standard_layout\t" << is_standard_layout<T>::value << endl;
    cout << "has_virtual_destructor\t" << has_virtual_destructor<T>::value << endl;

    cout << "is_polymorphic\t" << is_polymorphic<T>::value << endl;

    
    cout << "is_trivially_constructible\t" << is_trivially_constructible<T>::value << endl;
    cout << "is_trivially_copy_assignable\t"  << is_trivially_copy_assignable<T>::value << endl;
    // cout << "is_trivially_assignable\t"  << is_trivially_assignable<T>::value << endl;
    cout << "is_trivially_move_constructible\t"  << is_trivially_move_constructible<T>::value << endl;
    cout << "is_trivially_move_assignable\t"  << is_trivially_move_assignable<T>::value << endl;
    cout << endl;
  }


  typedef basic_string<char> string;
  typedef basic_string<wchar_t> wstring;
  typedef basic_string<char16_t> u16string;
  typedef basic_string<char32_t> u32string;
  class Foo {
  private:  
    int d1,d2;
  };

  class Goo {
    private:
      int d1,d2;
    public:
      virtual ~Goo() {}
  };

  class Zoo {
  public:
    Zoo(int i1, int i2):d1(i1),d2(i2) {}
    Zoo(const Zoo&) = delete;
    Zoo(Zoo &&) = default;
    Zoo& operator=(const Zoo&) = default;
    Zoo& operator=(Zoo &&) = delete;

    virtual ~Zoo() {}
  private:
    int d1,d2;
  };
}




int main() {
  lsc::type_traits_output(10); 
  lsc::type_traits_output(lsc::string("helloworld"));
  lsc::type_traits_output(std::string("hello world"));
  lsc::type_traits_output(lsc::Foo());
  lsc::type_traits_output(lsc::Goo());
  lsc::type_traits_output(lsc::Zoo(10,20));

  lsc::type_traits_output(std::list<int>());
  return 0;
}