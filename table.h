#ifndef TABLE_H
#define TABLE_H

#include <vector>

#include "entry.h"

class table {
 private:
  std::string _name = "todo";
  std::vector<entry> _table;
  std::string _data_loc;

 public:
  table() = default;
  table(std::string n);
  // take the name checks if its exists else constructs new table

 public:  // functions for saving an loading data
  bool data_exist();

  std::string get_loc(std::string& name) {
    _data_loc = "../data/" + _name + ".txt";
    std::cout << _data_loc << '\n';
  }

  friend std::ostream& operator<<(std::ostream&, const table&);
  friend std::istream& operator<<(std::istream&, table&);
  void put_entry(std::string, int);
  void mod_entry(int, std::string);
  void save_table();
  // table load_table();

 public:
  void delete_entry(int i) { _table.erase(_table.begin() + i); }
  int get_size() { return _table.size(); };
  void print_table() { std::cout << *this; }
};

table load_table();

#endif /* end of include guard: TABLE_H */
