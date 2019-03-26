#include "list.h"

// nicht durch CMakeList.txt genutzt

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

  std::cout << "Test Modify" << '\n';
  todo.ModEntry(1, "Test der Modifikation");
  todo.ModEntry(4, "Test der Modifikation");
  todo.Print_table();

  std::cout << "Test Delete" << '\n';
  todo.DeleteEntry(1);
  todo.Print_table();

  return 0;
}
