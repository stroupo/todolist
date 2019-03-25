#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>

// Entry in To-Do list
class Entry {
 public:
  enum Priority { whatever = 0, normal, important };

 private:
  std::string m_desc = "'new task...'";
  Priority m_priority = normal;

 public:
  Entry() = default;
  Entry(std::string d, Priority p = normal) : m_desc{d}, m_priority{p} {};

  void SetPriority(Priority prio) { m_priority = prio; };
  void ModTask(std::string mod_desc) { m_desc = mod_desc; };

  void Print() const { std::cout << m_desc << '\t' << m_priority << '\n'; };
};

// Table that holds the Entrys
class Table {
 private:
  std::string m_name = "Default Table";
  std::vector<Entry> m_table;

 public:
  Table() = default;
  Table(std::string, std::vector<Entry>);
  void PutEntry(std::string, Entry::Priority);
  // void ModEntry()
  // void DeleteEntry()
  int GetSize() { return m_table.size(); };
  void Print_table();
};

Table::Table(std::string n, std::vector<Entry> t) {
  m_name = n;
  m_table = t;
}

void Table::PutEntry(std::string entr_name,
                     Entry::Priority prio = Entry::normal) {
  // perfect forwarding by emplace_back
  m_table.emplace_back(entr_name, prio);
}

void Table::Print_table() {
  for (int i = 0; i < m_table.size(); ++i) {
    std::cout << i << '\t';
    m_table[i].Print();
  }
}

#endif /* end of include guard: LIST_H */
