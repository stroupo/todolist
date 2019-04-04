#include <fstream>
#include <sstream>

#include "entry.h"
#include "table.h"

// nicht durch CMakeList.txt genutzt

int main(int argc, char const *argv[]) {
  /*
    entry entry1("Programming mergesort", 2);
    entry entry2("Reading a Book", 0);
    entry entry3;

    entry1.set_priority(1);
  */

  int sel;

  if (!(std::istringstream(argv[1]) >> sel))
    std::cerr << "Forgot input arg!" << '\n';

  if (sel == 1) {
    std::cout << "Test of Table" << '\n';

    table todo;

    todo.put_entry("Test mit String und Priorität", 2);
    todo.put_entry("Test2 nur mit String", 1);
    todo.put_entry("Test3 nur mit String", 2);
    todo.print_table();

    std::cout << "Test Modify" << '\n';
    todo.mod_entry(1, "Test der Modifikation");
    todo.mod_entry(4, "Test der Modifikation");
    todo.print_table();

    std::cout << "Test Delete" << '\n';
    todo.delete_entry(1);
    todo.print_table();

    todo.put_entry("Test der Formatierung", 0);
    todo.put_entry("Test 2", 0);
    todo.put_entry("Test 3", 0);
    todo.put_entry("Test 4", 0);

    todo.save_table();
    //  todo.get_loc("todo");
  }
  if (sel == 2) {
    std::cout << "Test of load function" << '\n';
    // todo3.get_loc()
    table todo3;
    // todo3.get_size();
    todo3 = load_table();
    todo3.print_table();
  }
  // todo.SaveData();

  return 0;
}
