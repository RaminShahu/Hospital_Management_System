#include "GNWard.h"

#include <iostream>
// Default constructor for GNWard
GNWard::GNWard() {
  this->capacity = 5;
  this->patient = new Patient[capacity];
  this->avability = true;
  this->currentPatientNumber = 0;
  this->roomNumber = GNWard::count++;
}
// Function for displaying GNWard information
void GNWard::dispDescription() {
  std::cout << "Room type: General Ward\n";
  std::cout << "Room capacity: 5\n";
  std::cout << "Price: 2000(Without medicare)\n";
  std::cout << "Price: 1000(With medicare)\n";
}
// Function for adding patient into the general ward
bool GNWard::addPatient(Patient patient) {
  if (currentPatientNumber <= capacity) {
    this->patient[currentPatientNumber] = patient;
    currentPatientNumber++;
    return true;
  } else if (currentPatientNumber > capacity) {
    this->avability = false;
    return false;
  }
  return false;
}
// Default deconstructor for general ward
GNWard::~GNWard() {}
// Function for displaying information for general ward
void GNWard::dispInfo() {
  std::cout << "Capacity: " << capacity << "\n";
  std::cout << "Current Number of patient: " << currentPatientNumber << "\n";
  std::cout << "Room Number: " << roomNumber << "\n";
  if (currentPatientNumber == 0) {
    std::cout << "No patient in this room.\n";
  }
  for (int i = 0; i < currentPatientNumber; i++) {
    patient[i].dispInfo();
    std::cout << "\n";
  }
}