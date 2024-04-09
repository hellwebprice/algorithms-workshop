#include <algorithm>
#include <iostream>

int main(void) {
  int n;
  std::cin >> n;

  int d_by_3 = 0, d_by_5 = 0, d_by_15 = 0, max = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    if (a % 15 == 0 && a >= d_by_15) {
      max = std::max(max, d_by_15);
      d_by_15 = a;
    } else {
      max = std::max(max, a);
      if (a % 3 == 0) {
        d_by_3 = std::max(d_by_3, a);
      } else if (a % 5 == 0) {
        d_by_5 = std::max(d_by_5, a);
      }
    }
  }

  std::cout << std::max(1LL * max * d_by_15, 1LL * d_by_5 * d_by_3)
            << std::endl;

  return 0;
}
