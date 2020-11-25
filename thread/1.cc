#include <chrono>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <iostream>


/*
C++语言级别支持的多线程：代码跨平台 /windows/linux/mac
thread
mutex
conditon_variable
lock_guard
unique_lock
atomic 原子类型 基于CAS操作的原子类型 线程安全的
sleep_for

strace ./a.out
 * */
void fun() {
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "thread!" << std::endl;
}


int main() {
	// 定义了一个线程对象 传入一个线程函数
	std::thread t1([]() {std::cout << "hello world!" << std::endl;});

	t1.join();
	std::thread t2(fun);
	t2.join();
	return 0;
}

