#include<iostream>
#include<string>
#include<stdlib.h>
#include<iomanip>

#include "person.hpp"
#include "Patient.hpp"
#include "Doctor.hpp"
#include "Hospital.hpp"

using namespace std;

int main()
{
     Hospital hospital;     
     //test
     Doctor a("Maryam", 26, Person::Gender::Female, "099090901222", Doctor::Specialization::General);
     Patient p("Ali", 22, Person::Gender::Female, "09188231234", Patient::Blood_types::B, Patient::Insurance::Yes, Patient::Illness::Emergency);
     hospital.add_doctor(a);
     hospital.add_patient(p);
     hospital.set_visit("Maryam", "Ali");
     //end of test

     return 0;
}
