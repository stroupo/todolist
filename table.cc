#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "entry.h"
#include "table.h"
/*
table::table(std::string n) {
  _name = n;
  // get_loc(n);
  if (data_exist()) {
    load_table();
    std::cout << "data exists" << '\n';
  } else
    std::cout << "new table generated" << '\n';
}
*/

bool table::data_exist() {
  std::ifstream f("../data/todo.txt");
  return f.good();
}

std::ostream& operator<<(std::ostream& os, const table& table) {
  for (auto& x : table._table) {
    auto [desc, priori] = x.get_detail();
    os << std::left << std::setw(40) << desc << ", " << std::setw(3) << priori
       << '\n';
  }
  return os;
}

std::istream& operator>>(std::istream& is, table& table) {
  std::string desc, prio;
  if (std::getline(is, desc, ',') && std::getline(is, prio)) {
    table.put_entry(desc, std::stoi(prio));
  }
  return is;
}

void table::put_entry(std::string entr_name, int prio = 1) {
  _table.emplace_back(entr_name, prio);
}

void table::mod_entry(int i, std::string s) {
  if (i < _table.size()) {
    _table[i].mod_task(s);
  } else
    std::cerr << "Dieser Eintrag ist nicht vorhanden" << '\n';
}

void table::save_table() {
  std::ofstream out("../data/" + _name + ".txt");
  out << *this;
  out.close();
}

table load_table() {  // std::string data_loc
  table table;
  std::ifstream infile("../data/todo.txt");
  while (!infile.eof()) infile >> table;
  return table;
  /*
     std::string line;
    while (std::getline(infile, line, ',')) {
      std::string n;
      int prio;
      std::istringstream iss(line);
      if (iss >> n >> prio) {
        this->put_entry(n, prio);
      }
    }
    */
}
