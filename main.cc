#include <fstream>

#include "entry.h"
#include "table.h"

// nicht durch CMakeList.txt genutzt

int main(int argc, char const *argv[]) {
  // std::cout << "Test" << '\n';

  entry entry1("Programming mergesort", entry::important);
  entry entry2("Reading a Book", entry::whatever);
  entry entry3;

  entry1.set_priority(entry::normal);

  std::cout << "Test of Table" << '\n';

  table todo;

  todo.put_entry("Test mit String und Priorität", entry::important);
  todo.put_entry("Test2 nur mit String", entry::important);
  todo.print_table(todo);

  std::cout << "Test Modify" << '\n';
  todo.mod_entry(1, "Test der Modifikation");
  todo.mod_entry(4, "Test der Modifikation");
  todo.print_table(todo);

  std::cout << "Test Delete" << '\n';
  todo.delete_entry(1);
  todo.print_table(todo);

  todo.put_entry("Test der Formatierung", entry::whatever);
  todo.put_entry("Test 2", entry::whatever);
  todo.put_entry("Test 3", entry::whatever);
  todo.put_entry("Test 4", entry::whatever);

  //  std::ofstream out("todo.txt");
  //  out << todo;
  //  out.close();

  todo.save_table(todo);

  // todo.SaveData();

  return 0;
}
