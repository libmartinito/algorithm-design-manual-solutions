// goal: design a stack that supports push(x), pop(), and findmin()
// which returns the minimum element of the stack.
//
// operations should run in constant time.
//

#include <iostream>
#include <vector>

struct Stack {
  std::vector<int> stack{};
  std::vector<int> min{};

  void push(int num) {
    stack.push_back(num);

    if (min.size() == 0) {
      min.push_back(num);

      return;
    }

    if (min.back() > num) {
      min.push_back(num);
    } else {
      min.push_back(min.back());
    }

    return;
  }

  void pop() {
    stack.pop_back();
    min.pop_back();
  }

  int findmin() { return min.back(); }
};

int main() {
  Stack stack{};

  stack.push(3);
  stack.push(2);

  if (stack.findmin() == 2) {
    std::cout << "findmin works!\n";
  } else {
    std::cout << "findmin doesn't work.\n";
  }

  stack.pop();

  if (stack.findmin() == 3) {
    std::cout << "findmin works!\n";
  } else {
    std::cout << "findmin doesn't work.\n";
  }
}
