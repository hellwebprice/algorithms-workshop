#include <algorithm>
#include <iostream>
#include <queue>

int main(void) {

  int n, k;
  std::cin >> n >> k;

  std::priority_queue<int64_t> a;

  for (int i = 0; i < std::min(k, n); ++i) {
    int64_t t;
    std::cin >> t;
    a.push(t);

    std::cout << a.top() << std::endl;
  }

  for (int i = k; i < n; ++i) {
    int64_t t;
    std::cin >> t;
    a.push(t);

    a.pop();
    std::cout << a.top() << std::endl;
  }

  return 0;
}
