#include "Doctor.h"

#include <fstream>
#include <iostream>
// Default constructor for Doctor class
Doctor::Doctor() : Person() { this->DoctorID = 0; }
// Function for displaying doctor info
void Doctor::dispInfo() {
  std::cout << "Name: " << this->name << "\n";
  std::cout << "Phone Number: " << phoneNo << "\n";
  std::cout << "Adress: " << adress << "\n";
  std::cout << "E-mail: " << email << "\n";
  std::cout << "DoctorID: " << DoctorID << "\n";
}
// Function for setting attributes for objects of Doctor class
void Doctor::setDoctorId(int DoctorID) { this->DoctorID = DoctorID; }

int Doctor::getDoctorID() { return this->DoctorID; }
// Doctor function to diagonose the patient
void Doctor::diagonose(std::string patientName) {
  std::cout << "Hi my name is " << name
            << ". I will be treating you today. Pleaset tell me your reason "
               "of visit today "
            << patientName << "."
            << "\n";
}
// Doctor function to give medication the patient
int Doctor::medication(std::string patientName) {
  bool extraCareStatus;
  std::string extracare = "";

  std::cout << "After reviewing your condition " << patientName
            << ", I would like to prescribe you some medication.\n";

  std::cout << "Presecribe medication to the patient.\n";
  std::getline(std::cin, this->medicationPrescribed);
  std::ofstream outfile;
  outfile.open("patientData.txt", std::ios::app);
  if (outfile.is_open()) {
    outfile << "Medication prescribed by doctor: " << medicationPrescribed
            << "\n";
  } else {
  }

  while (extracare != "YES" && extracare != "NO") {
    std::cout << "Enter the extra care required status in YES or NO: ";
    std::getline(std::cin, extracare);
    if (extracare == "YES") {
      extraCareStatus = true;

      std::cout << "You have to go to the specialist doctor.\n";

    } else if (extracare == "NO") {
      extraCareStatus = false;
      std::cout << "You are free to leave now " << patientName
                << " just follow the prescribed medicine. I hope you will be "
                   "fine thanks for coming here.\n ";
      if (outfile.is_open()) {
        outfile << "Extra Care Status: Patient did not require extra care.\n";
        outfile << "Treated by specialist doctor: NONE.\n";
        outfile << "Medication prescribed by specialist doctor: NONE.\n";
        outfile << "Stay Period: 0\n";
        outfile << "Room Type: NONE\n";
      } else {
        std::cout << "Not writing\n";
      }
    } else {
    }
  }
  return extraCareStatus;
}
// Default destructor for Doctor
Doctor::~Doctor() {

}