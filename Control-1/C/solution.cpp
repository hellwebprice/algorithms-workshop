#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  for (int _ = 0; _ < t; ++_) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &p : a) {
      std::cin >> p;
    }

    std::sort(a.begin(), a.end());

    long long result = 0;
    for (int i = 0; i < n / 2; ++i) {
      result += a[n - 1 - i] - a[i];
    }
    std::cout << result << std::endl;
  }
  return 0;
}
