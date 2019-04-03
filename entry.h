#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>
#include <tuple>

class entry {
 public:
  enum Priority { whatever = 0, normal, important };

 private:
  // std::tuple<string, Priority> task =
  std::string m_desc = "some task";
  Priority m_priority = normal;

 public:
  entry() = default;
  entry(std::string d, Priority p = normal) : m_desc{d}, m_priority{p} {};

  // some member-functions
  std::tuple<std::string, Priority> get_detail() const {
    return std::make_tuple(m_desc, m_priority);
  };
  void set_priority(Priority prio) { m_priority = prio; };
  void mod_task(std::string mod_desc) { m_desc = mod_desc; };
  void print() const { std::cout << m_desc << '\t' << m_priority << '\n'; };
};

#endif /* end of include guard: ENTRY_H */
