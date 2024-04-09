#include <algorithm>
#include <functional>
#include <iostream>
#include <istream>
#include <queue>
#include <tuple>
#include <vector>

struct Segment {
  int left, right;

public:
  friend bool operator<(const Segment &a, const Segment &b) {
    return a.left < b.left;
  }
  friend bool operator>(const Segment &a, const Segment &b) {
    return a.right > b.right;
  }
  friend std::istream &operator>>(std::istream &is, Segment &s) {
    return is >> s.left >> s.right;
  }
};

int main(void) {

  int n, m;
  std::cin >> n >> m;

  std::vector<Segment> segments(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> segments[i];
  }

  std::sort(segments.begin(), segments.end());

  auto segments_it = segments.begin();
  std::priority_queue<Segment, std::vector<Segment>, std::greater<Segment>> q;
  for (int i = 1; i <= n; ++i) {
    while (segments_it != segments.end() && segments_it->left == i) {
      q.push(*segments_it++);
    }
    while (!q.empty() && q.top().right < i) {
      q.pop();
    }
    std::cout << q.size() << ' ';
  }
  std::cout << std::endl;

  return 0;
}
