#include <iostream>
#include <string>

#include "person.h"

using namespace std;

Person::Person(string name, int age, Gender gender, string phone_number)
{
     set_name(name);
     set_age(age);
     set_gender(gender);
     set_phone(phone_number);

     show_inf();
}

Person::~Person()
{}

void Person::set_name(string name)
{
     this->name = name;
}

void Person::set_age(int age)
{
     this->age = age;
}

void Person::set_gender(Gender gender)
{
     this->gender = gender;
}

void Person::set_phone(string phone_number)
{
     this->phone_number = phone_number;
}

string Person::get_name() const
{
     return name;
}
	
int Person::get_age() const
{
     return age;
}

Person::Gender Person::get_gender() const
{
     return gender;
}

string Person::get_phone() const
{
     return phone_number;
}

void Person::show_inf() 
{
     cout << "*****************"           << endl;
     cout << "First Name : " << get_name() << "\n" 
             "Age : "        << get_age()  << "\n"
             "Gender : ";
          switch (get_gender())
          {
          case 0:
               cout << "Male" << endl;
               break;
          case 1:
               cout << "Female" << endl;
          case 2:
               cout << "Unknown" << endl;
          }
     cout << "Phone Number : " << get_phone() << endl;
     cout << "*****************" << endl;   
}