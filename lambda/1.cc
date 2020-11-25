#include <iostream>
#include <typeinfo>
using namespace std;



/*
C++11 函数对象的升级版 =》 lambda
函数对象的缺点：
灵活性太差  需要定义一个类出来

lambda表达式语法：
[捕获外部变量](形参列表)->返回值{操作代码};
[]不捕获任何外部变量

*/

auto sum(int a, int b)->int{return a+b;}



int main() {
	auto f = [](int a, int b) {return a+b;};
	cout << typeid(f).name() << endl;
	cout << sum(10, 20) << endl;
	return 0;
}
