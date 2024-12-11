// goal: make a function with the following behavior
//
// input: series of digits (2 - 9), dictionary of n words
// output: words described by sequence when typed on keypad
//
// example:
//
// 269 returns any, box, boy, and cow

#include <iostream>
#include <map>
#include <string>
#include <vector>

int getNumberFromChar(std::map<int, std::vector<char>> number_char_map,
                      char target) {
  for (auto number_char : number_char_map) {
    for (char ch : number_char.second) {
      if (ch == target) {
        return number_char.first;
      }
    }
  }

  return -1;
}

std::vector<std::string> getWordsFromSequence(std::vector<int> sequence,
                                              std::vector<std::string> words) {
  std::map<int, std::vector<char>> number_char_map{
      {2, {'a', 'b', 'c'}}, {3, {'d', 'e', 'f'}},
      {4, {'g', 'h', 'i'}}, {5, {'j', 'k', 'l'}},
      {6, {'m', 'n', 'o'}}, {7, {'p', 'q', 'r', 's'}},
      {8, {'t', 'u', 'v'}}, {9, {'w', 'x', 'y', 'z'}},
  };

  std::vector<std::string> result{};

  for (std::string word : words) {
    std::vector<int> nums;

    for (char ch : word) {
      nums.push_back(getNumberFromChar(number_char_map, ch));
    }

    if (nums == sequence) {
      result.push_back(word);
    }
  }

  return result;
};

int main() {
  std::vector<std::string> result =
      getWordsFromSequence({2, 6, 9}, {"any", "box", "boy", "cow", "python"});

  std::vector<std::string> expected = {"any", "box", "boy", "cow"};

  if (result == expected) {
    std::cout << "correct!\n";
  } else {
    std::cout << "wrong.\n";
  }
}
