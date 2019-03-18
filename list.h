#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>

// Entry in To-Do list
class Entry {
 public:
  enum Priority { whatever = 0, normal, important };

  // ID of the Task.. increments when adding new tasks and decrements when
  // deleting
  static int id_inc;

 private:
  int m_taskid = ++id_inc;
  std::string m_desc = "'new task...'";
  Priority m_priority = normal;

 public:
  Entry() = default;
  Entry(std::string d, Priority p)
      : m_desc{d}, m_priority{p}, m_taskid{++id_inc} {};

  int IncrId(int m_taskid) { return id_inc; };
  void SetPriority(Priority prio) { m_priority = prio; };
  void ModTask(std::string mod_desc) { m_desc = mod_desc; };

  void Print(/*int m_taskid*/) {
    std::cout << m_taskid << "," << m_desc << "," << m_priority << '\n';
  };
};

class Table {
 private:
  std::string m_name = "Default To-Do";
  std::vector<Entry> m_table;

 public:
  Table() = default;
  Table(std::string n) : m_name{n}, m_table{} {};
  void Print_table() {
    for (int i = 0; i < m_table.size(); ++i) {
      m_table[i].Print();
    }
  }
};

int Entry::id_inc = 0;

std::vector<Entry> table;

#endif /* end of include guard: LIST_H */
