#include <iostream>
#include <string>
#include <random>
#include <ctime>

#include "header/Doctor.hpp"

using namespace std;

Doctor::Doctor(string name, int age, Gender gender, string phone_number, Specialization specialization):Person(name, age, gender, phone_number)
{
    set_specialization(specialization);
}

Doctor::~Doctor()
{}

void Doctor::set_specialization(Specialization specialization)
{
    this->specialization = specialization;
}

Doctor::Specialization Doctor::get_specialization() const
{
    return specialization;
}
