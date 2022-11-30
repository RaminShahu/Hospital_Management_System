
#include <string.h>

#include <fstream>
#include <iostream>

int main() {
  std::ifstream doctorFile("spDoctors.txt", std::ios::in);
  std::string name;
  int count = 0;

  for (int i = 0; i < 15; i++) {
    getline(doctorFile, name);
    count++;
    if (name == "Rayhaan Shahu") {
      break;
    }
  }
  std::cout << count << "\n";
  return 0;
}
