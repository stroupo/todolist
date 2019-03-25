

#include "list.h"

int main(int argc, char const *argv[]) {
  // std::cout << "Test" << '\n';

  Entry entry1("Programming mergesort", Entry::important);
  Entry entry2("Reading a Book", Entry::whatever);
  Entry entry3;

  entry1.SetPriority(Entry::normal);

  std::cout << "Test of Table" << '\n';

  Table todo;

  todo.PutEntry("Test mit String und Priorität", Entry::important);
  todo.PutEntry("Test2 nur mit String");

  todo.Print_table();
  return 0;
}
