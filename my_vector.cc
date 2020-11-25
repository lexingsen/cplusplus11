#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;



namespace lsc{

template <typename T>
struct Allocator {
	T* allocate(size_t size) {
		return (T*)malloc(sizeof(T)*size);
	}

	void deallocate(void *p) {
		free(p);
	}

	/*void construct(T *p, const T &val) {
		new (p) T(val);
	}

	void construct(T *p, T &&val) {
		new (p) T(std::move(val));
	}*/

	template <typename Ty>
	void construct(T *p, Ty &&val) {
		new (p) T(std::forward<Ty>(val));
	}

	void destroy(T* p) {
		p->~T();
	}
};


template <typename T, typename Alloc=Allocator<T>>
class vector {
private:
  T *_first;
  T *_last;
  T *_end;
  Alloc _allocator; // 增加空间配置器成员处理vector成员 内存开辟 内存释放 对象构造 对象析构
  
public:
  vector(int size=10) {
    // _first = new T[size];
    _first = _allocator.allocate(size); // 仅仅开辟内存
    _end = _first+size;
    _last = _first;
  }

  vector(const vector<T>& src) {
    int size=src._end - src._first;
    // _first = new T[size];
    _first = _allocator.allocate(size);
    int len = _last-_first;
    for (int i=0; i<len; ++i) {
      // _first[i] = src._first[i];
      _allocator.construct(_first[i], src._first[i]); // 构造对象
    }
    _last = _first + len;
    _end = _first + size;
  }

  vector<T>& operator=(const vector<T>& src) {
    if (this == &src) {
      return *this;
    }
    delete[] _first;
    int size = src._end - src._first;
    int len = src._last - src._first;
    _first = new T[size];
    for (int i=0; i<len; ++i) {
      _first[i] = src._first[i];
    }
    _last = _first + len;
    _end = _first + size;
    return *this;
  }



  ~vector() {
    // delete[] _first;  1.首先析构有效的对象元素  2.释放空间
    int len = _last - _first;
    for (T* p=_first; p!=_last; ++p) {
		_allocator.destroy(p);// 析构有效对象
	} 
	_allocator.deallocate(_first); // 释放内存
    _first = _last = _end = nullptr;
  }

  // void push_back(const T &x) {
  //   if (full()) {
  //     resize();
  //   }
  //   // *_last ++ = x;
  //   _allocator.construct(_last, x);
  //   _last ++;
  // }

  void pop_back() {
    if (empty()) {
      return;
    }
    -- _last;
    _allocator.destroy(_last);
  }


  template <typename Ty>
  void push_back(Ty &&x) {
    if (full()) {
      resize();
    }
    _allocator.construct(_last, std::forward<Ty>(x));
    _last ++;
  }

  T back() const {
    if (empty()) {

    }
    return *(_last-1);
  }

  bool full() {
    return _end == _last;
  }

  bool empty() {
    return _last == _first;
  }

  int size() {
    return _last - _first;
  }

  void resize() {
    int size=_end-_first;
    // T *tmp = new T[2*size];
    T* tmp = _allocator.allocate(2*size);
    int len = _last-_first;
    for(int i=0; i<len; ++i) {
      _allocator.construct(tmp+i, _first[i]);
    }
    // delete[] _first;
    for (T *p=_first; p!=_last; ++p) {
		_allocator.destroy(p);
	}
	_allocator.deallocate(_first);
    _first = tmp;
    _end = _first + 2*size;
    _last = _first + len;
  }


  T& operator[](int index) {
    if (index < 0 || index >= size()) {
      throw "index out of range Exception";
    }
    return _first[index];
  }

  // 迭代器一般实现成容器的嵌套类型
  class iterator {
  private:
    T *_ptr;
  public:
    iterator(T *ptr=nullptr) :_ptr(ptr) {}
    bool operator!=(const iterator& it) const {
      return _ptr != it._ptr;
    }

    void operator++() {
      _ptr ++;
    }
    T& operator*() {return *_ptr;} // *it=x;
    const T& operator*() const {return *_ptr;}
  };

  iterator begin() {return iterator(_first);}
  iterator end() {return iterator(_last);}
};

struct Test {
  Test() {
    cout << "Test()" << endl;
  }

  ~Test() {
    cout << "~Test()" << endl;
  }

  Test(const Test &t) {
    cout << "Test(const Test&)" << endl;
  }

  Test& operator=(const Test& t) {
    cout << "operator=(const Test&)" << endl;
  }

  Test(Test &&x) {
    cout << "Test(Test&&)" << endl;
  }

  Test& operator=(Test&& x) {
    cout << "operator=(Test &&)" << endl;
  }
};
}

/*
底层是链表 哈希表 红黑树   []运算符重载不能使用在这些容器中
*/

int main() {
  vector<int> v;
  for (int i=0; i<20; ++i) {
    v.push_back(rand() % 100 + 1);
  }

  for (auto it=v.begin(); it!=v.end(); ++it) {
    if (*it % 2==0) {
      v.erase(it);// insert(it, val) erase(it)
    }
  }
  return 0;
}



#if 0
int main() {
  vector<int> vec;
  for (int i=0; i<10; ++i) vec.push_back(rand() % 100 + 1);
  auto it = vec.begin();
  for(; it!=vec.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  for (int i=0; i<vec.size(); ++i) {
    cout << vec[i] << " ";
  }
  cout << endl;


  // for_each的方式
  for (int val: vec) { // 其底层原理就是通过容器的迭代器来实现容器的遍历的
    cout << val << " ";
  }
  cout << endl;
  return 0;
}

#endif