// goal: make an algorithm that determines if a binary search tree is balanced
// in O(n) time

#include <cmath>
#include <iostream>

struct LeafNode {
  int val;
  LeafNode *left;
  LeafNode *right;

  LeafNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

void insertBSTNode(int val, LeafNode *curr) {
  LeafNode *&next_node = val < curr->val ? curr->left : curr->right;

  if (next_node == nullptr) {
    next_node = new LeafNode(val);
  } else {
    insertBSTNode(val, next_node);
  }

  return;
}

int checkIfTreeIsBalanced(LeafNode *curr, bool &is_tree_balanced) {
  if (curr == nullptr) {
    return 0;
  }

  int left_node_count = checkIfTreeIsBalanced(curr->left, is_tree_balanced);
  int right_node_count = checkIfTreeIsBalanced(curr->right, is_tree_balanced);

  if (std::abs(right_node_count - left_node_count) > 1) {
    is_tree_balanced = false;
  }

  return left_node_count + right_node_count + 1;
}

int main() {
  LeafNode *head{new LeafNode(6)};
  insertBSTNode(7, head);
  insertBSTNode(5, head);

  bool is_tree_balanced{true};
  checkIfTreeIsBalanced(head, is_tree_balanced);

  if (is_tree_balanced) {
    std::cout << "algorithm correctly checks if tree is balanced!\n";
  } else {
    std::cout << "wrong.\n";
  }

  insertBSTNode(4, head);
  insertBSTNode(3, head);
  checkIfTreeIsBalanced(head, is_tree_balanced);

  if (!is_tree_balanced) {
    std::cout << "algorithm correctly checks if tree is not balanced!\n";
  } else {
    std::cout << "wrong.\n";
  }
}
