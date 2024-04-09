#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main(void) {

  enum STATUSES {
    DECLINED,
    RESUPPLIED,
    APPROVED,
  };

  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  std::vector<STATUSES> statuses(n + m, DECLINED);
  std::map<size_t, long long> supplies;
  supplies[0] = 0;
  std::vector<std::pair<int, size_t>> queries;
  queries.reserve(m);
  for (size_t i = 1; i <= n + m; ++i) {
    int x;
    std::cin >> x;

    if (x < 0) {
      queries.push_back({x, i});
      continue;
    }

    supplies[i] = x;
    statuses[i - 1] = RESUPPLIED;
  }

  std::sort(queries.begin(), queries.end(),
            std::greater<std::pair<int, size_t>>());
  for (auto &query : queries) {
    auto supply_it = --supplies.upper_bound(query.second);
    while (supply_it != supplies.begin() && supply_it->second < -query.first) {
      auto prev_it = std::prev(supply_it);
      prev_it->second += supply_it->second;
      supplies.erase(supply_it);
      supply_it = prev_it;
    }
    if (supply_it->second >= -query.first) {
      supply_it->second += query.first;
      statuses[query.second - 1] = APPROVED;
    }
  }

  for (auto &status : statuses) {
    switch (status) {
    case DECLINED:
      std::cout << "declined" << std::endl;
      break;
    case RESUPPLIED:
      std::cout << "resupplied" << std::endl;
      break;
    case APPROVED:
      std::cout << "approved" << std::endl;
      break;
    }
  }

  return 0;
}
