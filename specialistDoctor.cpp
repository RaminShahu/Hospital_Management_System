#include "specialistDoctor.h"

#include <iostream>

specialistDoctor::specialistDoctor() : Doctor() {}
void specialistDoctor::dispInfo() {
  std::cout << "Name: " << this->name << "\n";
  std::cout << "Phone Number: " << this->phoneNo << "\n";
  std::cout << "Adress: " << this->adress << "\n";
  std::cout << "E-mail: " << this->email << "\n";
  std::cout << "DoctorID: " << this->DoctorID << "\n";
}

void specialistDoctor::diagonose(std::string patientName) {
  std::cout << "Hi " << patientName << " my name is " << name
            << ". I am your specilaist doctor today. I have revied your "
               "medical condition and I will be treating you today.\n";
}

int specialistDoctor::medication(std::string patientName) {
  std::cout << "I would like to prescribe you some medication " << patientName
            << " and care in for few days in the hospital.\n";

  std::cout << "Presecribe medication to the patient.\n";
  std::getline(std::cin, this->medicationPrescribed);
  int numberOfDays;
  std::cout << "Enter the number of days you would like the patient to stay in "
               "the hospital.\n";
  std::cin >> numberOfDays;
  return numberOfDays;
}

specialistDoctor::~specialistDoctor() {}
