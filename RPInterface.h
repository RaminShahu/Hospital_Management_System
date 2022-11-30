#include "Interface.h"
#ifndef RPINTERFACE_H
#define RPINTERFACE_H

class RPInterface : public Interface {
 public:
  RPInterface(Hospital* hospital1) { this->hospital = hospital1; }
  RPInterface() {}
  void writeOnFile();
 
};

#endif