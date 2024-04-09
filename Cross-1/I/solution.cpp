#include <iostream>

template <typename T> class RBTree {

  enum class Color { RED, BLACK };

  struct Node {
    T data;
    Node *parent;
    Node *left;
    Node *right;
    Color color;

    Node(const T &val)
        : data(val), parent(nullptr), left(nullptr), right(nullptr),
          color(Color::RED) {}
  } *root;

  void left_rotate(Node *x) {
    Node *y = x->right;
    x->right = y->left;
    if (y->left != nullptr) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      root = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }

  void right_rotate(Node *y) {
    Node *x = y->left;
    y->left = x->right;
    if (x->right != nullptr) {
      x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == nullptr) {
      root = x;
    } else if (y == y->parent->right) {
      y->parent->right = x;
    } else {
      y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
  }

  void fix_insert(Node *z) {
    while (z != root && z->parent->color == Color::RED) {
      if (z->parent == z->parent->parent->left) {
        Node *y = z->parent->parent->right;
        if (y != nullptr && y->color == Color::RED) {
          z->parent->color = Color::BLACK;
          y->color = Color::BLACK;
          z->parent->parent->color = Color::RED;
          z = z->parent->parent;
        } else {
          if (z == z->parent->right) {
            z = z->parent;
            left_rotate(z);
          }
          z->parent->color = Color::BLACK;
          z->parent->parent->color = Color::RED;
          right_rotate(z->parent->parent);
        }
      } else {
        Node *y = z->parent->parent->left;
        if (y != nullptr && y->color == Color::RED) {
          z->parent->color = Color::BLACK;
          y->color = Color::BLACK;
          z->parent->parent->color = Color::RED;
          z = z->parent->parent;
        } else {
          if (z == z->parent->left) {
            z = z->parent;
            right_rotate(z);
          }
          z->parent->color = Color::BLACK;
          z->parent->parent->color = Color::RED;
          left_rotate(z->parent->parent);
        }
      }
    }
    root->color = Color::BLACK;
  }

  void transplant(Node *u, Node *v) {
    if (u->parent == nullptr) {
      root = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    if (v != nullptr) {
      v->parent = u->parent;
    }
  }

  Node *min(Node *x) {
    while (x->left != nullptr) {
      x = x->left;
    }
    return x;
  }

  void fix_delete(Node *x) {
    while (x != root && x->color == Color::BLACK) {
      if (x == x->parent->left) {
        Node *w = x->parent->right;
        if (w->color == Color::RED) {
          w->color = Color::BLACK;
          x->parent->color = Color::RED;
          left_rotate(x->parent);
          w = x->parent->right;
        }
        if (w->left->color == Color::BLACK && w->right->color == Color::BLACK) {
          w->color = Color::RED;
          x = x->parent;
        } else {
          if (w->right->color == Color::BLACK) {
            w->left->color = Color::BLACK;
            w->color = Color::RED;
            right_rotate(w);
            w = x->parent->right;
          }
          w->color = x->parent->color;
          x->parent->color = Color::BLACK;
          w->right->color = Color::BLACK;
          left_rotate(x->parent);
          x = root;
        }
      } else {
        Node *w = x->parent->left;
        if (w->color == Color::RED) {
          w->color = Color::BLACK;
          x->parent->color = Color::RED;
          right_rotate(x->parent);
          w = x->parent->left;
        }
        if (w->right->color == Color::BLACK && w->left->color == Color::BLACK) {
          w->color = Color::RED;
          x = x->parent;
        } else {
          if (w->left->color == Color::BLACK) {
            w->right->color = Color::BLACK;
            w->color = Color::RED;
            left_rotate(w);
            w = x->parent->left;
          }
          w->color = x->parent->color;
          x->parent->color = Color::BLACK;
          w->left->color = Color::BLACK;
          right_rotate(x->parent);
          x = root;
        }
      }
    }
    x->color = Color::BLACK;
  }

  void delete_node(Node *node) {
    if (node == nullptr) {
      return;
    }

    delete_node(node->left);
    delete_node(node->right);
    delete node;
  }

public:
  RBTree() : root(nullptr) {}

  void insert(const T &val) {
    Node *x = root, *y = nullptr, *z = new Node(val);
    while (x != nullptr) {
      y = x;
      if (z->data < x->data) {
        x = x->left;
      } else {
        x = x->right;
      }
    }
    z->parent = y;
    if (y == nullptr) {
      root = z;
    } else if (z->data < y->data) {
      y->left = z;
    } else {
      y->right = z;
    }
    fix_insert(z);
  }

  bool contains(const T &val) const {
    Node *z = root;
    while (z != nullptr) {
      if (z->data == val) {
        return true;
      }
      if (val < z->data) {
        z = z->left;
      } else {
        z = z->right;
      }
    }
    return false;
  }

  T *upper_bound(const T &val) const {
    Node *z = root;
    Node *result = nullptr;
    while (z != nullptr) {
      if (val <= z->data) {
        result = z;
        z = z->left;
      } else {
        z = z->right;
      }
    }
    if (result == nullptr) {
      return nullptr;
    }
    return &result->data;
  }

  void erase(const T &val) {
    Node *z = root;
    while (z != nullptr) {
      if (z->data == val) {
        break;
      }
      if (val < z->data) {
        z = z->left;
      } else {
        z = z->right;
      }
    }
    if (z == nullptr)
      return;
    Node *y = z;
    Color y_real_color = y->color;
    Node *x;
    if (z->left == nullptr) {
      x = z->right;
      transplant(z, z->right);
    } else if (z->right == nullptr) {
      x = z->left;
      transplant(z, z->left);
    } else {
      y = min(z->right);
      y_real_color = y->color;
      x = y->right;
      if (y->parent == z) {
        x->parent = y;
      } else {
        transplant(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      }
      transplant(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }
    if (y_real_color == Color::BLACK) {
      fix_delete(x);
    }
    delete z;
  }

  ~RBTree() { delete_node(root); }
};

int main() {

  enum {
    MOD = 1000000000,
  };

  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  RBTree<int> rbtree;

  int prev = 0;
  for (int i = 0; i < n; ++i) {
    std::string cmd;
    int a;
    std::cin >> cmd >> a;
    if (cmd == "+") {
      a = (a + prev) % MOD;
      if (!rbtree.contains(a)) {
        rbtree.insert(a);
      }
      prev = 0;
    } else if (cmd == "?") {
      auto cur = rbtree.upper_bound(a);
      prev = cur == nullptr ? -1 : *cur;
      std::cout << prev << std::endl;
    } else {
      throw 1;
    }
  }

  return 0;
}
