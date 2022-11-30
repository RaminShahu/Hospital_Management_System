#ifndef DPINTERFACE_H
#define DPINTERFACE_H
#include "Interface.h"
// Class for deregister patient interface
class DPInterface : public Interface {
 public:
  DPInterface(Hospital* hospital1) { this->hospital = hospital1; }
  DPInterface() {}
  void writeOnFile();

  
  
};

#endif