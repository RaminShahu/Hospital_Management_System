#ifndef INTERFACE_H
#define INTERFACE_H
#include <fstream>
#include "Hospital.h"
// Absract class for Interface
class Interface {
 public:
  Hospital* hospital;
  Interface() {}
  virtual void writeOnFile() = 0;
};

#endif