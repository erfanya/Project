#include <iostream>
#include <string>

#include "person.hpp"
#include "doctor.hpp"

using namespace std;

Doctor::~Doctor()
{}

void Doctor::set_id(int id)
{
     if (id > 0 && id <= 100)
     {
          this->id = id;
     }
     else
     {
          cout << "Enter a valid ID Number (1-100)" << endl;
     }
}

void Doctor::set_specialization(Specialization specialization)
{
     this->specialization = specialization;
}

int Doctor::get_id() const
{
     return id;
}

Doctor::Specialization Doctor::get_specialization() const
{
     return specialization;
}
