#include <iostream>
using namespace std;



class Test {
private:
  int ma;
public:
  Test(int data=10):ma(data) {
    cout << "Test(int)" << endl;
  }
  ~Test() {
    cout << "~Test()" << endl;
  }

  Test(const Test& src):ma(src.ma) {
    cout << "Test(const Test&)" << endl;
  }

  void operator=(const Test &src) {
    cout << "operator=" << endl;
    ma = src.ma;
  }

  int getData() const
  {
    return ma;
  }
};

// 不能返回局部或临时对象的指针或引用
Test getObject(Test& t) {
  // int val = t.getData();
  // Test tmp(val);
  int val = t.getData();
  return Test(val);
  // 用临时对象拷贝构造一个新对象  临时对象就不产生了  Test t = Test(30) Test t(30)
}

/*
对象优化的三条规则：
1.函数参数传递过程过程中，对象优先按照引用传递，不要按值传递
2.函数返回对象时，尽量优先返回一个临时对象，而不要返回一个定义过的对象  减少一次临时对象的构造和析构
3.接受函数返回值是对象的函数时，要用初始化的方式接受，不要用赋值的方式接受
*/


// 11->9->7->4
int main() {
  Test t1; // Test(int)
  Test t2 = getObject(t1); // Test(int)
  // ~Test()
  // ~Test()

  return 0;

  // cout << "=======================" << endl;
  // t1 = getObject(t1);
  // cout << "=======================" << endl;
  // return 0;
}




#if 0
int main() {
  Test t1; // Test(int)
  Test t2; // Test(int)
  cout << "===========" << endl;
  t2 = getObject(t1);
  cout << "===========" << endl;
  //实参到形参  初始化
  // Test(const Test&) Test(int) operator=
  return 0; 
}
#endif 



















// class Test {
// private:
//   int ma;
//   int mb; 
// public:
//   Test(int a=5, int b=5):ma(a),mb(b) {
//     cout << "Test(int, int)" << endl;
//   }

//   ~Test() {
//     cout << "~Test()" << endl;
//   }

//   Test(const Test &src):ma(src.ma), mb(src.mb) {
//     cout << "Test(const Test&)" << endl;
//   }

//   void operator=(const Test &src) {
//     ma = src.ma;
//     mb = src.mb;
//     cout << "operator=" << endl;
//   }
// };



// Test t1(10,10);

// int main() {
//   Test t2(20,20);
//   Test t3 = t2;
//   static Test t4 = Test(30,30);
//   t2 = Test(40,40);
//   t2 = (Test)(50,50);
//   t2 = 60;
//   cout << "----------------------" << endl;
//   Test *p1 = new Test(70,70); // 不是临时对象 heap 只有delete的时候才析构
//   cout << "----------------------" << endl;
//   Test *p2 = new Test[2];
//   cout << "----------------------" << endl;
//   Test *p3 = &Test(80, 80); // 临时对象
//   cout << "----------------------" << endl;
//   const Test &p4 = Test(90, 90); // 临时对象 提升为 栈对象的生成周期
//   cout << "----------------------" << endl;
//   delete p1; 
//   delete p2;
// }

// Test t5(100,100);


// class Test {
// public:
//   Test(int a=10):ma(a) {cout << "Test(int)" << endl;}
//   ~Test() {cout << "~Test()" << endl;}
//   Test(const Test& t):ma(t.ma) {cout << "Test(const Test&)" << endl;}
//   Test& operator=(const Test &t) {
//     cout << "operator=" << endl;
//     ma = t.ma;
//     return *this;
//   }
// private:
//   int ma;
// };


// int main() {
//   Test *p = &Test(40);
//   // p指向的是一个已经析构的临时对象

//   const Test &ref = Test(50);
//   cout << "-----------------" << endl;
//   return 0;
// }


// int main() {
//   Test t1;
//   Test t2(t1);
//   Test t3 = t1;
//   // Test(20)显式生成临时对象  生存周期：所在的语句
//   // C++编译器队友对象构造的优化：用临时对象生成新对象的时候，临时对象就不产生了，直接构造新对象就可以了
//   Test t4 = Test(20); // Test t4(20);没有区别的
//   cout << "==========" << endl;

//   t4 = t2;


//   // 显式生成临时对象
//   t4 = Test(30);// 临时对象生成   语句结束时，临时对象析构
//   cout << "==========" << endl;

//   // 显式生成临时对象
//   t4 = (Test)30; // int->Test   
//   cout << "==========" << endl;
//   t4 = 100; // 隐式构造 
//   cout << "==========" << endl;
//   return 0;
// }
