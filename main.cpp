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
#include "CRPPInterface.h"
#include "DPInterface.h"
#include "GNWard.h"
#include "Interface.h"
#include "Menu.h"
#include "PVWard.h"
#include "RPInterface.h"

int GNWard::count = 1;
int PVWard::count1 = 1;

int main() {
  // Defining the variable
  bool exit = false;
  int doctorNumber = 0;
  std::string command = "";
  std::ofstream outfile;
  int previousPatient;
  std::fstream prevFile;
  // Creating Hospital
  std::cout << "                                                   Hi Welcome "
               "to Hospital Game Simulator             \n";
  Hospital hospital("spDoctors.txt", "Doctors.txt");
  Hospital* hospital1 = &hospital;

  Menu main(hospital1);
  main.writeOnFile();

  while (exit == false) {
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    main.displayMenu();
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Enter what you want to do: ";
    std::getline(std::cin, command);

    if (command == "RP") {
      // Using interface for Register Patient
      RPInterface rpInterface(hospital1);
      rpInterface.writeOnFile();
    }
    // code
    else if (command == "DP") {
      // Using interface for Deregister patient
      DPInterface dpInterface(hospital1);
      dpInterface.writeOnFile();
    } else if (command == "CRCP") {
      // Using interface for checking record of current patient
      CRCPInterface crcpInterface(hospital1);
      crcpInterface.writeOnFile();
      // code
    } else if (command == "CRPP") {
      // Using interface for checking record of previous patient
      CRPPInterface crppInterface(hospital1);
      crppInterface.writeOnFile();
      // code
    } else if (command == "EX") {
      // Program for exit the game
      exit = true;
      delete[] hospital.patient;
      delete[] hospital.Doctors;
      delete[] hospital.SpDoctors;
      delete[] hospital.generalWard;
      delete[] hospital.privateWard;
      std::cout << "The system is ended.\n";
      return 0;
      // code
    } else if (command == "SR") {
      std::string wardType;
      std::cout << "Enter what type of ward you want to search(PW OR GW): ";
      getline(std::cin, wardType);
      if (wardType == "GW") {
        // Searching room if the receptionist want to search general ward.
        std::cout << "Enter the room number you want to search: ";
        int roomNumber;
        std::cin >> roomNumber;
        std::cin.ignore();
        if (roomNumber > hospital.numberOfGeneralWard) {
          std::cout << "Your hospital does not have that many room.\n";
        }
        for (int i = 0; i < hospital.numberOfGeneralWard; i++) {
          int number = hospital.generalWard[i].getRoomNumber();
          if (roomNumber == number) {
            hospital.generalWard[i].dispInfo();
          }
        }
      } else if (wardType == "PW") {
        // Searching room if the receptionist want to search private ward.
        int roomNumber1;
        std::cout << "Enter the room number you want to search for: ";
        std::cin >> roomNumber1;
        std::cin.ignore();
        if (roomNumber1 > hospital.numberOfPrivateWard) {
          std::cout << "Your hospital does not have that many room.\n";
        }
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
      std::cout << "Enter a valid commaand\n";
    }
  }
}