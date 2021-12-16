#include <iostream>
#include <string>

#include "person.hpp"
#include "patient.hpp"

using namespace std;

Patient::Patient(string name, string age, Gender gender, string phone_number, Insurance insturance, Illness illness):Person(name, age, gender, phone_number)
{
     set_illness(illness);
     set_insurance(insturance);
     set_status(Patient::Status::Waiting);
}

Patient::~Patient()
{}

void Patient::set_status(Status status)
{
     this->status = status;
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

     switch (get_insurance())
     {
     case 0:
          cout << "Insurance : NO"      << endl;    
          break;
     case 1:
          cout << "Insurance : YES"     << endl;
          break;
     }

     switch (get_illness())
     {
     case 0:
          cout << "Illness : Surface"   << endl;    
          break;
     case 1:
          cout << "Illness : Emergency" << endl;
          break;
     case 2:
          cout << "Illness : Surgery"   << endl;
          break;
     }

     switch (get_status())
     {
     case 0:
          cout << "Status : Waiting"    << endl;
          break;
     case 1:
          cout << "Status : Cured"      << endl;
          break;
     }
     cout << "------------------------" << endl;
}