#include <iostream>

#include "GNWard.h"

#ifndef PVWARD_H
#define PVWARD_H

class PVWard : public GNWard {
 public:
  static int count1;
  PVWard();
  void dispDescription();
  bool addPatient(Patient patient1);
  void dispInfo();
  ~PVWard();
};

#endif
