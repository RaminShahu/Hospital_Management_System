#include <string.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Doctor.h"
#include "Hospital.h"
using namespace std;
#include <vector>

#include "CRCPInterface.h"
#include "DPInterface.h"
#include "Interface.h"
#include "Menu.h"
#include "RPInterface.h"
int gnWard::count = 1;
int pvWard::count1 = 1;
bool nameFound1(std::string patientName, std::string nameToFound) {
  int z = 0;
  int num1 = nameToFound.length();
  int num2 = patientName.length();
  int number = num2 - num1;

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

int main() {
  bool exit = false;
  int doctorNumber = 0;
  std::string command = "";
  int previousPatient;
  std::fstream outfile;
  std::fstream prevFile;

  std::cout << "           Hi Welcome to Hospital Game Simulator             ";
  Hospital hospital("spDoctors.txt", "Doctors.txt");
  Hospital* hospital1 = &hospital;

  Menu main(hospital1);

  main.writeOnFile1();

  main.menu();

  while (exit == false) {
    std::cout << "Enter what you want to do: ";
    std::getline(std::cin, command);

    if (command == "RP") {
      hospital.patient = new Patient(5);
      hospital.numberOfPatient++;
      RPInterface rpInterface(hospital1);
      rpInterface.writeOnFile();

    }

    else if (command == "DP") {
      outfile.close();
      hospital.numberOfPatient--;
      hospital.numberOfPreviousPatient++;
      DPInterface dpInterface(hospital1);
      dpInterface.writeOnFile();

    }

    else if (command == "CRCP") {
      CRCPInterface crcpInterface(hospital1);
      crcpInterface.writeOnFile();

      /*  std::cout.clear();
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
        int counter4 = 0;
        searchFile.open("patientData.txt", std::ios::in);
        while (std::getline(searchFile, searchName)) {
          counter4++;
          if (nameFound1(searchName, nameOfPatient)) {
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
          }
        }
        if (counter4 == (15 * (hospital.numberOfPatient)) + 3 || counter4 == 0)
        { std::cout << "Patient Not Found.\n";
        }*/
      // code
    } else if (command == "CRPP") {
      std::cout.clear();
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
      int counter5 = 0;
      searchFile.open("previousData.txt", std::ios::in);
      while (std::getline(searchFile, searchName)) {
        counter5++;
        if (nameFound1(searchName, nameOfPatient)) {
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
        }
      }
      if (counter5 == (15 * (hospital.numberOfPreviousPatient)) + 3 ||
          counter5 == 0) {
        std::cout << "Patient Not Found.\n";
      }
      // code
    } else if (command == "EX") {
      exit = true;
      // code
    } else if (command == "SR") {
      std::string wardType;
      std::cout << "Enter what type of ward you want to search(PW OR GW): ";
      getline(std::cin, wardType);
      if (wardType == "GW") {
        std::cout << "Enter the room number you want to search: ";
        int roomNumber;
        std::cin >> roomNumber;
        std::cin.ignore();
        for (int i = 0; i < hospital.numberOfGeneralWard; i++) {
          int number = hospital.generalWard[i].getRoomNumber();
          if (roomNumber == number) {
            hospital.generalWard[i].dispInfo();
          }
        }
      } else if (wardType == "PW") {
        int roomNumber1;
        std::cout << "Enter the room number you want to search for: ";
        std::cin >> roomNumber1;
        std::cin.ignore();
        for (int i = 0; i < hospital.numberOfPrivateWard; i++) {
          int number1 = hospital.privateWard[i].getRoomNumber();
          if (roomNumber1 == number1) {
            hospital.privateWard[i].dispInfo();
          }
        }
      } else {
        std::cout << "Enter a valid room type.\n";
      }
    } else {
      std::cout << "Enter a valid commaand: ";
    }
  }
}
