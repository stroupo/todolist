#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "list.h"

Table todo;

TEST_CASE("testing init and entry input") {
  CHECK(todo.GetSize() == 0);

  todo.PutEntry("Hallo");
  CHECK(todo.GetSize() == 1);
}
