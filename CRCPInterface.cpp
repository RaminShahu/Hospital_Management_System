#include "CRCPInterface.h"

#include <iostream>
// Interface for the searhing currently registered patient
void CRCPInterface::writeOnFile() {
  std::cout.clear();
  // Creating variable for storing lines of patient from txt file
  std::string nameOfPatient;
  std::cout << "Enter the name of the patient: ";
  std::getline(std::cin, nameOfPatient);
  std::fstream searchFile;
  std::string searchName;
  std::string phoneNo;
  std::string adress;
  std::string email;
  std::string medicareStatus;
  std::string doctor;
  std::string reason;
  std::string medication;
  std::string extraCareStatus;
  std::string specialistDoctor;
  std::string medicationSp;
  std::string stayPeriod;
  std::string roomType;
  std::string roomType1;
  bool found = false;
  searchFile.open("patientData.txt", std::ios::in);
  while (std::getline(searchFile, searchName)) {
    found = hospital->nameFound(searchName, nameOfPatient);
    if (found == true) {
      std::getline(searchFile, phoneNo);
      std::getline(searchFile, adress);
      std::getline(searchFile, email);
      std::getline(searchFile, medicareStatus);
      std::getline(searchFile, doctor);
      std::getline(searchFile, reason);
      std::getline(searchFile, medication);
      std::getline(searchFile, extraCareStatus);
      std::getline(searchFile, specialistDoctor);
      std::getline(searchFile, medicationSp);
      std::getline(searchFile, stayPeriod);
      std::getline(searchFile, roomType);
      std::getline(searchFile, roomType1);
      // Prints on terminal if patient found
      std::cout << searchName << "\n";
      std::cout << phoneNo << "\n";
      std::cout << adress << "\n";
      std::cout << email << "\n";
      std::cout << medicareStatus << "\n";
      std::cout << doctor << "\n";
      std::cout << reason << "\n";
      std::cout << medication << "\n";
      std::cout << extraCareStatus << "\n";
      std::cout << specialistDoctor << "\n";
      std::cout << medicationSp << "\n";
      std::cout << stayPeriod << "\n";
      std::cout << roomType << "\n";
      std::cout << roomType1 << "\n";
      break;
    }
  }
  searchFile.close();
  if (found == false) {
    // Patient not found
    std::cout << "Patient Not Found.\n";
  }
}