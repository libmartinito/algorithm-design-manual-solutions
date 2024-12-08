// goal: check if parentehses are balanced
//
// balanced: ((())())()
// not balanced: )()(
// not balanced: ())

#include <iostream>
#include <stack>
#include <string>

bool areParenthesesBalanced(std::string line) {
  std::stack<char> stack;

  for (char ch : line) {
    if (stack.size() != 0 && stack.top() == '(' && ch == ')') {
      stack.pop();
      continue;
    }

    stack.push(ch);
  }

  if (stack.size() != 0) {
    return false;
  }

  return true;
}

int main() {
  std::string balanced_parens = "((())())()";
  std::string unbalanced_parens = ")()(";
  std::string other_unbalanced_parens = "())";

  if (areParenthesesBalanced(balanced_parens) &&
      !areParenthesesBalanced(unbalanced_parens) &&
      !areParenthesesBalanced(other_unbalanced_parens)) {
    std::cout << "correct!\n";
  } else {
    std::cout << "wrong!\n";
  }
}
