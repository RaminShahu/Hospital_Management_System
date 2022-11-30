#include <iostream>
#include "Patient.h"

int main() {
  Patient p1;
  std::cout << p1.getName() << p1.getPhoneNo() << p1.getAdress()
            << p1.getEmail() << p1.getReason() << p1.getRequireCareStatus()
            << p1.getMedicareStatus() << "\n";
  p1.setName("Eva");
  p1.setPhoneNo("0402042332");
  p1.setAdress("Northfield");
  p1.setEmail("raminshahu786@gmail.com");
  p1.setReason("Corona");
  p1.setMedicareStatus(true);
  p1.setRequireCareStaus(true);
  std::cout << p1.getName() << p1.getPhoneNo() << p1.getAdress()
            << p1.getEmail() << p1.getReason() << p1.getRequireCareStatus()
            << p1.getMedicareStatus() << "\n";
  Patient p2("John","0456903987","Parafield","raminshahu@outlook.com","Cough",true,false);
  p2.dispInfo();
}

