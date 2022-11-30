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

int gnWard::count = 1;

int index(std::string patientName, std::vector<std::string> lines) {
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

bool nameFound(std::string patientName, std::string nameToFound) {
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
  std::ofstream outfile;
  int previousPatient;
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
                "ALL THE PATIENT                                "
             << "\n";
    prevFile << "\n";
    prevFile << "\n";
    prevFile.close();

  } else {
    std::cout << "Not writing on file.\n";
  }
  outfile.close();

  // while (exit == false) {
  std::cout << "           Hi Welcome to Hospital Game Simulator             ";
  Hospital hospital("spDoctors.txt", "Doctors.txt");

  std::cout
      << "Hi You are now a medical receptionist and you have 6 options.\n";

  std::cout << "1. Register a new patient(RP). Type RP to do this.\n";
  std::cout << "2. Deregister a pateint(DP). Type DP to do this.\n";
  std::cout << "3. Check record of current patients. Type CRCP to do this.\n";
  // std::cout << "4. Check record of previous patents. Type CRPP to do
  // this.\n";
  std::cout << "5. Update current patient's details. Type UD to do this.\n";
  std::cout << "6. Exit. Type EX to do this.\n";

  while (exit == false) {
    std::cout << "Enter what you want to do: ";
    std::getline(std::cin, command);

    if (command == "RP") {
      hospital.patient = new Patient(5);
      hospital.numberOfPatient++;
      outfile.open("patientData.txt", std::ios::app);
      if (outfile.is_open()) {
        outfile << hospital.numberOfPatient << "\n";
        outfile << "Name: " << hospital.patient->name << "\n";
        outfile << "Phone No: " << hospital.patient->phoneNo << "\n";
        outfile << "Adress: " << hospital.patient->adress << "\n";
        outfile << "Email: " << hospital.patient->email << "\n";
        outfile << "Reason for visit: " << hospital.patient->reason << "\n";
        if (hospital.patient->mediCareCover == true) {
          outfile << "Medicare Status: Covered throught medicare.\n";
        } else if (hospital.patient->mediCareCover == false) {
          outfile << "Medicare Status: Not Covered throught medicare.\n";
        } else {
        }

        outfile.close();

      } else {
        std::cout << "Not writing on file.\n";
      }

      for (int i = 1; i <= hospital.numberOfDoctors; i++) {
        std::cout << i << "."
                  << "\n";
        hospital.Doctors[i - 1].dispInfo();
        std::cout << "\n";
      }
      std::cout << "Enter a number between 1 and 5 to select what doctor you "
                   "want for the patient: ";
      std::cin >> doctorNumber;
      while (doctorNumber < 1 && doctorNumber > 5) {
        std::cout << "Please enter a valid input: ";
        std::cout << "Enter a number between 1 and 5 to select what doctor you "
                     "want for the patient: ";
        std::cin >> doctorNumber;
        std::cin.ignore();
      }
      outfile.open("patientData.txt", std::ios::app);
      if (outfile.is_open()) {
        outfile << "Patient treated by doctor: "
                << hospital.Doctors[doctorNumber - 1].name << "\n";

      } else {
      }
      outfile.close();
      hospital.Doctors[doctorNumber - 1].diagonose(hospital.patient->getName());
      hospital.patient->setReason();

      outfile.open("patientData.txt", std::ios::app);
      if (outfile.is_open()) {
        outfile << "Reason for visit: " << hospital.patient->reason << "\n";

      } else {
      }
      outfile.close();

      bool extraCareStatus;
      extraCareStatus = hospital.Doctors[doctorNumber].medication(
          hospital.patient->getName());

      hospital.patient->requireCare = extraCareStatus;

      if (extraCareStatus == true) {
        for (int i = 1; i <= hospital.numberOfSpDoctors; i++) {
          std::cout << i << "."
                    << "\n";
          hospital.SpDoctors[i - 1].dispInfo();
          std::cout << "\n";
        }
        outfile.open("patientData.txt", std::ios::app);
        if (outfile.is_open()) {
          outfile << "Extra Care Status: Patient required extra care"
                  << "\n";
        } else {
        }
        outfile.close();
        std::cout << "Enter a number between 1 and 3 to select what specialist "
                     "doctor you "
                     "want for the patient: ";
        std::cin >> doctorNumber;
        std::cin.ignore();
        while (doctorNumber < 1 || doctorNumber > 3) {
          std::cout << "Please enter a valid input: ";
          std::cout << "Enter a number between 1 and 3 to select what "
                       "specialist doctor you "
                       "want for the patient: ";
          std::cin >> doctorNumber;
          std::cin.ignore();
        }
        outfile.open("patientData.txt", std::ios::app);
        if (outfile.is_open()) {
          outfile << "Treated by specialist doctor: "
                  << hospital.SpDoctors[doctorNumber - 1].name << "\n";
        } else {
        }
        outfile.close();
        hospital.SpDoctors[doctorNumber - 1].diagonose(
            hospital.patient->getName());
        int patientsStayPerid = hospital.SpDoctors[doctorNumber - 1].medication(
            hospital.patient->getName());
        hospital.patient->stayPeriod = patientsStayPerid;
        outfile.open("patientData.txt", std::ios::app);
        if (outfile.is_open()) {
          outfile << "Medication prescribed by specialist doctor: "
                  << hospital.SpDoctors[doctorNumber - 1].medicationPrescribed
                  << "\n";

          outfile << "Stay Period: " << patientsStayPerid << " days.\n";
          outfile.close();

        } else {
        }
        outfile.close();
        std::cin.ignore();
        hospital.dispWardsInformation(patientsStayPerid);
        bool avaibility = hospital.bookRoom();
        if (avaibility == false) {
          std::cout << "The rooms are full in this hospital go to different "
                       "hospital.\n";
          outfile.open("patientData.txt", std::ios::app);
          if (outfile.is_open()) {
            outfile << "Room was not available in the hospital, patient was "
                       "transferrred into another hospital.\n";

            outfile.close();
          } else {
          }
        } else if (avaibility == true) {
          std::cout << "Your room has been succesufully booked.\n";
        }

      } else if (extraCareStatus == false) {
      } else {
      }
      delete hospital.patient;
    }

    // code

    else if (command == "DP") {
      outfile.close();
      hospital.numberOfPatient--;
      hospital.numberOfPreviousPatient++;
      std::fstream inFile;
      inFile.open("patientData.txt", std::ios::in);
      std::fstream writeFile;
      std::string patientName;
      std::cout << "Enter the name of the patient: ";
      getline(std::cin, patientName);
      std::string line;
      std::vector<std::string> lines;
      std::string line1;
      std::vector<std::string> lines2;
      std::string line2;
      std::cout.setstate(std::ios_base::failbit);
      int counter = 0;
      if (inFile.is_open()) {
        for (int i = 0; i < 2; i++) {
          std::getline(inFile, line);
          lines.push_back(line);
        }
        while (std::getline(inFile, line)) {
          lines.push_back(line);
        }
      }
      inFile.close();
      counter = index(patientName, lines);
      if (counter != 0) {
        std::cout.clear();
        std::cout << "Patient succesfully removed.\n";
        writeFile.open("patientData.txt", std::ios::out);

        std::fstream writeFile1;
        std::vector<std::string> lines1;
        if (writeFile.is_open()) {
          for (int i = 0; i < lines.size(); i++) {
            if ((i != counter + 1) && (i != counter + 2) &&
                (i != counter + 3) && (i != counter + 4) &&
                (i != counter + 5) && (i != counter + 6) &&
                (i != counter + 7) && (i != counter + 8) &&
                (i != counter + 9) && (i != counter + 10) &&
                (i != counter + 11) && (i != counter + 12) &&
                (i != counter + 13) && (i != counter - 1) && (i != counter)) {
              writeFile << lines[i] << "\n";
              lines1.push_back(lines[i]);
            } else if (i > 2) {
              lines2.push_back(lines[i]);
            }
          }
        }
        writeFile.close();
        int number = 0;
        int calc = 3;
        for (int i = 0; i < lines1.size(); i++) {
          if (i == calc) {
            number = number + 1;
            std::string str;
            std::stringstream ss;
            ss << number;
            ss >> str;
            lines1[i] = str;
            calc = number * 15 + 3;
          }
        }
        writeFile1.open("patientData.txt", std::ios::out);
        for (int i = 0; i < lines1.size(); i++) {
          writeFile1 << lines1[i] << "\n";
        }
        writeFile1.close();

        prevFile.open("previousData.txt", std::ios::app);
        for (int i = 0; i < lines2.size(); i++) {
          prevFile << lines2[i] << "\n";
        }
        prevFile.close();

        prevFile.open("previousData.txt", std::ios::in);

        std::string line3;
        std::vector<std::string> lines3;

        for (int i = 0; i < 2; i++) {
          std::getline(prevFile, line3);
          lines3.push_back(line3);
        }
        while (std::getline(prevFile, line3)) {
          lines3.push_back(line3);
        }
        prevFile.close();
        int number1 = 0;
        int calc1 = 3;
        for (int i = 0; i < lines3.size(); i++) {
          if (i == calc1) {
            number1 = number1 + 1;
            std::string str1;
            std::stringstream ss1;
            ss1 << number1;
            ss1 >> str1;
            lines3[i] = str1;
            calc1 = number1 * 15 + 3;
          }
        }

        prevFile.open("previousData.txt", std::ios::out);
        for (int i = 0; i < lines3.size(); i++) {
          prevFile << lines3[i] << "\n";
        }
        prevFile.close();
      } else {
        std::cout.flush();
        std::cout.clear();
        std::cout << "Patient Not Found.\n";
      }

    }

    else if (command == "CRCP") {
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

      searchFile.open("patientData.txt", std::ios::in);
      while (std::getline(searchFile, searchName)) {
        if (nameFound(searchName, nameOfPatient)) {
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
          break;
        } else {
          std::cout << "Patient not found.\n";
        }
      }
    } else if (command == "CRPP") {
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
      searchFile.open("previousData.txt", std::ios::in);
      while (std::getline(searchFile, searchName)) {
        if (nameFound(searchName, nameOfPatient)) {
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

      // code
    } else if (command == "EX") {
      exit = true;
      // code
    } else if (command == "SR") {
      std::cout << "Enter the room number you want to search: ";
      int roomNumber;
      std::cin >> roomNumber;
      std::cin.ignore();
      for (int i = 0; i < hospital.numberOfGeneralWard; i++) {
        int number = hospital.generalWard[i].getRoomNumber();
        if (number == roomNumber) {
          hospital.generalWard[i].dispInfo();
        }
      }
    } else {
      std::cout << "Enter a valid commaand: ";
    }
  }
}
