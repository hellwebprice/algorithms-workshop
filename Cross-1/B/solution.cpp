#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

int main(void) {

  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  std::vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> x[i] >> y[i];
  }

  size_t mid = n / 2;
  std::nth_element(x.begin(), x.begin() + mid, x.end());
  std::nth_element(y.begin(), y.begin() + mid, y.end());

  long long result = 0;
  for (int i = 0; i < n; ++i) {
    result += 1LL * std::abs(x[i] - x[mid]) + std::abs(y[i] - y[mid]);
  }
  std::cout << result << std::endl;

  return 0;
}
