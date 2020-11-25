#include <iostream>
using namespace std;


namespace lsc{
template<typename T>
class complex {
private:
  T re, im;
public:
  complex(T r=0, T i=0):re(re), im(i) {}

  complex& operator+=(const complex&);
  T real() const {return re;}
  T imag() const {return im;}
};


}
