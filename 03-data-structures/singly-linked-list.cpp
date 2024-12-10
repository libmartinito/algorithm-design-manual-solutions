// we want to support:
//
// search(list, num)
// insert(num)
// delete(num)
//

#include <iostream>

struct Node {
  int num;
  Node *next;

  Node(int value) : num(value), next(nullptr) {}
  Node() : num(-1), next(nullptr) {} // use -1 to represent 'empty'
};

// since we don't go through the entire list,
// time complexity is O(1)
void insertNode(Node *&head, int num) {
  if (head->num == -1) {
    head = new Node(num);
    return;
  }

  Node *node = new Node(num);
  node->next = head;
  head = node;

  return;
}

// worst case is when element is at the end,
// time complexity is O(n)
Node *searchNode(Node *&head, int num) {
  if (head->num == num) {
    return head;
  }

  if (head->next == nullptr) {
    return new Node();
  }

  return searchNode(head->next, num);
}

Node *getNodeBefore(Node *&head, int num) {
  if (head->next == nullptr) {
    return new Node();
  }

  if (head->next->num == num) {
    return head;
  }

  return getNodeBefore(head->next, num);
}

// so we need to get the item before what we
// want to delete first
//
// worst case is that the item to be deleted is at the end
// time complexity is O(n)
void deleteNode(Node *&head, int num) {
  // when deleting at the head
  if (head->num == num && head->next != nullptr) {
    head = head->next;
  } else {
    head = new Node();
  }

  Node *node_before = getNodeBefore(head, num);

  // return if no node before target
  if (node_before->num == -1) {
    return;
  }

  Node *temp_node = node_before->next;
  node_before->next = node_before->next->next;
  temp_node->next = nullptr;

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

  deleteNode(node, 1);

  if (node->next == nullptr) {
    std::cout << "deleting a node works!\n";
  } else {
    std::cout << "error with deleting a node\n";
  }

  deleteNode(node, 2);

  if (node->num == -1) {
    std::cout << "deleting a node at the head works!\n";
  } else {
    std::cout << "error with deleting a node at the head\n";
  }
}
