#include <algorithm>
#include <iostream>
#include <vector>

template <class It> int nth_element(It begin, It end, size_t k) {
  if (end - begin <= 5) {
    std::sort(begin, end);
    return begin[k - 1];
  }

  std::vector<int> m;
  It it;
  for (it = begin; end - it > 5; it += 5) {
    std::sort(it, it + 5);
    m.push_back(it[2]);
  }
  std::sort(it, end);
  m.push_back(*(it + (end - it - 1) / 2));

  int median =
      nth_element(m.begin(), m.end(), (m.end() - m.begin() - 1) / 2 + 1);
  auto median_it =
      std::partition(std::partition(begin, end,
                                    [median](auto &em) { return em < median; }),
                     end, [median](auto &em) { return em == median; }) -
      1;

  auto l = median_it - begin;
  if (k == l + 1) {
    return median;
  }
  if (k <= l) {
    return nth_element(begin, median_it, k);
  }
  return nth_element(median_it + 1, end, k - l - 1);
}

int main(void) {

  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto &p : a) {
      std::cin >> p;
    }
    std::cout << nth_element(a.begin(), a.end(), k) << std::endl;
  }

  return 0;
}
