#include <iostream>
#include <set>
#include <vector>

int main(void) {
  int t;
  std::cin >> t;

  for (int _ = 0; _ < t; ++_) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> p(m);

    for (auto &k : p) {
      std::cin >> k;
    }

    int last = n;
    std::vector<int> result(n, -1);
    std::set<int> deleted;
    for (int i = 0; i < m; ++i) {
      if (last == 0) {
        break;
      }
      if (deleted.count(p[i]) > 0) {
        continue;
      }
      deleted.insert(p[i]);
      result[--last] = i + 1;
    }

    for (auto &p : result) {
      std::cout << p << ' ';
    }
    std::cout << std::endl;
  }
  return 0;
}
