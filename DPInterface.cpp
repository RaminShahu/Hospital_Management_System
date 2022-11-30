#include "DPInterface.h"

#include <string.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
// Interface for deregistering patient 
void DPInterface::writeOnFile() {

  std::fstream prevFile;
  hospital->numberOfPatient--;
  hospital->numberOfPreviousPatient++;
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
  // Getting data from file into vector
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
  counter = hospital->index(patientName, lines);
  if (counter != 0) {
    std::cout.clear();
    std::cout << "Patient succesfully removed.\n";
    writeFile.open("patientData.txt", std::ios::out);

    std::fstream writeFile1;
    std::vector<std::string> lines1;
    if (writeFile.is_open()) {
      // Getting lines into vector which asre not meant to be removed one patientData.txt and get stored to previousData.txt
      for (int i = 0; i < lines.size(); i++) {
        if ((i != counter + 1) && (i != counter + 2) && (i != counter + 3) &&
            (i != counter + 4) && (i != counter + 5) && (i != counter + 6) &&
            (i != counter + 7) && (i != counter + 8) && (i != counter + 9) &&
            (i != counter + 10) && (i != counter + 11) && (i != counter + 12) &&
            (i != counter - 1) && (i != counter)) {
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
        // Changing int to string
        number = number + 1;
        std::string str;
        std::stringstream ss;
        ss << number;
        ss >> str;
        lines1[i] = str;
        calc = number * 14 + 3;
      }
    }
    writeFile1.open("patientData.txt", std::ios::out);
    for (int i = 0; i < lines1.size(); i++) {
      writeFile1 << lines1[i] << "\n";
    }
    writeFile1.close();
// Vectors operartion for manipulating data
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
        calc1 = number1 * 14 + 3;
      }
    }
// Writing data into prevFile.txt
    prevFile.open("previousData.txt", std::ios::out);
    for (int i = 0; i < lines3.size(); i++) {
      prevFile << lines3[i] << "\n";
    }
    prevFile.close();
  } else {
    // Patient not found
    std::cout.flush();
    std::cout.clear();
    std::cout << "Patient Not Found.\n";
  }
}

