#include "Menu.h"

void Menu::displayMenu() {
  std::cout
      << "Hi You are now a medical receptionist and you have 5 options.\n";

  std::cout << "1. Register a new patient(RP). Type RP to do this.\n";
  std::cout << "2. Deregister a pateint(DP). Type DP to do this.\n";
  std::cout << "3. Check record of current patients. Type CRCP to do this.\n";
  std::cout << "4. Check record of previous patients. Type CRPP to do this.\n";
  std::cout << "5. Exit. Type EX to do this.\n";
}

void Menu::writeOnFile() {
  std::fstream outfile;
  std::fstream prevFile;
  outfile.open("patientData.txt", std::ios::out);
  if (outfile.is_open()) {
    outfile << "                                  This File Holds THE DATA OF "
               "ALL THE PATIENT                                "
            << "\n";
    outfile << "\n";
    outfile << "\n";

    prevFile.open("previousData.txt", std::ios::out);
    prevFile << "                                  This File Holds THE DATA OF "
                "ALL THE PREVIOUS PATIENT                                "
             << "\n";
    prevFile << "\n";
    prevFile << "\n";
    prevFile.close();

  } else {
    std::cout << "Not writing on file.\n";
  }
  outfile.close();
}