#include <iostream>

#include "Person.h"

int main() {
  Person p1;
  p1.setName("Eva");
  p1.setPhoneNo("0402042332");
  p1.setAdress("Northfield");
  p1.setEmail("raminshahu786@gmail.com");
  std::cout << p1.getName() << p1.getPhoneNo() << p1.getAdress()
            << p1.getEmail() << "\n";
}