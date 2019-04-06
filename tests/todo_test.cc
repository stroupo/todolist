#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "table.h"

table todo;

TEST_CASE("testing construction and init") {
  todo.add_entry("Hello World Todolist");
  CHECK(todo[0].get_detail() == std::tuple("Hello World Todolist", 1));
  CHECK(todo.show_entry(0) == "Hello World Todolist");
}
