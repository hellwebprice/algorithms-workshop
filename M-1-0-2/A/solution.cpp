#include <cstdlib>
#include <functional>
#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <vector>

template <typename T, typename F = std::less<T>> class Heap {
  F cmp = {};

  void _heapify(size_t pos) {
    for (;;) {
      size_t left = 2 * pos + 1, right = 2 * pos + 2, max = pos;

      if (left < _heap.size() && cmp(_heap[max], _heap[left])) {
        max = left;
      }

      if (right < _heap.size() && cmp(_heap[max], _heap[right])) {
        max = right;
      }

      if (max == pos) {
        return;
      }

      std::swap(_heap[pos], _heap[max]);
      pos = max;
    }
  }

public:
  std::vector<T> _heap;
  void push(T value) {
    size_t pos = _heap.size();
    size_t parent = (pos - 1) / 2;
    _heap.push_back(value);
    while (pos > 0 && cmp(_heap[parent], _heap[pos])) {
      std::swap(_heap[parent], _heap[pos]);
      pos = parent;
      parent = (pos - 1) / 2;
    }
  }

  T pop() {
    T max = _heap[0];
    _heap[0] = _heap.back();
    _heap.pop_back();
    _heapify(0);
    return max;
  }
};

struct Attempt {
  std::string name;
  int score;
  int minus_count;

  friend bool operator<(const Attempt &a, const Attempt &b) {
    return std::tie(a.score, a.minus_count) < std::tie(b.score, b.minus_count);
  }
};

int main(void) {
  int m, n;
  std::cin >> m >> n;

  Heap<Attempt> heap;
  for (int i = 0; i < n; ++i) {
    std::string name;
    int score;
    std::cin >> name >> score;
    heap.push(Attempt{name, score, -i});
  }

  std::set<std::string> names;
  for (int i = 0; i < n; ++i) {
    Attempt attempt = heap.pop();
    if (names.count(attempt.name) == 0) {
      names.insert(attempt.name);
      std::cout << attempt.name << std::endl;
    }
  }

  return 0;
}
