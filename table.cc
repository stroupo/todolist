#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "entry.h"
#include "table.h"

std::ostream& operator<<(std::ostream& os, const table& table) {
  for (auto& x : table._table) {
    auto [desc, priori] = x.get_detail();
    os << desc << "," << priori << '\n';
  }
  return os;
}

std::istream& operator>>(std::istream& is, table& table) {
  std::string desc, prio;
  if (std::getline(is, desc, ',') && std::getline(is, prio)) {
    table.add_entry(desc, std::stoi(prio));
  }
  return is;
}

void table::add_entry(std::string entr_name, int prio) {
  _table.emplace_back(entr_name, prio);
}

void table::mod_entry(int i, std::string s) {
  if (i < _table.size()) {
    _table[i].mod_task(s);
  } else
    std::cerr << "Dieser Eintrag ist nicht vorhanden" << '\n';
}

std::string table::show_entry(std::size_t idx) {
  if (idx < _table.size()) {
    return to_string(_table[idx]._desc);
  } else
    std::cerr << "No such entry" << '\n';
}

void table::save_table() {
  std::ofstream out("../data/" + _name + ".txt");
  out << *this;
  out.close();
}

// non-member-function
table load_table() {
  table table;
  std::ifstream infile("../data/todo.txt");
  while (!infile.eof()) infile >> table;
  return table;
}
