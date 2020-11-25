template <int L, int R>
struct min {
  static const int value = (L < R)?L:R;
};

int main() {
  min<10,20>::value;
  return 0;
}