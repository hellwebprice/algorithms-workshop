#include <iostream>
#include <ostream>
#include <random>

class Treap {
  static std::minstd_rand generator;

  struct Node {
    int _size = 1, priority, value;
    Node *left = nullptr, *right = nullptr;
    Node(int value) : priority(generator()), value(value) {}
    void recalc_size() { _size = size(left) + size(right) + 1; }
  } *root = nullptr;

  friend int size(Node *node) { return node == nullptr ? 0 : node->_size; }

  static Node *_merge(Node *left, Node *right) {
    if (left == nullptr || right == nullptr) {
      return left != nullptr ? left : right;
    }

    if (left->priority > right->priority) {
      left->right = _merge(left->right, right);
      left->recalc_size();
      return left;
    }
    right->left = _merge(left, right->left);
    right->recalc_size();
    return right;
  }

  static void _split(Node *root, int index, Node *&left, Node *&right) {
    if (root == nullptr) {
      left = right = nullptr;
      return;
    }

    int cur_index = size(root->left) + 1;
    if (size(root->left) + 1 <= index) {
      _split(root->right, index - cur_index, root->right, right);
      left = root;
      left->recalc_size();
      return;
    }
    _split(root->left, index, left, root->left);
    right = root;
    right->recalc_size();
  }

public:
  void splice(int l, int r) {
    Node *left, *to_start, *right;
    _split(root, l - 1, left, right);
    _split(right, r - l + 1, to_start, right);
    root = _merge(_merge(to_start, left), right);
  }

  void push_back(int value) { root = _merge(root, new Node(value)); }

  friend std::ostream &operator<<(std::ostream &os, Node *root) {
    if (root == nullptr) {
      return os;
    }
    return os << root->left << root->value << ' ' << root->right;
  }

  friend std::ostream &operator<<(std::ostream &os, Treap treap) {
    return os << treap.root;
  }
};

std::minstd_rand Treap::generator;

int main(void) {

  int n, m;
  std::cin >> n >> m;

  Treap treap;
  for (int i = 1; i <= n; ++i) {
    treap.push_back(i);
  }

  for (int i = 0; i < m; ++i) {
    int left, right;
    std::cin >> left >> right;

    if (left == 1) {
      continue;
    }

    treap.splice(left, right);
  }

  std::cout << treap << std::endl;

  return 0;
}
