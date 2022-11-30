#include <iostream>
#ifndef Person_H
#define Person_H

class Person {
 public:
  std::string name;
  std::string phoneNo;
  std::string adress;
  std::string email;

 public:
  Person(std::string name, std::string phoneNo, std::string adress,
       std::string email);
  Person();
  void setName(std::string name);
  void setPhoneNo(std::string phoneNo);
  void setAdress(std::string adress);
  void setEmail(std::string email);
  void setAge(int age);
  std::string getName();
  std::string getPhoneNo();
  std::string getAdress();
  std::string getEmail();
  virtual void dispInfo() = 0;
  ~Person();
};

#endif