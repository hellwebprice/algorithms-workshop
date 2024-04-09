#include <iostream>
#include <queue>
#include <string>
#include <tuple>

struct Time {
  int hours, minutes;

public:
  void scan() { scanf("%d:%d", &hours, &minutes); }

  friend bool operator<(const Time &a, const Time &b) {
    return std::tie(a.hours, a.minutes) < std::tie(b.hours, b.minutes);
  }
  friend bool operator>(const Time &a, const Time &b) { return b < a; }
};

int main(void) {

  int n, m;
  std::cin >> n >> m;

  std::priority_queue<Time, std::vector<Time>, std::greater<Time>> queue;
  for (int i = 0; i < n; ++i) {
    char name[10 + 1];
    Time from, to;

    scanf("%10s", name);
    from.scan(), to.scan();

    if (!queue.empty() && queue.top() < from) {
      queue.pop();
    }

    if (queue.size() == m) {
      printf("No\n");
      continue;
    }

    printf("%s\n", name);
    queue.push(to);
  }

  return 0;
}
