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
  void mod_priority(int prio) { _priority = prio; };
  void mod_task(std::string new_desc) { _desc = new_desc; };

  std::tuple<std::string, int> get_detail() const {
    return {_desc, _priority};
  };

  friend std::ostream& operator<<(std::ostream& os, const entry& entry);
};

#endif /* end of include guard: ENTRY_H */
