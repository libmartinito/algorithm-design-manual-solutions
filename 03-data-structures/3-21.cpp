// goal: concatenate two trees into one binary tree. all the values for one
// binary tree is smaller than all the values for the other. the worst case
// running time should be O(h)

#include <iostream>
struct Node {
  int val;
  Node *parent;
  Node *left;
  Node *right;

  Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

void insertBSTNode(int val, Node *curr) {
  Node *new_node{new Node(val)};

  if (val < curr->val) {
    if (curr->left == nullptr) {
      new_node->parent = curr;
      curr->left = new_node;
    } else {
      insertBSTNode(val, curr->left);
    }
  } else {
    if (curr->right == nullptr) {
      new_node->parent = curr;
      curr->right = new_node;
    } else {
      insertBSTNode(val, curr->right);
    }
  }
  return;
}

Node *getMaxNode(Node *node) {
  while (node->right != nullptr) {
    node = node->right;
  }

  return node;
}

Node *getMinNode(Node *node) {
  while (node->left != nullptr) {
    node = node->left;
  }

  return node;
}

Node *mergeTrees(Node *node, Node *other_node) {
  Node *large_val_tree_min_node{nullptr};

  large_val_tree_min_node =
      node->val < other_node->val ? getMinNode(other_node) : getMinNode(node);

  large_val_tree_min_node->right = large_val_tree_min_node->parent;
  large_val_tree_min_node->parent = nullptr;

  large_val_tree_min_node->left =
      node->val < other_node->val ? node : other_node;

  return large_val_tree_min_node;
}

int main() {
  Node *tree_with_small_val{new Node(2)};
  insertBSTNode(1, tree_with_small_val);
  insertBSTNode(2, tree_with_small_val);

  Node *tree_with_large_val{new Node(5)};
  insertBSTNode(4, tree_with_large_val);
  insertBSTNode(6, tree_with_large_val);

  Node *merged_trees_head{mergeTrees(tree_with_small_val, tree_with_large_val)};

  if (merged_trees_head->val == 4 && merged_trees_head->left->val == 2 &&
      merged_trees_head->right->val == 5) {
    std::cout << "merging trees successful!\n";
  } else {
    std::cout << "wrong.\n";
  }
}
