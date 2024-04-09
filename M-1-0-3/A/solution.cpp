#include <cstdio>
#include <cstdlib>
#include <map>
#include <utility>

int main(void) {

  int n;
  scanf("%d", &n);

  std::map<int, int> N;
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);

    if (N.count(a) == 0) {
      N[a] = a;
    }

    if (N.count(b) == 0) {
      N[b] = b;
    }

    std::swap(N[a], N[b]);
    printf("%d\n", std::abs(N[a] - N[b]));
  }

  return 0;
}
