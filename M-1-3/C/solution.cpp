#include <iostream>
#include <string>
#include <vector>

class SegmentTree {

  struct Node {
    int add;
    int max;
  };

  std::vector<Node> _tree;
  int n;

  void _add(int qL, int qR, int qV, int l, int r, int pos) {
    if (l > qR || r < qL) {
      return;
    }
    if (qL <= l && r <= qR) {
      _tree[pos].add += qV;
      _tree[pos].max += qV;
      return;
    }
    int lEnd = (l + r) >> 1, rBegin = lEnd + 1;
    _add(qL, qR, qV, l, lEnd, pos << 1);
    _add(qL, qR, qV, rBegin, r, pos << 1 | 1);
    _tree[pos].max =
        _tree[pos].add + std::max(_tree[pos << 1].max, _tree[pos << 1 | 1].max);
  }

  int _get_max(int qL, int qR, int l, int r, int pos) {
    if (l > qR || r < qL) {
      return 0;
    }
    if (qL <= l && r <= qR) {
      return _tree[pos].max;
    }
    int lEnd = (l + r) >> 1, rBegin = lEnd + 1;
    return _tree[pos].add + std::max(_get_max(qL, qR, l, lEnd, pos << 1),
                                     _get_max(qL, qR, rBegin, r, pos << 1 | 1));
  }

public:
  SegmentTree(int n) : _tree(n << 2), n(n) {}

  void add(int l, int r, int value) { _add(l - 1, r - 1, value, 0, n - 1, 1); }

  int get_max(int l, int r) { return _get_max(l - 1, r - 1, 0, n - 1, 1); }
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;

  SegmentTree st(n);
  for (int i = 0; i < k; ++i) {
    std::string cmd;
    int l, r;
    std::cin >> cmd >> l >> r;
    if (cmd == "build") {
      int value;
      std::cin >> value;
      st.add(l, r, value);
    } else if (cmd == "test") {
      std::cout << st.get_max(l, r) << std::endl;
    }
  }

  return 0;
}
