#include <cstdio>
#include <map>

int main(void) {

  int t;
  scanf("%d", &t);

  for (int i = 0; i < t; ++i) {
    int n;
    scanf("%d", &n);

    std::map<int, int> d;
    for (int j = 0; j < n; ++j) {
      int a;
      scanf("%d", &a);
      d[a - j] += 1;
    }
    long long result = 0;
    for (auto &k : d) {
      result += 1LL * k.second * (k.second - 1) / 2;
    }

    printf("%lld\n", result);
  }

  return 0;
}
