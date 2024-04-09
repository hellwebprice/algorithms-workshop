#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

  int t;
  std::cin >> t;

  for (int i = 0; i < t; ++i) {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for (auto &k : a) {
      std::cin >> k;
    }
    std::sort(a.begin(), a.end());

    long long water = 0;
    auto prev = a.begin();
    std::vector<int>::iterator cur;
    for (;;) {
      cur = std::upper_bound(prev, a.end(), *prev);
      if (cur == a.end() ||
          water + 1LL * (*cur - *prev) * (cur - a.begin()) > x) {
        break;
      }
      water += 1LL * (*cur - *prev) * (cur - a.begin());
      prev = cur;
    }
    int h = *prev + (x - water) / (cur - a.begin());
    std::cout << h << std::endl;
  }

  return 0;
}
