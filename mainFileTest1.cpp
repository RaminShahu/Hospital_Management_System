#include <fstream>
#include <iostream>

#include "Hospital.h"

int main() {
  bool exit = false;

  // while (exit == false) {
  std::cout << "           Hi Welcome to Hospital Game Simulator             ";
  Hospital("Doctors.txt", "spDoctors.txt");
}
//}