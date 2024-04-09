#include <stdio.h>
#include <vector>

std::vector<long long> tree;
long long ans;

long long read(const int l, const int r, const int pos) {
  if (l == r)
    scanf("%lld", &tree[pos]);
  else {
    int lEnd = (l + r) >> 1, rBegin = lEnd + 1;
    long long first = read(l, lEnd, pos << 1),
              second = read(rBegin, r, pos << 1 | 1);
    tree[pos] = first + second;
  }
  return tree[pos];
}

long long update(const int qIndex, const int qValue, const int l, const int r,
                 const int pos) {
  if (l == r) {
    if (l == qIndex)
      tree[pos] = qValue;
  } else {
    int lEnd = (l + r) >> 1, rBegin = lEnd + 1;
    if (l <= qIndex && qIndex <= lEnd)
      tree[pos] =
          update(qIndex, qValue, l, lEnd, pos << 1) + tree[pos << 1 | 1];
    else
      tree[pos] =
          tree[pos << 1] + update(qIndex, qValue, rBegin, r, pos << 1 | 1);
  }
  return tree[pos];
}

void get(const int qL, const int qR, const int l, const int r, const int pos) {
  if (l > qR || r < qL)
    return;
  if (qL <= l && r <= qR)
    ans += tree[pos];
  else {
    int lEnd = (l + r) >> 1, rBegin = lEnd + 1;
    get(qL, qR, l, lEnd, pos << 1);
    get(qL, qR, rBegin, r, pos << 1 | 1);
  }
}

int main() {

  int n, m, l, r;
  char cmd;
  scanf("%d", &n);

  tree.resize(n << 2);
  read(0, n - 1, 1);

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &l, &r);
    ans = 0;
    get(l - 1, r - 1, 0, n - 1, 1);
    printf("%lld ", ans);
  }

  return 0;
}
