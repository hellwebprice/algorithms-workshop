#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

class Graph {
  std::vector<std::vector<int>> _edges;
  std::vector<bool> used;
  std::vector<size_t> order;

  bool _dfs(size_t node, std::vector<size_t> &closed, bool is_reverse) {
    if (used[node]) {
      return false;
    }

    used[node] = true;
    if (is_reverse) {
      for (size_t i = 0; i < _edges.size(); ++i) {
        if (_edges[i][node] == 1) {
          _dfs(i, closed, is_reverse);
        }
      }
    } else {
      for (size_t i = 0; i < _edges.size(); ++i) {
        if (_edges[node][i] == 1) {
          _dfs(i, closed, is_reverse);
        }
      }
    }
    closed.push_back(node);
    return true;
  }

public:
  Graph(std::vector<std::vector<int>> &&edges) : _edges(std::move(edges)) {
    order.assign(_edges.size(), 0);
    for (size_t i = 0; i < order.size(); ++i) {
      order[i] = i;
    }
  }

  size_t dfs(bool is_reverse) {
    size_t result = 0;

    used.assign(_edges.size(), false);
    std::vector<size_t> closed;
    for (auto &node : order) {
      if (!used[node]) {
        _dfs(node, closed, is_reverse);
        ++result;
      }
    }
    order.swap(closed);
    std::reverse(order.begin(), order.end());

    return result;
  }
};

int main(void) {

  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  size_t n;
  std::cin >> n;

  std::vector<std::vector<int>> edges(n, std::vector<int>(n, 0));
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      std::cin >> edges[i][j];
    }
  }

  Graph graph(std::move(edges));
  graph.dfs(false);
  std::cout << graph.dfs(true) << std::endl;

  return 0;
}
