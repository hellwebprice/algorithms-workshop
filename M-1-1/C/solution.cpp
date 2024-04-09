#include <cstdint>
#include <iostream>

int advanced_gcd(int a, int b, int64_t &x, int64_t &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  int64_t new_x, new_y;
  int gcd = advanced_gcd(b, a % b, new_x, new_y);
  x = new_y, y = new_x - a / b * new_y;

  return gcd;
}

bool find_solution(int a, int b, int c, int64_t &x, int64_t &y) {
  int gcd = advanced_gcd(std::abs(a), std::abs(b), x, y);
  if (c % gcd != 0)
    return false;

  x *= c / gcd;
  if (a < 0) {
    x = -x;
  }

  y *= c / gcd;
  if (b < 0) {
    y = -y, b = -b, a = -a;
  }

  while (x <= 0) {
    x += b / gcd;
    y -= a / gcd;
  }

  while (x > 0) {
    x -= b / gcd;
    y += a / gcd;
  }

  x += b / gcd;
  y -= a / gcd;

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
