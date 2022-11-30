#ifndef MENU_H
#define MENU_H
#include <fstream>

#include "Interface.h"
class Menu : public Interface {
 public:
  Menu(Hospital* hospital) { this->hospital = hospital; };
  Menu(){};
  void displayMenu();
  void writeOnFile();
};

#endif