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

  static int size(Node *node) { return node == nullptr ? 0 : node->_size; }

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

  void free(Node *node) {
    if (node == nullptr) {
      return;
    }

    free(node->left);
    free(node->right);
    delete node;
  }

public:
  int size() const { return size(root); }
  void splice(int l, int r) {
    Node *left, *to_start, *right;
    _split(root, l - 1, left, right);
    _split(right, r - l + 1, to_start, right);
    root = _merge(_merge(to_start, left), right);
  }

  int get(int index) {
    Node *left, *node, *right;
    _split(root, index - 1, left, right);
    _split(right, 1, node, right);
    root = _merge(left, right);

    int result = node->value;
    delete node;
    return result;
  }

  void push_back(int value) { root = _merge(root, new Node(value)); }

  ~Treap() { free(root); }
};

std::minstd_rand Treap::generator;

int main(void) {

  int n, p;
  std::cin >> n >> p;

  Treap treap;
  for (int i = 1; i <= n; ++i) {
    treap.push_back(i);
  }

  int index = 0;
  for (int i = 0; i < n; ++i) {
    index = (index + p - 1) % treap.size();
    std::cout << treap.get(index + 1) << ' ';
  }
  std::cout << std::endl;

  return 0;
}
