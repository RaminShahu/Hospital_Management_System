#include <iostream>

#include "Doctor.h"

#ifndef specialistDoctor_H
#define specialistDoctor_H

class specialistDoctor : public Doctor {
 public:
  specialistDoctor();
  void dispInfo();
  void diagonose(std::string patientName);
  int medication(std::string patientName);
  ~specialistDoctor();
};

#endif
