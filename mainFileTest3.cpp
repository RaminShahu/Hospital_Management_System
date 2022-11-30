#include <fstream>
#include <iostream>

#include "Hospital.h"
int main() {
  bool exit = false;
  std::string command = "";

  // while (exit == false) {
  std::cout << "           Hi Welcome to Hospital Game Simulator             ";
  Hospital hospital("spDoctors.txt", "Doctors.txt");

  std::cout
      << "Hi You are now a medical receptionist and you have 6 options.\n";

  std::cout << "1. Register a new patient(RP). Type RP to do this.\n";
  std::cout << "2. Deregister a pateint(DP). Type DP to do this.\n";
  std::cout << "3. Check record of current patients. Type CRCP to do this.\n";
  std::cout << "4. Check record of previous patents. Type CRPP to do this.\n";
  std::cout << "5. Update current patient's details. Type UD to do this.\n";
  std::cout << "6. Exit. Type EX to do this.\n";

  while (exit == false) {
    std::cout << "Enter what you want to do: ";
    std::cin >> command;
    if (command == "RP") {
      hospital.patient = new Patient;
      
      // code
    } else if (command == "DP") {
      // code

    } else if (command == "CRCP") {
      // code
    } else if (command == "CRPP") {
      // code
    } else if (command == "EX") {
      exit = true;
      // code
    } else {
      std::cout << "Enter a valid commaand: ";
    }
  }
}
