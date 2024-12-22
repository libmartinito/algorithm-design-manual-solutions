// goal: create a dictionary data structure
//
// insertion should be O(1)
// deletion should be O(1)
// search should be O(1)
//
// elements are drawn from a finite set of integers
// 1, 2, 3 ... n

#include <iostream>
#include <vector>

struct Dictionary {
  std::vector<int> store;

  Dictionary(int size) : store(size, -1) {}

  void insert_val(int num) { store[num - 1] = num; }

  int search_val(int num) {
    if (store[num - 1] == -1) {
      return -1;
    }

    return store[num - 1];
  }

  void delete_val(int num) { store[num - 1] = -1; }
};

int main() {
  Dictionary *dict{new Dictionary(5)};

  dict->insert_val(1);
  dict->insert_val(2);

  if (dict->search_val(2) == 2) {
    std::cout << "insertion and search works!\n";
  } else {
    std::cout << "wrong.\n";
  }

  dict->delete_val(2);

  if (dict->search_val(2) == -1) {
    std::cout << "deletion works!\n";
  } else {
    std::cout << "wrong.\n";
  }
}
