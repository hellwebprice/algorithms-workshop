#include <iostream>
#include <vector>

int main(void) {

  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  size_t n, t;
  std::cin >> n >> t;
  std::vector<size_t> to(n - 1);
  for (size_t i = 0; i < n - 1; ++i) {
    std::cin >> to[i];
    to[i] += i;
  }

  size_t cur = 0;
  while (cur < to.size()) {
    cur = to[cur];
    if (cur == t - 1) {
      std::cout << "YES" << std::endl;
      return 0;
    }
  }

  std::cout << "NO" << std::endl;
  return 0;
}
