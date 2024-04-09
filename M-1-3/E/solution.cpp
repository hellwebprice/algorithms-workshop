#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class SegmentTree {

  std::vector<int> _tree;
  int n;

  void _add(int qL, int qR, int l, int r, int pos) {
    if (l > qR || r < qL) {
      return;
    }
    if (qL <= l && r <= qR) {
      ++_tree[pos];
      return;
    }
    int lEnd = (l + r) >> 1, rBegin = lEnd + 1;
    _add(qL, qR, l, lEnd, pos << 1);
    _add(qL, qR, rBegin, r, pos << 1 | 1);
  }

  int _get(int qI, int l, int r, int pos) const {
    if (l > qI || r < qI) {
      return 0;
    }
    if (qI == l && r == qI) {
      return _tree[pos];
    }
    int lEnd = (l + r) >> 1, rBegin = lEnd + 1;
    return _tree[pos] + _get(qI, l, lEnd, pos << 1) +
           _get(qI, rBegin, r, pos << 1 | 1);
  }

public:
  SegmentTree(int n) : _tree(n << 2), n(n) {}

  void add(int l, int r) { _add(l - 1, r - 1, 0, n - 1, 1); }

  int get(int i) const { return _get(i, 0, n - 1, 1); }
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;

  std::vector<int> a(n);
  for (int &k : a) {
    std::cin >> k;
  }
  std::sort(a.begin(), a.end());

  SegmentTree st(n);
  for (int i = 0; i < q; ++i) {
    int l, r;
    std::cin >> l >> r;
    st.add(l, r);
  }

  std::vector<int> counts(n);
  for (int i = 0; i < n; ++i) {
    counts[i] = st.get(i);
  }
  std::sort(counts.begin(), counts.end());

  long long result = 0;
  for (int i = 0; i < n; ++i) {
    result += 1LL * a[i] * counts[i];
  }

  std::cout << result << std::endl;

  return 0;
}
