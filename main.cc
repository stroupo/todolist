#include "list.h"

int main(int argc, char const *argv[]) {
  std::cout << "Test" << '\n';

  Entry entry1("Programming mergesort", Entry::important);
  Entry entry2("Reading a Book", Entry::whatever);
  Entry entry3;
  entry2.Print();
  entry1.Print();

  entry1.SetPriority(Entry::normal);
  entry1.Print();
  entry3.Print();

  std::cout << '\n';
  std::cout << "Test of Table" << '\n';

  return 0;
}
