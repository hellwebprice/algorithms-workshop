#include <cstdio>
#include <functional>
#include <queue>

struct Consignment {
  int i;
  int votes, places = 0;

public:
  void scan(int _idx) {
    i = -_idx;
    scanf("%d", &votes);
  }
  friend bool operator<(const Consignment &a, const Consignment &b) {
    long long a_quote = 1LL * a.votes * (b.places + 1),
              b_quote = 1LL * b.votes * (a.places + 1);
    return std::tie(a_quote, a.i) < std::tie(b_quote, b.i);
  }
};

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  std::vector<Consignment> consignments(n);
  std::priority_queue<std::reference_wrapper<Consignment>> queue;
  for (int i = 0; i < n; ++i) {
    consignments[i].scan(i);
    queue.push(consignments[i]);
  }

  for (int i = 0; i < m; ++i) {
    auto consignment = queue.top();
    queue.pop();
    ++consignment.get().places;
    queue.push(consignment);
  }

  for (int i = 0; i < n; ++i) {
    printf("%d ", consignments[i].places);
  }
  printf("\n");
  return 0;
}
