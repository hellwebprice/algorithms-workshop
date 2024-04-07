#include <iostream>
#include <vector>

template <typename It> void merge_sort(It begin, It end) {
  if (std::distance(begin, end) < 2)
    return;

  auto mid = std::next(begin, std::distance(begin, end) / 2);
  merge_sort(begin, mid);
  merge_sort(mid, end);

  std::vector<typename std::iterator_traits<It>::value_type> t;
  t.reserve(std::distance(begin, end));

  auto left = begin, right = mid;
  while (left != mid && right != end) {
    if (*left < *right) {
      t.push_back(*left++);
    } else {
      t.push_back(*right++);
    }
  }

  t.insert(t.end(), left, mid);
  t.insert(t.end(), right, end);
  std::move(t.begin(), t.end(), begin);
}

int main() {
  int t;
  std::cin >> t;

  for (int i = 0; i < t; ++i) {
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    for (size_t j = 0; j < n; ++j) {
      std::cin >> a[j];
    }

    merge_sort(a.begin(), a.end());

    for (int j = 0; j < n; ++j) {
      std::cout << a[j] << ' ';
    }
    std::cout << std::endl;
  }
  return 0;
}
