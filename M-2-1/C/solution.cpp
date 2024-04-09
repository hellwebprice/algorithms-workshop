#include <algorithm>
#include <iostream>
#include <vector>

class Tree {
  struct Node {
    size_t height;
    std::vector<std::reference_wrapper<Node>> childs;
    Node() : height(0), childs() {}
  };

  std::vector<Node> _nodes;
  size_t _max_height;

  void _dfs(Node &node, size_t height) {
    _max_height = std::max(_max_height, node.height = height);
    for (auto &child : node.childs) {
      _dfs(child, height + 1);
    }
  }

public:
  Tree(size_t n) : _nodes(1 + n), _max_height(false) {}

  void set_parent(size_t index, int parent) {
    parent = parent == -1 ? 0 : parent;
    _nodes[parent].childs.push_back(_nodes[index]);
  }

  size_t get_max_height() {
    if (_max_height == 0) {
      _dfs(_nodes[0], 0);
    }
    return _max_height;
  }
};

int main(void) {

  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  size_t n;
  std::cin >> n;

  Tree tree(n);
  for (size_t i = 1; i <= n; ++i) {
    int parent;
    std::cin >> parent;
    tree.set_parent(i, parent);
  }

  std::cout << tree.get_max_height() << std::endl;

  return 0;
}
