#include <sstream>

#include "entry.h"

std::ostream& operator<<(std::ostream& os, const entry& entry) {
  os << entry._desc << "," << entry._priority << '\n';
  return os;
}
