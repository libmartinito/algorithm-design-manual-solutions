// goal: given two binary search trees, merge into a doubly linked list in
// sorted order

#include <iostream>
#include <string>

struct Node {
  int val;
  Node *prev;
  Node *next;

  Node(int val = -1) : val(val), prev(nullptr), next(nullptr) {}
};

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

void insert_doubly_linked_list_node(int val, Node *curr) {
  if (curr->val == -1) {
    curr->val = val;
    return;
  }

  while (curr->next != nullptr && val > curr->next->val) {
    curr = curr->next;
  }

  if (curr->next == nullptr) {
    curr->next = new Node(val);
    curr->next->prev = curr;

    return;
  }

  Node *new_node{new Node(val)};
  new_node->next = curr->next;
  new_node->prev = curr;
  curr->next->prev = new_node;
  curr->next = new_node;

  return;
}

void add_leaf_nodes_to_list(LeafNode *tree_node, Node *&list_node) {
  if (tree_node == nullptr) {
    return;
  }

  add_leaf_nodes_to_list(tree_node->left, list_node);
  insert_doubly_linked_list_node(tree_node->val, list_node);
  add_leaf_nodes_to_list(tree_node->right, list_node);

  return;
}

int main() {
  LeafNode *first_tree_head{new LeafNode(2)};
  insert_bst_node(1, first_tree_head);
  insert_bst_node(3, first_tree_head);

  LeafNode *second_tree_head{new LeafNode(5)};
  insert_bst_node(4, second_tree_head);
  insert_bst_node(6, second_tree_head);

  Node *list_head{new Node()};

  add_leaf_nodes_to_list(first_tree_head, list_head);
  add_leaf_nodes_to_list(second_tree_head, list_head);

  std::string expected_output{""};

  while (list_head) {
    expected_output += std::to_string(list_head->val);
    list_head = list_head->next;
  }

  std::cout << expected_output << std::endl;
  if (expected_output == "123456") {
    std::cout << "merging trees to a sorted doubly linked list works!\n";
  } else {
    std::cout << "wrong.\n";
  }
}
