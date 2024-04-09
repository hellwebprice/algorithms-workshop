#include <algorithm>
#include <cstdio>
#include <vector>

int main() {

  int n;
  scanf("%d", &n);

  std::vector<int> a(1);
  a.reserve(n);
  scanf("%d", &a[0]);
  printf("1\n");

  for (int i = 0; i < n - 1; ++i) {
    int t;
    scanf("%d", &t);
    if (t >= a.back()) {
      a.push_back(t);
    } else {
      *std::upper_bound(a.begin(), a.end(), t) = t;
    }
    printf("%ld\n", a.size());
  }

  return 0;
}
