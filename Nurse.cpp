#include "Nurse.h"

#include <iostream>

#include "timer.h"
Nurse::Nurse() : Person() { this->nurseID = 00000; }
Nurse::Nurse(std::string name, std::string phoneNo, std::string adress,
             std::string email, int nurseID)
    : Person(name, phoneNo, adress, email) {
  this->nurseID = nurseID;
}
void Nurse::helpPatients(std::string patientName, std::string roomNo) {
  std::cout << "Going to room No." << roomNo << "\n";
  timer(1);
  std::cout << "Please take this medicine"
            << " " << patientName << "\n";
  std::cout << "Get Well Soon!";
}
void Nurse::setNurseId(int id) { this->nurseID = id; }

void Nurse::dispInfo() {
  std::cout << "Name: " << name << "\n";
  std::cout << "PhoneNo: " << phoneNo << "\n";
  std::cout << "Adress: " << adress << "\n";
  std::cout << "Email: " << email << "\n";
  std::cout << "NurseID: " << nurseID << "\n";
}