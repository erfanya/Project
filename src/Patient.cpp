#include <iostream>
#include <string>

#include "person.hpp"
#include "patient.hpp"

using namespace std;

Patient::Patient(std::string name, unsigned int age, Gender gender, std::string phone_number, Blood_types blood_type, Insurance insturance, Illness illness):Person(name,age,gender,phone_number)
{
     set_blood_type(blood_type);
     set_illness(illness);
     set_insurance(insturance);
}

Patient::~Patient()
{}

void Patient::set_status(Status status)
{
     this->status = status;
}

void Patient::set_blood_type(Blood_types blood_type)
{
     this->blood_type = blood_type;
}

void Patient::set_illness(Illness illness)
{
     this->illness = illness;
}

void Patient::set_insurance(Insurance insurance)
{
     this->insurance = insurance;
}

Patient::Status Patient::get_status() const
{
     return status;
}

Patient::Blood_types Patient::get_blood_type() const
{
     return blood_type;
}

Patient::Illness Patient::get_illness() const
{
     return illness;
}

Patient::Insurance Patient::get_insurance() const
{
     return insurance;
}

void Patient::show_inf() const
{
     Person::show_inf();

     switch (get_status())
     {
     case 0:
          cout << "Status : Watiing"     << endl;
          break;
     case 1:
          cout << "Status : Cured"       << endl;
          break;
     }

     switch (get_blood_type())
     {
     case 0:
          cout << "Blood type : A"       << endl;    
          break;
     case 1:
          cout << "Blood type : B"       << endl;
          break;
     case 2:
          cout << "Blood type : AB"      << endl;
          break;
     case 3:
          cout << "Blood type : O"       << endl;
          break;
     case 4:
          cout << "Blood type : Unknown" << endl;
     default:
          throw invalid_argument("Invalid Blood type");
     }

     switch (get_insurance())
     {
     case 0:
          cout << "Insurance : NO" << endl;    
          break;
     case 1:
          cout << "Insurance : YES"  << endl;
          break;
     default:
          throw invalid_argument("Invalid Insurance");
     }

     switch (get_illness())
     {
     case 0:
          cout << "Illness : Emergency"       << endl;    
          break;
     case 1:
          cout << "Illness : Calm"            << endl;
          break;
     case 2:
          cout << "Illness : Unknown illness" << endl;
          break;
     default:
          throw invalid_argument("Invalid Illness");
     }
}