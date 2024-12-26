// goal: make an algorithm that takes an n-node binary search tree and create an
// equivalent balanced binary search tree in O(n) time

#include <cmath>
#include <iostream>
#include <vector>

struct LeafNode {
  int val;
  LeafNode *left;
  LeafNode *right;

  LeafNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

void insert_bst_node(int val, LeafNode *curr) {
  LeafNode *&next_node = val < curr->val ? curr->left : curr->right;

  if (next_node == nullptr) {
    next_node = new LeafNode(val);
  } else {
    insert_bst_node(val, next_node);
  }

  return;
}

void getTreeElements(LeafNode *node, std::vector<int> &tree_elements) {
  if (node == nullptr) {
    return;
  }

  getTreeElements(node->left, tree_elements);
  tree_elements.push_back(node->val);
  getTreeElements(node->right, tree_elements);

  return;
}

LeafNode *getBalancedTree(LeafNode *head) {
  std::vector<int> tree_elements;
  getTreeElements(head, tree_elements);

  size_t median_index{tree_elements.size() / 2};
  LeafNode *balanced_tree_head{new LeafNode(tree_elements[median_index])};

  for (size_t i = 0; i < tree_elements.size(); i++) {
    if (i == median_index) {
      continue;
    }

    insert_bst_node(tree_elements[i], balanced_tree_head);
  }

  return balanced_tree_head;
}

int main() {
  LeafNode *unbalanced_tree_head{new LeafNode(6)};
  insert_bst_node(7, unbalanced_tree_head);
  insert_bst_node(8, unbalanced_tree_head);

  LeafNode *balanced_tree_head{getBalancedTree(unbalanced_tree_head)};
  if (balanced_tree_head->val == 7 && balanced_tree_head->left->val == 6 &&
      balanced_tree_head->right->val == 8) {
    std::cout << "algorithm for balancing tree worked!\n";
  } else {
    std::cout << "wrong.\n";
  }
}
