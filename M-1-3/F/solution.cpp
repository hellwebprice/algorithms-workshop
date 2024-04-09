#include <cmath>
#include <iostream>
#include <vector>

class Tree {
  struct Node {
    size_t height{0};
    size_t in, out;
    std::vector<Node *> parents{32, nullptr};
    std::vector<Node *> childs{};
  } *_root;

  std::vector<Node *> _nodes;
  std::vector<std::vector<size_t>> _height_indeces;

  void _add_height_index(size_t height, size_t index) {
    if (height >= _height_indeces.size()) {
      _height_indeces.push_back({index});
      return;
    }

    _height_indeces[height].push_back(index);
  }

  void _dfs(Node *node, size_t &index) {
    if (node == nullptr) {
      return;
    }

    _add_height_index(node->height, index);
    node->in = index++;

    for (auto &child : node->childs) {
      _dfs(child, index);
    }

    _add_height_index(node->height, index);
    node->out = index++;
  }

  static void _delete_node(Node *node) {
    if (node == nullptr) {
      return;
    }

    for (auto &child : node->childs) {
      _delete_node(child);
    }
    delete node;
  }

public:
  Tree(std::vector<size_t> &parents)
      : _root(new Node), _nodes(parents.size(), nullptr) {
    for (size_t i = 0; i < parents.size(); ++i) {
      Node *node = _nodes[i] = new Node;
      if (parents[i] == 0) {
        _root->childs.push_back(node);
        continue;
      }
      Node *parent = _nodes[parents[i] - 1];
      parent->childs.push_back(node);
      node->height = parent->height + 1;
      node->parents[0] = parent;
      for (size_t i = 1; i < 32; ++i) {
        if (node->parents[i - 1] != nullptr) {
          node->parents[i] = node->parents[i - 1]->parents[i - 1];
        }
      }
    }

    size_t index = 0;
    _dfs(_root, index);
  }

  int get(size_t v, int p) {
    Node *node = _nodes[v - 1];
    if (node->height < p) {
      return 0;
    }

    Node *pparent = node;
    for (int i = p & -p; p != 0; p ^= i, i = p & -p) {
      pparent = pparent->parents[std::log2(i)];
    }
    return (std::lower_bound(_height_indeces[node->height].begin(),
                             _height_indeces[node->height].end(),
                             pparent->out) -
            std::lower_bound(_height_indeces[node->height].begin(),
                             _height_indeces[node->height].end(),
                             pparent->in)) /
               2 -
           1;
  }

  ~Tree() { _delete_node(_root); }
};

int main(void) {

  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  std::vector<size_t> parents(n);
  for (auto &parent : parents) {
    std::cin >> parent;
  }

  Tree tree(parents);

  int m;
  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    size_t v;
    int p;
    std::cin >> v >> p;

    std::cout << tree.get(v, p) << ' ';
  }
  std::cout << std::endl;

  return 0;
}
