#include <iostream>
#include <set>
#include <tuple>

struct Segment {
  int left, right;

public:
  friend bool operator<(const Segment &a, const Segment &b) {
    return std::tie(a.left, a.right) < std::tie(b.left, b.right);
  }
};

int main(void) {

  int n;
  std::cin >> n;

  enum {
    INF = 1000000000,
  };

  std::set<Segment> occupied;
  occupied.insert({0, 0});
  occupied.insert({INF, INF});

  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;

    if (a > 0) {
      auto upper = occupied.upper_bound({a, INF});
      auto lower = std::next(upper, -1);

      Segment new_occupied = {a, a};
      if (a <= lower->right + 1) {
        a = lower->right + 1;
        new_occupied = Segment{lower->left, a};
        occupied.erase(lower);
      }

      if (new_occupied.right == upper->left - 1) {
        new_occupied.right = upper->right;
        occupied.erase(upper);
      }
      std::cout << a << std::endl;
      occupied.insert(new_occupied);
    } else {
      a = -a;
      auto upper = occupied.upper_bound({a, INF});
      auto lower = std::next(upper, -1);
      auto occupied_el = *lower;
      occupied.erase(lower);
      if (occupied_el.left < a) {
        occupied.insert(Segment{occupied_el.left, a - 1});
      }
      if (a < occupied_el.right) {
        occupied.insert(Segment{a + 1, occupied_el.right});
      }
    }
  }
  return 0;
}
