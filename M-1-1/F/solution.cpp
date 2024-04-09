#include <cstdio>
#include <utility>
#include <vector>

template <typename It> It partition(It begin, It end) {

  It pivot = begin;
  for (It it = begin; it != end; ++it) {
    pivot += *it <= *begin;
  }

  std::swap(*begin, *--pivot);

  It it_begin = begin, it_end = --end;
  while (it_begin != pivot && it_end != pivot) {
    while (*it_begin++ <= *pivot) {
    }
    while (*it_end-- > *pivot) {
    }
    if (--it_begin != pivot && ++it_end != pivot) {
      std::swap(*it_begin++, *it_end--);
    }
  }
  return pivot;
}

template <typename It> void quick_sort(It begin, It end) {
  if (begin >= end) {
    return;
  }
  It pivot = partition(begin, end);
  quick_sort(begin, pivot);
  quick_sort(pivot + 1, end);
}

int main(void) {

  int t;
  scanf("%d", &t);

  for (int i = 0; i < t; ++i) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (auto &k : a) {
      scanf("%d", &k);
    }
    quick_sort(a.begin(), a.end());
    for (auto &k : a) {
      printf("%d ", k);
    }
    printf("\n");
  }

  return 0;
}
