#include <algorithm>
#include <iostream>
#include <vector>

const double EPS = 1e-9;

double find_max_square(std::pair<std::vector<double>::const_iterator,
                                 std::vector<double>::const_iterator>
                           best_x,
                       std::vector<double>::const_iterator end,
                       double max_abs_y) {
  if (best_x.first == end || best_x.second == end)
    return 0;

  double min_x = *(best_x.first), max_x = *(best_x.second);
  return max_abs_y * (max_x - min_x) / 2;
}

int main() {
  size_t n;
  std::cin >> n;

  double left_max_abs_y = 0, right_max_abs_y = 0;
  std::vector<double> left_x, right_x;
  for (size_t i = 0; i < n; ++i) {
    double x, y;
    std::cin >> x >> y;
    y = std::abs(y);
    if (x < 0) {
      if (std::abs(y) < EPS) {
        left_x.push_back(x);
      } else if (left_max_abs_y < y) {
        left_max_abs_y = y;
      }
    } else if (x > 0) {
      if (std::abs(y) < EPS) {
        right_x.push_back(x);
      } else if (right_max_abs_y < y) {
        right_max_abs_y = y;
      }
    }
  }

  auto best_left_x = std::minmax_element(left_x.begin(), left_x.end());
  auto best_right_x = std::minmax_element(right_x.begin(), right_x.end());

  std::cout
      << std::max(find_max_square(best_left_x, left_x.end(), left_max_abs_y),
                  find_max_square(best_right_x, right_x.end(), right_max_abs_y))
      << std::endl;

  return 0;
}
