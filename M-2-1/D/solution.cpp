#include <iostream>
#include <set>
#include <vector>

class Graph {
  struct Node {
    std::set<Node *> edges;
    Node() : edges() {}
  };

  std::vector<Node> _nodes;

public:
  Graph(size_t n) : _nodes(n) {}
  Graph(size_t n, std::vector<std::pair<size_t, size_t>> &edges) : _nodes(n) {
    for (auto &[from, to] : edges) {
      _nodes[from - 1].edges.insert(&_nodes[to - 1]);
      _nodes[to - 1].edges.insert(&_nodes[from - 1]);
    }
  }

  size_t remove_1() {
    size_t result = 0;

    std::vector<std::pair<Node *, Node *>> to_erase;
    do {
      to_erase.clear();
      for (Node &node : _nodes) {
        if (node.edges.size() == 1) {
          Node *neighbour = *node.edges.begin();
          node.edges.clear();
          to_erase.push_back({neighbour, &node});
        }
      }
      for (auto &[neightbour, node] : to_erase) {
        neightbour->edges.erase(node);
      }
      ++result;
    } while (!to_erase.empty());

    return result - 1;
  }
};

int main(void) {

  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  size_t n, m;
  std::cin >> n >> m;

  std::vector<std::pair<size_t, size_t>> edges(m);
  for (size_t i = 0; i < m; ++i) {
    std::cin >> edges[i].first >> edges[i].second;
  }

  Graph graph(n, edges);
  std::cout << graph.remove_1() << std::endl;

  return 0;
}
