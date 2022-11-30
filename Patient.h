#ifndef Patient_H
#define Patient_H

#include <iostream>

#include "Person.h"

using namespace std;

class Patient : public Person {
 public:
  std::string reason;
  bool mediCareCover;
  bool requireCare;
  int stayPeriod;

 public:
  Patient();
  Patient(std::string name, std::string phoneNo, std::string adress,
          std::string email, std::string reason, bool mediCareCover,
          bool requireCare);
  Patient(int num);
  void setReason();
  void setMedicareStatus(bool mediCareCover);
  void setRequireCareStaus(bool requireCare);
  std::string getReason();
  bool getMedicareStatus();
  bool getRequireCareStatus();
  void dispInfo();
  ~Patient();
};
#endif