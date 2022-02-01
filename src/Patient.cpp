#include <iostream>
#include <string>

#include "../header/Person.hpp"
#include "../header/Patient.hpp"

using namespace std;

Patient::Patient(string name, int age, Gender gender, string phone_number, Insurance insturance, Illness illness, string fee):Person(name, age, gender, phone_number)
{
    set_illness(illness);
    set_insurance(insturance);
    set_status(Patient::Status::Waiting);
    set_fee(fee);
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

void Patient::set_fee(string fee)
{
    this->fee = fee;
}

string Patient::get_fee()
{
    return fee;
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
