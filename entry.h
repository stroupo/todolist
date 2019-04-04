#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>
#include <tuple>

struct entry {
 public:
  int _priority = 1;  // whatever = 0, normal = 1, important = 2
  std::string _desc = "some task";

 public:
  entry() = default;
  entry(std::string d, int p = 1) : _desc{d}, _priority{p} {};

  std::tuple<std::string, int> get_detail() const {
    return std::make_tuple(_desc, _priority);
  };
  void set_priority(int prio) { _priority = prio; };
  void mod_task(std::string new_desc) { _desc = new_desc; };
  void print() const { std::cout << _desc << '\t' << _priority << '\n'; };
};

#endif /* end of include guard: ENTRY_H */
