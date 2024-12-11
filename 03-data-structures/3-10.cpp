// goal: make an algorithm that determines whether or not two strings are
// anagrams
//
// example:
//
// silent / listen are anagrams
// insect / incest are anagrams
//

#include <iostream>
#include <map>
#include <string>

bool isAnagram(std::string first, std::string second) {
  if (first.size() != second.size()) {
    return false;
  }

  std::map<char, int> first_char_count_map{};
  std::map<char, int> second_char_count_map{};

  for (char ch : first) {
    first_char_count_map[ch]++;
  }

  for (char ch : second) {
    second_char_count_map[ch]++;
  }

  for (auto char_count : first_char_count_map) {
    if (char_count.second != second_char_count_map[char_count.first]) {
      return false;
    }
  }

  return true;
}

int main() {
  if (isAnagram("silent", "listen")) {
    std::cout << "silent and listen are anagrams!\n";
  } else {
    std::cout << "wrong.\n";
  }

  if (isAnagram("insect", "incest")) {
    std::cout << "insect and incest are anagrams!\n";
  } else {
    std::cout << "wrong\n";
  }
}
