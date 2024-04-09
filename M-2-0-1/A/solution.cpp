#include <iostream>
#include <vector>

class Tree {
  struct Node {
    size_t open, close;
    std::vector<std::reference_wrapper<Node>> childs;
  };

  std::vector<Node> _nodes;

  static void _dfs(Node &node, size_t &index) {
    node.open = index++;
    for (auto &child : node.childs) {
      _dfs(child, index);
    }
    node.close = index++;
  }

public:
  Tree(size_t n) : _nodes(1 + n) {}

  void add_node(size_t index, size_t parent) {
    _nodes[parent].childs.push_back(_nodes[index]);
  }

  void dfs() {
    size_t index = 0;
    _dfs(_nodes[0], index);
  }

  bool is_ancestor(size_t a, size_t b) {
    return _nodes[a].open <= _nodes[b].open &&
           _nodes[b].close <= _nodes[a].close;
  }
};

int main(void) {

  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  size_t n;
  std::cin >> n;

  Tree tree(n);
  for (size_t i = 1; i <= n; ++i) {
    size_t parent_index;
    std::cin >> parent_index;
    tree.add_node(i, parent_index);
  }

  size_t m;
  std::cin >> m;
  tree.dfs();
  for (size_t i = 0; i < m; ++i) {
    size_t a, b;
    std::cin >> a >> b;
    std::cout << int(tree.is_ancestor(a, b)) << std::endl;
  }

  return 0;
}
