#include <cstdio>
#include <queue>

int main(void) {

  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int n;
    scanf("%d", &n);

    std::priority_queue<int> queue;
    long long result = 0;
    for (int j = 0; j < n; ++j) {
      int cur;
      scanf("%d", &cur);
      if (cur != 0) {
        queue.push(cur);
        continue;
      }
      if (!queue.empty()) {
        result += queue.top();
        queue.pop();
      }
    }
    printf("%lld\n", result);
  }

  return 0;
}
