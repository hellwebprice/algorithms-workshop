#include <iostream>
#include <vector>

class multiset_fenwick {
  std::vector<int> _tree;

public:
  multiset_fenwick(int n) : _tree(n) {}

  void add_to_multiset(int a) {
    for (--a; a < _tree.size(); a = (a | (a + 1))) {
      ++_tree[a];
    }
  }

  void remove_from_multiset(int a) {
    for (--a; a < _tree.size(); a = (a | (a + 1))) {
      --_tree[a];
    }
  }

  int get_k_stat(int k) {
    int result = 0;
    while (k > 0) {
      while ((result | (result + 1)) < _tree.size() &&
             _tree[result | (result + 1)] < k) {
        result = (result | (result + 1));
      }
      if (_tree.size() <= result) {
        return 0;
      }
      k -= _tree[result++];
    }
    return result;
  }
};

int main(void) {

  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;

  multiset_fenwick m(n);
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    m.add_to_multiset(a);
  }

  for (int i = 0; i < q; ++i) {
    int k;
    std::cin >> k;
    if (k > 0) {
      m.add_to_multiset(k);
      continue;
    }
    k = -k;
    m.remove_from_multiset(m.get_k_stat(k));
  }

  std::cout << m.get_k_stat(1) << std::endl;

  return 0;
}
