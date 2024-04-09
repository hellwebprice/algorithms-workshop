#include <iostream>
#include <queue>
#include <vector>

class Graph {
  struct Node {
    size_t index;
    std::vector<std::reference_wrapper<Node>> edge;
  };

  std::vector<Node> _nodes;

public:
  Graph(size_t n) : _nodes(n) {
    for (size_t i = 0; i < n; ++i) {
      _nodes[i].index = i;
    }
  }

  void add_edge(size_t from, size_t to) {
    _nodes[from].edge.push_back(_nodes[to]);
    _nodes[to].edge.push_back(_nodes[from]);
  }

  size_t count() {
    std::vector<size_t> distances(_nodes.size(), -1);
    std::queue<std::reference_wrapper<Node>> queue;
    queue.push(_nodes[0]);
    distances[0] = 0;
    size_t M = 1, N = 0;

    while (!queue.empty()) {
      Node &node = queue.front();
      queue.pop();
      for (Node &neighbour : node.edge) {
        if (distances[neighbour.index] == -1) {
          distances[neighbour.index] = distances[node.index] + 1;
          M += !(distances[neighbour.index] & 1);
          N += distances[neighbour.index] & 1;
          queue.push(neighbour);
        }
      }
    }

    return M * N - _nodes.size() + 1;
  }
};

int main(void) {

  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  size_t n;
  std::cin >> n;

  Graph graph(n);
  for (size_t i = 0; i < n - 1; ++i) {
    size_t from, to;
    std::cin >> from >> to;
    graph.add_edge(from - 1, to - 1);
  }

  std::cout << graph.count() << std::endl;

  return 0;
}
