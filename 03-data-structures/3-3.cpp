// goal: make an algorithm that reverses a singly linked list in linear time

#include <iostream>
#include <vector>

struct Node {
  int num;
  Node *next;

  Node(int value) : num(value), next(nullptr) {}
};

Node *reverseLinkedList(Node *node) {
  std::vector<Node *> nodes;

  while (node != nullptr) {
    nodes.push_back(node);
    node = node->next;
  }

  for (size_t i = 0; i < nodes.size(); i++) {
    if (i == 0) {
      nodes[i]->next = nullptr;
      continue;
    }

    nodes[i]->next = nodes[i - 1];
  }

  return nodes.back();
}

int main() {
  Node *head = new Node(1);
  Node *second = new Node(2);
  Node *third = new Node(3);

  head->next = second;
  second->next = third;

  Node *node = reverseLinkedList(head);

  std::vector<int> nums{};

  while (node != nullptr) {
    nums.push_back(node->num);
    node = node->next;
  }

  if (nums[0] == 3 && nums[1] == 2 && nums[2] == 1) {
    std::cout << "correct!\n";
  } else {
    std::cout << "wrong!\n";
  }
}
