
#include "Patient.h"

#include <string.h>

#include <iostream>

Patient::Patient() {
  name = "";
  phoneNo = " ";
  adress = " ";
  email = " ";
  reason = " ";
  mediCareCover = true;
  requireCare = true;
  stayPeriod = 0;
}

Patient::Patient(int num) : Person() {
  std::cout << "Enter the name of the patient: ";
  std::getline(std::cin, name);
  std::cout << "Enter the phone number of the patient: ";
  std::getline(std::cin, phoneNo);
  std::cout << "Enter the adress of the patient: ";
  std::getline(std::cin, adress);
  std::cout << "Enter the email of the patient: ";
  std::getline(std::cin, email);
  std::cout << "Enter the medicare status of the patient(YES OR NO): ";
  std::string medicareAns;
  std::getline(std::cin, medicareAns);
  if (medicareAns == "YES") {
    mediCareCover = true;
  } else if (medicareAns == "NO") {
    mediCareCover = false;
  } else {
  }
  while (medicareAns != "YES" && medicareAns != "NO") {
    std::cout << "Enter the medicare status in YES or NO: ";
    std::cin >> medicareAns;
    if (medicareAns == "YES") {
      mediCareCover = true;
    } else if (medicareAns == "NO") {
      mediCareCover = false;
    } else {
    }
  }
}
Patient::Patient(std::string name, std::string phoneNo, std::string adress,
                 std::string email, std::string reason, bool mediCareCover,
                 bool requireCare)
    : Person(name, phoneNo, adress, email) {
  this->reason = reason;
  this->mediCareCover = mediCareCover;
  this->requireCare = requireCare;
}
void Patient::setReason() {
  std::cin.ignore();
  std::getline(std::cin, this->reason);
}

void Patient::setMedicareStatus(bool mediCareCover) {
  this->mediCareCover = mediCareCover;
}

void Patient::setRequireCareStaus(bool requireCare) {
  this->requireCare = requireCare;
}

std::string Patient::getReason() { return this->reason; }

bool Patient::getMedicareStatus() { return this->mediCareCover; }
bool Patient::getRequireCareStatus() { return this->requireCare; }
void Patient::dispInfo() {
  std::cout << "Name: " << name << "\n";
  std::cout << "PhoneNo: " << phoneNo << "\n";
  std::cout << "Adress: " << adress << "\n";
  std::cout << "Email: " << email << "\n";
  std::cout << "Reason: " << reason << "\n";
  if (this->mediCareCover == true) {
    std::cout << "Covered through medicare.\n";
  } else {
    std::cout << "Not covered throught medicare.\n";
  }
  if (this->requireCare == true) {
    std::cout << "The pateint had a specalist doctor for visit and required "
                 "rest in the hospital.\n";
  } else {
    std::cout << "The patient's case was not severe and patient was treated by "
                 "regular doctor.\n";
  }
}

Patient::~Patient() {}