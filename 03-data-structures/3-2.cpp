// goal: get number of valid parenthesis
//
// string: )()(())()()))())))(
// number: 12

#include <iostream>
#include <stack>
#include <string>

int getBalancedParenthesesLength(std::string line) {
  int balanced_parentheses_count{0};
  std::stack<char> stack;

  for (char ch : line) {
    if (stack.size() != 0 && stack.top() == '(' && ch == ')') {
      balanced_parentheses_count += 2;
      stack.pop();
      continue;
    }

    stack.push(ch);
  }

  return balanced_parentheses_count;
}

int main() {
  std::string line = ")()(())()()))())))(";

  if (getBalancedParenthesesLength(line) == 12) {
    std::cout << "correct!\n";
  } else {
    std::cout << "wrong!\n";
  }
}
