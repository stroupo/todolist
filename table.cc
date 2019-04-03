#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

#include "entry.h"
#include "table.h"

table::table(std::vector<entry> t) : m_table{t} {};

std::ostream& operator<<(std::ostream& os, const table& table) {
  int i = 0;
  for (auto& x : table.m_table) {
    auto [desc, priori] = x.get_detail();
    os << std::left << std::setw(3) << i << std::setw(40) << desc
       << std::setw(3) << priori << '\n';
    ++i;
  }
  return os;
}

void table::put_entry(std::string entr_name,
                      entry::Priority prio = entry::normal) {
  m_table.emplace_back(entr_name, prio);
}

void table::mod_entry(int i, std::string s) {
  if (i < m_table.size()) {
    m_table[i].mod_task(s);
  } else
    std::cerr << "Dieser Eintrag ist nicht vorhanden" << '\n';
}

void table::delete_entry(int i) { m_table.erase(m_table.begin() + i); }

void table::save_table(const table& table) {
  std::ofstream out("../data/todo.txt");
  out << table;
  out.close();
}
