#include <algorithm>
#include <climits>
#include <iostream>
#include <random>

class Treap {

  static std::minstd_rand generator;

  struct Node {
    int size, priority, value, min;
    Node *left = nullptr, *right = nullptr;
    Node(int value)
        : size(1), priority(generator()), value(value), min(value) {}
    void recalc() {
      size = get_size(left) + get_size(right) + 1;
      min = std::min({value, get_min(left), get_min(right)});
    }
  } *root = nullptr;

  static int get_size(Node *node) { return node == nullptr ? 0 : node->size; }
  static int get_min(Node *node) {
    return node == nullptr ? INT_MAX : node->min;
  }

  static Node *_merge(Node *left, Node *right) {
    if (left == nullptr || right == nullptr) {
      return left != nullptr ? left : right;
    }

    if (left->priority > right->priority) {
      left->right = _merge(left->right, right);
      left->recalc();
      return left;
    }
    right->left = _merge(left, right->left);
    right->recalc();
    return right;
  }

  static void _split(Node *root, int index, Node *&left, Node *&right) {
    if (root == nullptr) {
      left = right = nullptr;
      return;
    }
    int cur_size = get_size(root->left) + 1;
    if (cur_size <= index) {
      _split(root->right, index - cur_size, root->right, right);
      left = root;
      left->recalc();
      return;
    }
    _split(root->left, index, left, root->left);
    right = root;
    right->recalc();
  }

  void _delete_node(Node *node) {
    if (node == nullptr) {
      return;
    }
    _delete_node(node->left);
    _delete_node(node->right);
    delete node;
  }

public:
  void insert(int index, int value) {
    Node *left, *right;
    _split(root, index, left, right);
    root = _merge(_merge(left, new Node(value)), right);
  }

  int min(int l, int r) {
    Node *left, *find, *right;
    _split(root, l - 1, left, right);
    _split(right, r - l + 1, find, right);
    int result = get_min(find);
    root = _merge(_merge(left, find), right);
    return result;
  }

  ~Treap() { _delete_node(root); }
};

std::minstd_rand Treap::generator;

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int k;
  std::cin >> k;

  Treap treap;
  for (int i = 0; i < k; ++i) {
    char cmd;
    std::cin >> cmd;
    if (cmd == '+') {
      int i, x;
      std::cin >> i >> x;
      treap.insert(i, x);
    } else if (cmd == '?') {
      int l, r;
      std::cin >> l >> r;
      std::cout << treap.min(l, r) << std::endl;
    }
  }

  return 0;
}
