#include <fstream>
#include <iostream>

#include "Doctor.h"
#include "GNWard.h"
#include "Nurse.h"
#include "PVWard.h"
#include "Patient.h"
#include "specialistDoctor.h"
#ifndef Hospital_H
#define Hospital_H
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
// Class for hospital
class Hospital {
 public:
  std::string hospitalName;
  int numberOfDoctors;

  int numberOfSpDoctors;
  Doctor* Doctors;
  Doctor* SpDoctors;

  int numberOfGeneralWard;
  int numberOfPrivateWard;
  GNWard* generalWard;
  GNWard* privateWard;
  Patient* patient;
  int numberOfPatient;
  int numberOfPreviousPatient;

 public:
  Hospital(std::string specialistDoctorFilename, std::string doctorFilename);
  Hospital() {}
  void dispWardsInformation(int stayPeriod);
  bool bookRoom();
  int index(std::string patientName, std::vector<std::string> lines);
  bool nameFound(std::string patientName, std::string nameToFound);
  ~Hospital();
};

#endif