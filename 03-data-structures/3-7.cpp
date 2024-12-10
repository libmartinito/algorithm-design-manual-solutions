// goal: support constant time deletion from a singly linked list.
//
// singly linked list implementation can be seen in ./singly-linked-list.cpp
//

#include <iostream>

struct Node {
  int num;
  Node *next;

  // added sentinel node for handling deletes
  Node(int value) : num(value), next(new Node()) {};
  Node() : num(-1), next() {};
};

void insertNode(Node *&head, int num) {
  if (head->num == -1) {
    // modified to keep sentinel node
    Node *node = new Node(num);
    node->next = head;
    head = node;

    return;
  }

  Node *node = new Node(num);
  node->next = head;
  head = node;

  return;
}

Node *searchNode(Node *&head, int num) {
  if (head->num == num) {
    return head;
  }

  if (head->next == nullptr) {
    return new Node();
  }

  return searchNode(head->next, num);
}

// deleting a node in constant time requires changing
// the interface i originally had
//
// for this to work, you need to already have access
// to the node you want to delete
void deleteNode(Node *node) {
  if (node->next->num == -1) {
    node->num = node->next->num;
    node->next = nullptr;
    return;
  }

  Node *temp_next_next = node->next->next;
  node->num = node->next->num;
  node->next->next = nullptr;
  node->next = temp_next_next;

  return;
}

int main() {
  Node *node = new Node();

  if (node->num == -1) {
    std::cout << "initializing an empty node works!\n";
  } else {
    std::cout << "error with initializing empty node\n";
  }

  insertNode(node, 1);

  if (node->num == 1) {
    std::cout << "inserting a node to an empty list works!\n";
  } else {
    std::cout << "error with inserting a node to an empty list\n";
  }

  insertNode(node, 2);

  if (node->num == 2) {
    std::cout << "inserting a node to an non-empty list works!\n";
  } else {
    std::cout << "error with inserting a node to an non-empty list\n";
  }

  Node *searched_node = searchNode(node, 3);

  if (searched_node->num == -1) {
    std::cout << "searching for a nonexistent node works!\n";
  } else {
    std::cout << "error with searching for a nonexistent node\n";
  }

  searched_node = searchNode(node, 1);

  if (searched_node->num == 1) {
    std::cout << "searching for an existing node works!\n";
  } else {
    std::cout << "error with searching for an existing node\n";
  }

  deleteNode(searched_node);

  if (node->next->num == -1) {
    std::cout << "deleting a node at the end works!\n";
  } else {
    std::cout << "error with deleting a node at the end\n";
  }
}
