#include <string.h>

#include <fstream>
#include <iostream>

#include "Doctor.h"
#include "Hospital.h"
using namespace std;
int main() {
  bool exit = false;
  int doctorNumber = 0;
  std::string command = "";
  std::ofstream outfile;
  outfile.open("patientData.txt", std::ios::out);
  if (outfile.is_open()) {
    outfile << "                                  This File Holds THE DATA OF "
               "ALL THE PATIENT                                "
            << "\n";
    outfile << "\n";
    outfile << "\n";
    outfile.close();

  } else {
    std::cout << "Not writing on file.\n";
  }

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
          outfile << "\n";
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

      hospital.Doctors[doctorNumber - 1].diagonose(hospital.patient->getName());
      hospital.patient->setReason();
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
        hospital.SpDoctors[doctorNumber - 1].diagonose(
            hospital.patient->getName());
        int patientsStayPerid = hospital.SpDoctors[doctorNumber - 1].medication(
            hospital.patient->getName());
        hospital.patient->stayPeriod = patientsStayPerid;
        std::cin.ignore();
        hospital.dispWardsInformation(patientsStayPerid);
        bool avaibility = hospital.bookRoom();
        if (avaibility == false) {
          std::cout << "The rooms are full in this hospital go to different "
                       "hospital.\n";
        } else if (avaibility == true) {
          std::cout << "Your room has been succesufully booked.\n";
        }
      }

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
