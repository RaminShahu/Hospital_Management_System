

#include "Hospital.h"

#include <fstream>
#include <iostream>
#include <string>
// Default constructor for Hospital
Hospital::Hospital(std::string specialistDoctorFilename,
                   std::string doctorFilename) {
  this->numberOfPatient = 0;
  this->numberOfPreviousPatient = 0;
  std::cout << "Name your hospital: ";
  std::getline(std::cin, hospitalName);
  this->numberOfDoctors = 0;
  // Select the number of doctors you want in hospital
  std::cout << "You can have 5 to 10 doctors.\n";
  std::cout << "Enter the number of doctors you would like to have in your "
               "hospital: ";
  std::cin >> this->numberOfDoctors;
  std::cin.ignore();

  while (this->numberOfDoctors < 5 || this->numberOfDoctors > 10) {
    std::cout << "Please enter a valid input.\n";
    std::cout << "Enter the number of doctors you would like to have in your "
                 "hospital: ";
    std::cin >> this->numberOfDoctors;
    std::cin.ignore();
  }
  this->Doctors = new Doctor[numberOfDoctors + 1];
  std::ifstream doctorFile(doctorFilename, std::ios::in);
  for (int i = 0; i < numberOfDoctors; i++) {
     // Reading from text file to set attributes of  doctor
    std::string name;
    std::string phoneNo;
    std::string adress;
    std::string email;
    std::string DoctorID;
    getline(doctorFile, name);
    getline(doctorFile, phoneNo);
    getline(doctorFile, adress);
    getline(doctorFile, email);
    getline(doctorFile, DoctorID);
    Doctors[i].setName(name);
    Doctors[i].setPhoneNo(phoneNo);
    Doctors[i].setAdress(adress);
    Doctors[i].setEmail(email);
    Doctors[i].setDoctorId(stoi(DoctorID));
  }
  std::cout << "                      The following " << numberOfDoctors
            << " doctors are in your hospital: \n";

  for (int i = 0; i < numberOfDoctors; i++) {
    Doctors[i].dispInfo();
  }
// Select the specialist doctor
  std::cout << "You can have 1 to 3 specialist doctors in your hospital .\n";
  std::cout << "Enter the number of specialist doctors you would like to have "
               "in your "
               "hospital: ";
  std::cin >> this->numberOfSpDoctors;
  std::cin.ignore();
  while (this->numberOfSpDoctors < 1 || this->numberOfSpDoctors > 3) {
    std::cout << "Please enter a valid input.\n";
    std::cout << "Enter the number of specalist doctors you would like to have "
                 "in your "
                 "hospital: ";
    std::cin >> this->numberOfSpDoctors;
    std::cin.ignore();
  }
  this->SpDoctors = new specialistDoctor[numberOfSpDoctors];
  std::ifstream specialistDoctorFile(specialistDoctorFilename, std::ios::in);
  for (int i = 0; i < numberOfSpDoctors; i++) {
    // Reading from text file to set attributes of specialist doctor
    std::string name;
    std::string phoneNo;
    std::string adress;
    std::string email;
    std::string DoctorID;
    getline(specialistDoctorFile, name);
    getline(specialistDoctorFile, phoneNo);
    getline(specialistDoctorFile, adress);
    getline(specialistDoctorFile, email);
    getline(specialistDoctorFile, DoctorID);
    SpDoctors[i].setName(name);
    SpDoctors[i].setPhoneNo(phoneNo);
    SpDoctors[i].setAdress(adress);
    SpDoctors[i].setEmail(email);
    SpDoctors[i].setDoctorId(stoi(DoctorID));
  }

  std::cout << "                      The following " << numberOfDoctors
            << " specialist doctors are in your hospital: \n";

  for (int i = 0; i < numberOfSpDoctors; i++) {
    SpDoctors[i].dispInfo();
  }
// Select the general ward in your hospital
  std::cout << "You can have 1 to 5 general wards each one of them can hold "
               "upto 5 patients at one time.\n";
  std::cout << "Enter the number of general wards you would like to have in "
               "your hospital: ";
  std::cin >> this->numberOfGeneralWard;
  std::cin.ignore();
  while (this->numberOfGeneralWard < 1 || this->numberOfGeneralWard > 5) {
    std::cout << "Please enter a valid input.\n";
    std::cout << "Enter the number of general wards you would like to have in "
                 "your hospital: ";
    std::cin >> this->numberOfGeneralWard;
    std::cin.ignore();
  }
  this->generalWard = new GNWard[numberOfGeneralWard];
  std::cout << "You can have upto " << numberOfGeneralWard * 5
            << " patients in your general ward.\n";
  // Select Private Ward in your hospital
  std::cout << "You can have 1 to 5 private wards each one of them can hold "
               "upto 1 patients at one time.\n";
  std::cout << "Enter the number of private wards you would like to have in "
               "your hospital: ";
  std::cin >> this->numberOfPrivateWard;
  std::cin.ignore();
  while (this->numberOfPrivateWard < 1 || this->numberOfPrivateWard > 5) {
    std::cout << "Please enter a valid input.\n";
    std::cout << "Enter the number of general wards you would like to have in "
                 "your hospital: ";
    std::cin >> this->numberOfPrivateWard;
    std::cin.ignore();
  }
  this->privateWard = new PVWard[numberOfPrivateWard];

  std::cout << "You have " << numberOfPrivateWard
            << " private wards in your hospital each one of them can hold one "
               "patient at a time\n";

  std::cout << "Your hospital is now created with " << numberOfDoctors
            << "doctors, " << numberOfSpDoctors << " specialist doctors, "
            << numberOfGeneralWard << " general wards, and  "
            << numberOfPrivateWard << " private wards.\n";
};
// Function for displaying informaton of wards in the hospital
void Hospital::dispWardsInformation(int stayPeriod) {
  std::cout << "As you have to stay at the hospital for " << stayPeriod
            << " days. What kind of rooom would you like?\n";
  std::cout << "We have two kind of wards where you can stay.\n";
  generalWard->dispDescription();
  privateWard->dispDescription();
}
// Function for booking room in the hospital
bool Hospital::bookRoom() {
  std::string roomType;
  std::cout << "What kind of room would you like to book " << patient->getName()
            << "?\n";
  std::cout << "Press "
            << "PW"
            << " for private room and "
            << "GW"
            << " for general ward.\n";

  std::getline(std::cin, roomType);

  while (roomType != "PW" && roomType != "GW") {
    std::cout << "Please enter your input in PW for private ward and GW for "
                 "general ward.\n";

    std::getline(std::cin, roomType);
  }
// Condtion if the patient wants the private ward
  if (roomType == "PW") {
    int counter = 0;
    while (counter < numberOfPrivateWard) {
      bool avaibility = privateWard[counter].addPatient(*patient);
      if (avaibility == true) {
        std::ofstream outfile;
        outfile.open("patientData.txt", std::ios::app);
        if (outfile.is_open()) {
          outfile << "Room Type: Private Ward"
                  << "\n";
        } else {
        }
        outfile.close();
        return true;
      } else if (avaibility == false) {
        counter++;
      }
    }
    return false;

  }
  // Condition for if the patient wants the general ward
   else if (roomType == "GW") {
    int counter = 0;
    while (counter < numberOfGeneralWard) {
      
      if (generalWard[counter].addPatient(*patient) == true) {
        std::ofstream outfile;
        outfile.open("patientData.txt", std::ios::app);
        if (outfile.is_open()) {
          outfile << "Room Type: General Ward"
                  << "\n";
        } else {
        }
        outfile.close();
        return true;
      } else if (generalWard[counter].addPatient((*patient)) == false) {
        counter++;
      }
    }
    return false;
  }
  return false;
}
// Function for finding the line in txt where the name i
int Hospital::index(std::string patientName, std::vector<std::string> lines) {
  int z = 0;
  int num;
  int num2 = patientName.length();
  int number;
  std::string line;
  for (int i = 0; i < lines.size(); i++) {
    line = lines[i];
    num = line.length();

    number = (num - num2);
    std::cout << line << "\n";
    if (number > 0) {
      for (int j = 0; j <= number; j++) {
        z = 0;
        while ((z < num2) && (line[j + z] == patientName[z])) {
          z++;
          if (z == num2) {
            return i;
          }
        }
      }
    }
  }
  return 0;
}
// Funcition for finding name from vecotr which has txt file lines
bool Hospital::nameFound(std::string patientName, std::string nameToFound) {
  int z = 0;
  int num1 = nameToFound.length();
  int num2 = patientName.length();
  int number = num2 - num1;
  if (number > 0) {
    for (int j = 0; j <= number; j++) {
      z = 0;
      while ((z < num1) && (patientName[j + z] == nameToFound[z])) {
        z++;
        if (z == num1) {
          return true;
        }
      }
    }
    return false;
  }
  return false;
}

// Default constructor for Hospital
Hospital::~Hospital() {
 // delete[] Doctors;
 // delete[] SpDoctors;
 // delete[] generalWard;
//  delete[] privateWard;
}