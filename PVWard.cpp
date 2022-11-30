#include "PVWard.h"

#include <iostream>

PVWard::PVWard() {
  this->capacity = 1;
  this->patient = new Patient;
  this->avability = true;
  this->currentPatientNumber = 0;
  this->roomNumber = PVWard::count1++;
}

void PVWard::dispDescription() {
  std::cout << "Room type: Private Ward\n";
  std::cout << "Room capacity: 1\n";
  std::cout << "Price: 5000(Without medicare)\n";
  std::cout << "Price: 3000(With medicare)\n";
}
bool PVWard::addPatient(Patient patient1) {
  if (currentPatientNumber != 1) {
    *patient = patient1;
    currentPatientNumber++;
    avability = true;
    return true;
  } else {
    return false;
  }
}

void PVWard::dispInfo() {
  std::cout << "Capacity: " << capacity << "\n";
  std::cout << "Current Number of patient: " << currentPatientNumber << "\n";
  std::cout << "Room Number: " << roomNumber << "\n";
  std::cout << "\n";
  if (currentPatientNumber == 0) {
    std::cout << "No patient in this room.\n";
  } else {
    patient->dispInfo();
    std::cout << "\n";
  }
}

PVWard::~PVWard() {}