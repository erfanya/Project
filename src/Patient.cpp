#include <iostream>
#include <string>

#include "person.hpp"
#include "patient.hpp"

using namespace std;

Patient::~Patient()
{}

void Patient::set_blood_type(Blood_types blood_type)
{
     this->blood_type = blood_type;
}

void Patient::set_illness(Illness illness)
{
     this->illness = illness;
}

void Patient::set_insurance(Insurance insturance)
{
     this->insurance = insurance;
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
