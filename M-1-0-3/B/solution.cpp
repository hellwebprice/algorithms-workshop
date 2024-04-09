#include <iostream>
#include <random>
#include <string>

class Treap {
  static std::minstd_rand generator;

  struct Node {
    int key, priority;
    Node *left = nullptr, *right = nullptr;
    Node(int key) : key(key), priority(generator()) {}
  } *root = nullptr;

  static Node *_merge(Node *left, Node *right) {
    if (left == nullptr || right == nullptr) {
      return left != nullptr ? left : right;
    }

    if (left->priority > right->priority) {
      left->right = _merge(left->right, right);
      return left;
    }
    right->left = _merge(left, right->left);
    return right;
  }

  static void _split(Node *root, int key, Node *&left, Node *&right) {
    if (root == nullptr) {
      left = right = nullptr;
      return;
    }
    if (root->key < key) {
      _split(root->right, key, root->right, right);
      left = root;
      return;
    }
    _split(root->left, key, left, root->left);
    right = root;
  }

  int _min(Node *root) const {
    if (root == nullptr) {
      return -1;
    }

    while (root->left) {
      root = root->left;
    }
    return root->key;
  }

public:
  bool contains(int key) {
    Node *left, *equal, *right;
    _split(root, key, left, right);
    _split(right, key + 1, equal, right);
    bool result = equal;
    root = _merge(_merge(left, equal), right);
    return result;
  }

  void insert(int key) {
    Node *left, *right;
    _split(root, key, left, right);
    root = _merge(_merge(left, new Node(key)), right);
  }

  int upper_bound(int key) {
    Node *left, *right;
    _split(root, key, left, right);
    int result = _min(right);
    root = _merge(left, right);
    return result;
  }
};

std::minstd_rand Treap::generator;

int main(void) {
  enum {
    MOD = 1000000000,
  };

  int n;
  scanf("%d", &n);

  Treap treap;
  int prev = 0;
  for (int i = 0; i < n; ++i) {
    std::string cmd;
    int a;
    std::cin >> cmd >> a;
    if (cmd == "+") {
      a = (a + prev) % MOD;
      if (!treap.contains(a)) {
        treap.insert(a);
      }
      prev = 0;
    } else if (cmd == "?") {
      prev = treap.upper_bound(a);
      std::cout << prev << std::endl;
    } else {
      throw 1;
    }
  }

  return 0;
}
