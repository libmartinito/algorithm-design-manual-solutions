// goal: make an algorithm that finds two nodes
// that are switched in a binary search tree
// in O(n) time

#include <iostream>
#include <vector>

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

void getNodesInOrder(Node *node, std::vector<Node *> &nodes) {
  if (node == nullptr) {
    return;
  }

  getNodesInOrder(node->left, nodes);

  nodes.push_back(node);

  getNodesInOrder(node->right, nodes);

  return;
}

std::vector<Node *> getSwappedNodes(Node *head) {
  std::vector<Node *> nodes{};
  getNodesInOrder(head, nodes);

  if (nodes.size() == 2) {
    return nodes;
  }

  int lo = 0;
  int hi = nodes.size() - 1;

  while (nodes[lo]->val < nodes[lo + 1]->val) {
    lo++;
  }

  while (nodes[hi]->val > nodes[hi - 1]->val) {
    hi--;
  }

  return {nodes[lo], nodes[hi]};
};

int main() {
  Node *head = new Node(1);
  head->left = new Node(2);
  head->right = new Node(3);

  std::vector<Node *> swapped_nodes = getSwappedNodes(head);

  if (swapped_nodes[0]->val == 2 && swapped_nodes[1]->val == 1) {
    std::cout << "first example is correct!\n";
  } else {
    std::cout << "wrong.\n";
  }

  head = new Node(2);
  head->left = new Node(3);
  head->right = new Node(1);

  swapped_nodes = getSwappedNodes(head);

  if (swapped_nodes[0]->val == 3 && swapped_nodes[1]->val == 1) {
    std::cout << "second example is correct!\n";
  } else {
    std::cout << "wrong.\n";
  }

  head = new Node(3);
  head->left = new Node(1);
  head->right = new Node(2);

  swapped_nodes = getSwappedNodes(head);

  if (swapped_nodes[0]->val == 3 && swapped_nodes[1]->val == 2) {
    std::cout << "third example is correct!\n";
  } else {
    std::cout << "wrong.\n";
  }

  head = new Node(4);
  head->left = new Node(1);
  head->right = new Node(3);
  head->right->right = new Node(2);

  swapped_nodes = getSwappedNodes(head);

  if (swapped_nodes[0]->val == 4 && swapped_nodes[1]->val == 2) {
    std::cout << "fourth example is correct!\n";
  } else {
    std::cout << "wrong.\n";
  }
}
