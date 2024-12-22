// goal: create an algorithm with runtime of O(n)
// that finds the maximum depth of a binary tree

#include <algorithm>
#include <iostream>

struct Node {
  int val;
  Node *parent;
  Node *left;
  Node *right;

  Node(int val) : val(val), parent(nullptr), left(nullptr), right(nullptr) {}
};

void insertNode(Node *node, int val, Node *parent = nullptr) {
  if (node == nullptr) {
    Node *new_node = new Node(val);
    new_node->parent = parent;

    if (val < parent->val) {
      parent->left = new_node;
    } else {
      parent->right = new_node;
    }

    return;
  }

  if (val < node->val) {
    insertNode(node->left, val, node);
  } else {
    insertNode(node->right, val, node);
  }

  return;
}

int getMaxDepth(Node *node, int count = 0) {
  if (node == nullptr) {
    return count;
  }

  int leftResult{getMaxDepth(node->left, count + 1)};
  int rightResult{getMaxDepth(node->right, count + 1)};

  return std::max(leftResult, rightResult);
}

int main() {
  Node *head = new Node(2);
  insertNode(head, 1);
  insertNode(head, 3);
  insertNode(head, 4);

  int max_depth = getMaxDepth(head);

  if (max_depth == 3) {
    std::cout << "finding max depth works!\n";
  } else {
    std::cout << "wrong.";
  }
}
