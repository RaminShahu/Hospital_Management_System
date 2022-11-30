#include <iostream>

#include "Person.h"
#ifndef Doctor_H
#define Doctor_H
// Class for Doctor
class Doctor : public Person {
 public:
  int DoctorID;
  std::string medicationPrescribed;

 public:
  Doctor();
  void dispInfo();
  void setDoctorId(int DoctorID);
  int getDoctorID();
  virtual void diagonose(std::string patientName);
  virtual int medication(std::string patientName);
  ~Doctor();
};

#endif