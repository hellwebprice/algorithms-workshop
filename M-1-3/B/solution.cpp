#include <iostream>
#include <vector>

class SegmentTree {

  std::vector<int> _tree;
  int n;

  void _push(int pos) {
    if (_tree[pos] != -1) {
      _tree[pos << 1] = _tree[pos << 1 | 1] = _tree[pos];
      _tree[pos] = -1;
    }
  }

  void _set(int qL, int qR, int qV, int l, int r, int pos) {
    if (l > qR || r < qL) {
      return;
    }
    if (qL <= l && r <= qR) {
      _tree[pos] = qV;
      return;
    }
    _push(pos);
    int lEnd = (l + r) >> 1, rBegin = lEnd + 1;
    _set(qL, qR, qV, l, lEnd, pos << 1);
    _set(qL, qR, qV, rBegin, r, pos << 1 | 1);
  }

  long long _get(int qL, int qR, int l, int r, int pos) {
    if (l > qR || r < qL || pos >= _tree.size()) {
      return 0;
    }
    if (qL <= l && r <= qR && _tree[pos] != -1) {
      return 1LL * _tree[pos] * (r - l + 1);
    }
    _push(pos);
    int lEnd = (l + r) >> 1, rBegin = lEnd + 1;
    return _get(qL, qR, l, lEnd, pos << 1) +
           _get(qL, qR, rBegin, r, pos << 1 | 1);
  }

public:
  SegmentTree(int n) : _tree(n << 2, -1), n(n) {}

  void set(int l, int r, int value) { _set(l - 1, r - 1, value, 0, n - 1, 1); }

  long long get(int l, int r) { return _get(l - 1, r - 1, 0, n - 1, 1); }
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;

  SegmentTree st(n);
  for (int i = 0; i < k; ++i) {
    char cmd;
    int l, r;
    std::cin >> cmd >> l >> r;
    if (cmd == 'A') {
      int value;
      std::cin >> value;
      st.set(l, r, value);
    } else if (cmd == 'Q') {
      std::cout << st.get(l, r) << std::endl;
    }
  }

  return 0;
}
