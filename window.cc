#include "window.h"
#include "table.h"

#include <QApplication>
#include <QPushButton>

Window::Window(QWidget *parent) : QWidget(parent) {
  setFixedSize(400, 200);

  _add_entry_button = new QPushButton("Add Entry", this);
  _add_entry_button->setGeometry(10, 10, 80, 30);

  connect(_add_entry_button, SIGNAL(clicked(bool)), this,
          SLOT(slotAddEntryButtonClicked(bool)));
}

void Window::slotAddEntryButtonClicked(bool clicked) {
  if (clicked) {
    table todo;
    todo.add_entry("Added with Puttonclick");
  }
}
