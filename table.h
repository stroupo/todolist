#ifndef TABLE_H
#define TABLE_H

#include <sstream>
#include <tuple>
#include <vector>

#include "entry.h"

class table {
 private:
  std::string _name = "todo";
  std::vector<entry> _table;
  std::string _data_loc;

 public:
  table() = default;

 public:
  const entry& operator[](std::size_t idx) const { return _table[idx]; };
  friend std::ostream& operator<<(std::ostream&, const table&);
  friend std::istream& operator<<(std::istream&, table&);

  void add_entry(std::string, int prio = 1);
  void mod_entry(int idx, std::string new_descr);
  std::string show_entry(std::size_t idx);
  void save_table();

 public:
  void delete_entry(int i) { _table.erase(_table.begin() + i); }
  int get_size() { return _table.size(); };
  void print_table() { std::cout << *this; }
};

table load_table();

template <typename T>
std::string to_string(const T& object) {
  std::ostringstream oss;
  oss << object;
  return oss.str();
}

#endif /* end of include guard: TABLE_H */
