#include <iostream>

#include "Patient.h"
#ifndef GNWARD_H
#define GNWARD_H
// Class for general ward (GNWard)
class GNWard {
 protected:
  int capacity;
  bool avability;
  int currentPatientNumber;
  static int count;
  int roomNumber;
  Patient* patient;

 public:
  GNWard();
  virtual void dispDescription();
  virtual bool addPatient(Patient patient);
  int getCurrentPatientNumber() { return currentPatientNumber; }
  ~GNWard();
  int getRoomNumber() { return roomNumber; }
  virtual void dispInfo();
};

#endif