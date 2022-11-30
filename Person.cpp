
#include "Person.h"

#include <iostream>

Person::Person(std::string name, std::string phoneNo, std::string adress,
               std::string email) {
  this->name = name;
  this->phoneNo = phoneNo;
  this->adress = adress;
  this->email = email;
}
Person::Person() {
  this->name = "";
  this->phoneNo = "";
  this->adress = "";
  this->email = "";
}

std::string Person::getName() { return this->name; }
std::string Person::getPhoneNo() { return this->phoneNo; }
std::string Person::getAdress() { return this->adress; }
std::string Person::getEmail() { return this->email; }

void Person::setName(std::string name) { this->name = name; }
void Person::setPhoneNo(std::string phoneNo) { this->phoneNo = phoneNo; }

void Person::setAdress(std::string adress) { this->adress = adress; }

void Person::setEmail(std::string email) { this->email = email; }

Person::~Person() {}
