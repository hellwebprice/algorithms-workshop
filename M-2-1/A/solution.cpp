#include <iostream>
#include <map>
#include <vector>

template <typename T> class DSU {
  struct Node {
    T leader;
    size_t size;
  };

  std::map<T, Node> _dsu;

public:
  DSU(std::vector<T> &elements) {
    for (auto &element : elements) {
      _dsu[element].leader = element;
      _dsu[element].size = 1;
    }
  }

  T &operator[](T &v) {
    return v == _dsu[v].leader ? v : _dsu[v].leader = (*this)[_dsu[v].leader];
  }

  void union_set(T &a, T &b) {
    a = (*this)[a], b = (*this)[b];
    if (a == b) {
      return;
    }
    if (_dsu[a].size < _dsu[b].size) {
      std::swap(a, b);
    }
    _dsu[b].leader = a;
    _dsu[a].size += _dsu[b].size;
  }

  inline size_t get_size(T &a) { return _dsu[(*this)[a]].size; }
};

int main(void) {

  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  size_t n, m;
  std::cin >> n >> m;

  std::vector<size_t> init;
  init.reserve(n);
  for (int i = 1; i <= n; ++i) {
    init.push_back(i);
  }

  DSU<size_t> dsu(init);
  for (size_t i = 0; i < m; ++i) {
    size_t k;
    std::cin >> k;

    size_t first;
    if (k > 0) {
      std::cin >> first;
    }
    for (size_t j = 1; j < k; ++j) {
      size_t user;
      std::cin >> user;
      dsu.union_set(first, user);
    }
  }

  for (size_t i = 1; i <= n; ++i) {
    std::cout << dsu.get_size(i) << ' ';
  }
  std::cout << std::endl;

  return 0;
}
