#include <iostream>
#include <string>

#include "person.hpp"

using namespace std;

Person::Person(string name, string age, Gender gender, string phone_number)
{
     check_name(name);
     set_age(age);
     set_gender(gender);
     set_phone(phone_number);
}

Person::~Person()
{}

void Person::set_name(string name)
{
     this->name = name;
}

void Person::check_name(string name)
{
     bool check_num = false;

     for (auto letter : name)
     {
          for (char ch = '0'; ch <= '9' && !check_num; ch++)
          {
               if (ch == letter)
               {
                    check_num = true;
               }
          }
     }

     for (size_t i = 0; i < name.length(); i++)
     {
          name[i] = tolower(name[i]);
     }
     
     if (check_num == false)
     {
          set_name(name);
     }
     else
     {
          throw invalid_argument("Enter a valid name");
     }
}
     
void Person::set_age(string age)
{
     bool check_low = false;
     bool check_upp = false;

     for (auto letter : age)
     {
          for (char ch = 'a'; ch <= 'z' && !check_low; ch++)
          {
               if (ch == letter)
               {
                    check_low = true;
               }
          }

          for(char ch = 'A'; ch <= 'Z' && !check_upp; ch++)
          {
               if(ch == letter)
               {
                    check_upp = true;
               }
          }
     }

     if (check_low == true || check_upp == true)
     {
          throw invalid_argument("Enter a valid age");
     }

     if (stoi(age) <= 0 || stoi(age) > 110)
     {
          throw invalid_argument("Enter a valid age");
     }

     this->age = age;
}

void Person::set_gender(Gender gender)
{
     this->gender = gender;
}

void Person::set_phone(string phone_number)
{
     if (phone_number.length() != 11)
     {
          throw invalid_argument("Enter a valid phone number");
     }
     this->phone_number = phone_number;
}

string Person::get_name() const
{
     return name;
}
	
string Person::get_age() const
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

void Person::show_inf() const
{
     cout << "------------------------"       << endl;
     cout << "Name : " << get_name()          << endl; 
     cout << "Age : "  << get_age()           << endl;
     cout << "Gender : ";
          switch (get_gender())
          {
          case 0:
               cout << "Male"                 << endl;
               break;
          case 1:
               cout << "Female"               << endl;
               break;
          }
     cout << "Phone Number : " << get_phone() << endl;
}