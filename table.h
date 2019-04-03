#ifndef TABLE_H
#define TABLE_H

#include <vector>

#include "entry.h"

class table {
 private:
  std::vector<entry> m_table;

 public:
  table() = default;
  table(std::vector<entry>);
  friend std::ostream& operator<<(std::ostream&, const table&);
  void put_entry(std::string, entry::Priority);
  void mod_entry(int, std::string);
  void save_table(const table& table);
  void load_table();

 public:
  void delete_entry(int i) { m_table.erase(m_table.begin() + i); }
  int get_size() { return m_table.size(); };
  void print_table(const table& table) { std::cout << table; }
};

#endif /* end of include guard: TABLE_H */
