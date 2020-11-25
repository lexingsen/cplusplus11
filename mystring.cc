#include <iostream>
#include <cstring>
using namespace std;


class MyString {
private:
  char *mptr;
public:
  MyString(const char *str=nullptr) {
    cout << "MyString(const char *str)" << endl;
    if (str != nullptr) {
      mptr = new char[strlen(str)+1];
      strcpy(mptr, str);
    } else {
      mptr = new char[1];
      *mptr = '\0';
    }
  }

  ~MyString() {
    cout << "~MyString()" << endl;
    delete[] mptr;
    mptr = nullptr;
  }


  MyString(const MyString& src) {
    cout << "MyString(const MyString&)" << endl;
    mptr = new char[strlen(src.mptr)+1];
    strcpy(mptr, src.mptr);
  }

  MyString& operator=(const MyString& src) {
    cout << "operator=(const MyString&)" << endl;
    if (this == &src) {
      return *this;
    }
    delete[] mptr;
    mptr = new char[strlen(src.mptr)+1];
    strcpy(mptr, src.mptr);
    return *this;
  }

  MyString(MyString&& src) {
    cout << "MyString(MyString &&)" << endl;
    mptr = src.mptr;
    src.mptr = nullptr;
  }

  const char* c_str() const {
    return mptr;
  }
};


MyString getString(MyString& str) {
  const char *ptr = str.c_str();
  MyString res(ptr);
  return res;
}



/*
必须要创建函数中间的临时对象
接受返回的对象必须以赋值的方式接受,不能以初始化的方式接收
*/




int main() {
  MyString s1("aaaaaaaaaaaaa");
  MyString s2;
  s2 = getString(s1);
  return 0;
}