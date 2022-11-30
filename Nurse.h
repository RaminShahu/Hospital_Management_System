#ifndef Nurse_H
#define Nurse_H
#include <iostream>

#include "Person.h"

class Nurse : public Person {
  int nurseID;

 public:
  Nurse();
  Nurse(std::string name, std::string phoneNo, std::string adress,
        std::string email, int nurseID);
  void helpPatients(std::string patientName, std::string roomNo);
  void dispInfo();
  void setNurseId(int id);
};

#endif