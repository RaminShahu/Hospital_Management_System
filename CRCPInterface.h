#ifndef CRPCINTERFACE_H
#define CRPCINTERFACE_H
#include "Interface.h"
// Class for checking record of current registered patient
class CRCPInterface : public Interface {
 public:
  CRCPInterface(Hospital* hospital1) { this->hospital = hospital1; }
  CRCPInterface() {}

  void writeOnFile();
};
#endif
