#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QPushButton;
class Window : public QWidget {
  Q_OBJECT
 public:
  explicit Window(QWidget *parent = 0);
 private slots:
  void slotAddEntryButtonClicked(bool checked);

 private:
  QPushButton *_add_entry_button;
};

#endif /* end of include guard: WINDOW_H */
