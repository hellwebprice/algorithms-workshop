#include <cstdint>
#include <iostream>

bool find_solution(int a, int b, int c, int64_t &x, int64_t &y) {
  if (b == 0) {
    if (c % a != 0) {
      return false;
    }
    x = c / a, y = 0;
    return true;
  }

  x = 1, y = 0;
  int64_t x2 = 0, y2 = 1, c1 = a, c2 = b;
  if (c1 < 0) {
    x = -x, c1 = -c1;
  }

  if (c2 < 0) {
    y2 = -y2, c2 = -c2;
  }

  if (c2 > c1) {
    std::swap(x, x2);
    std::swap(y, y2);
    std::swap(c1, c2);
  }

  while (c2 != 0) {
    int64_t k = c1 / c2;
    c1 -= k * c2;
    x -= k * x2;
    y -= k * y2;
    std::swap(x, x2);
    std::swap(y, y2);
    std::swap(c1, c2);
  }

  if (c % c1 != 0) {
    return false;
  }

  x *= c / c1, y *= c / c1;

  if (b < 0) {
    b = -b, a = -a;
  }

  while (x <= 0) {
    x += b / c1, y -= a / c1;
  }

  while (x > 0) {
    x -= b / c1, y += a / c1;
  }

  x += b / c1, y -= a / c1;

  return true;
}

int main(void) {
  int a, b, c;
  std::cin >> a >> b >> c;
  int64_t x, y;
  if (find_solution(a, b, c, x, y)) {
    std::cout << x << ' ' << y << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
