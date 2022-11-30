#include "RPInterface.h"

void RPInterface::writeOnFile() {
  int doctorNumber = 0;
  std::string command = "";
  std::ofstream outfile;
  int previousPatient;
  std::fstream prevFile;
  bool exit = false;
  hospital->patient = new Patient(5);
  hospital->numberOfPatient = hospital->numberOfPatient + 1;
  outfile.open("patientData.txt", std::ios::app);
  if (outfile.is_open()) {
    outfile << hospital->numberOfPatient << "\n";
    outfile << "Name: " << hospital->patient->name << "\n";
    outfile << "Phone No: " << hospital->patient->phoneNo << "\n";
    outfile << "Adress: " << hospital->patient->adress << "\n";
    outfile << "Email: " << hospital->patient->email << "\n";
    // outfile << "Reason for visit: " << hospital.patient->reason << "\n";
    if (hospital->patient->mediCareCover == true) {
      outfile << "Medicare Status: Covered throught medicare.\n";
    } else if (hospital->patient->mediCareCover == false) {
      outfile << "Medicare Status: Not Covered throught medicare.\n";
    } else {
    }

    outfile.close();

  } else {
    std::cout << "Not writing on file.\n";
  }

  for (int i = 1; i <= hospital->numberOfDoctors; i++) {
    std::cout << i << "."
              << "\n";
    hospital->Doctors[i - 1].dispInfo();
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
            << hospital->Doctors[doctorNumber - 1].name << "\n";

  } else {
  }
  outfile.close();
  hospital->Doctors[doctorNumber - 1].diagonose(hospital->patient->getName());
  hospital->patient->setReason();

  outfile.open("patientData.txt", std::ios::app);
  if (outfile.is_open()) {
    outfile << "Reason for visit: " << hospital->patient->reason << "\n";

  } else {
  }
  outfile.close();

  bool extraCareStatus;
  extraCareStatus =
      hospital->Doctors[doctorNumber].medication(hospital->patient->getName());

  hospital->patient->requireCare = extraCareStatus;

  if (extraCareStatus == true) {
    for (int i = 1; i <= hospital->numberOfSpDoctors; i++) {
      std::cout << i << "."
                << "\n";
      hospital->SpDoctors[i - 1].dispInfo();
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
              << hospital->SpDoctors[doctorNumber - 1].name << "\n";
    } else {
    }
    outfile.close();
    hospital->SpDoctors[doctorNumber - 1].diagonose(hospital->patient->getName());
    int patientsStayPerid = hospital->SpDoctors[doctorNumber - 1].medication(
        hospital->patient->getName());
    hospital->patient->stayPeriod = patientsStayPerid;
    outfile.open("patientData.txt", std::ios::app);
    if (outfile.is_open()) {
      outfile << "Medication prescribed by specialist doctor: "
              << hospital->SpDoctors[doctorNumber - 1].medicationPrescribed
              << "\n";

      outfile << "Stay Period: " << patientsStayPerid << " days.\n";
      outfile.close();

    } else {
    }
    outfile.close();
    std::cin.ignore();
    hospital->dispWardsInformation(patientsStayPerid);
    bool avaibility = hospital->bookRoom();
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
  delete hospital->patient;
}