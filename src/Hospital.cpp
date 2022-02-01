#include <iostream>
#include <string>
#include <vector>
#include <QDebug>

using namespace std;

#include "../header/Hospital.hpp"
#include "../header/Doctor.hpp"
#include "../header/Patient.hpp"
#include "../header/Patient.hpp"

Hospital::Hospital()
{}

Hospital::~Hospital()
{}

void Hospital::add_doctor(Doctor doctor)
{
    this->doctors.push_back(doctor);
}

void Hospital::create_doctor(string name, int age, string gender, string phone_number, string specialization)
{
    try {
        if ((gender == "male") && (specialization == "general"))
        {
            Doctor doc(name, age, Person::Gender::Male, phone_number, Doctor::Specialization::General);

            add_doctor(doc);
        }

        if ((gender == "male") && (specialization == "expert"))
        {
            if (get_manager_xp() <= 20)
            {
                throw out_of_range("Your XP must be higher than 20");
            }

            Doctor doc(name, age, Person::Gender::Male, phone_number, Doctor::Specialization::Expert);

            add_doctor(doc);
        }

        if ((gender == "male") && (specialization == "surgeon"))
        {
            if (get_manager_xp() <= 50)
            {
                throw out_of_range("Your XP must be higher than 50");
            }

            Doctor doc(name, age, Person::Gender::Male, phone_number, Doctor::Specialization::Surgeon);

            add_doctor(doc);
        }

        if ((gender == "female") && (specialization == "general"))
        {
            Doctor doc(name, age, Person::Gender::Female, phone_number, Doctor::Specialization::General);

            add_doctor(doc);

        }

        if ((gender == "female") && (specialization == "expert"))
        {
            if (get_manager_xp() <= 20)
            {
                throw out_of_range("Your XP must be higher than 20");
            }

            Doctor doc(name, age, Person::Gender::Female, phone_number, Doctor::Specialization::Expert);

            add_doctor(doc);
        }

        if ((gender == "female") && (specialization == "surgeon"))
        {
            if (get_manager_xp() <= 50)
            {
                throw out_of_range("Your XP must be higher than 50");
            }

            Doctor doc(name, age, Person::Gender::Female, phone_number, Doctor::Specialization::Surgeon);

            add_doctor(doc);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
}

void Hospital::add_patient(Patient patient)
{
    this->patients.push_back(patient);
}

void Hospital::create_patient(string name, int age, string gender, string phone_number, string insurance, string illness)
{
    if ((gender == "male") && (insurance == "no") && (illness == "surface"))
    {
        string fee = "200$";

        Patient pat(name, age, Person::Gender::Male, phone_number, Patient::Insurance::No, Patient::Illness::Surface, fee);

        add_patient(pat);
    }

    if ((gender == "male") && (insurance == "no") && (illness == "emergency"))
    {
        string fee = "500$";

        Patient pat(name, age, Person::Gender::Male, phone_number, Patient::Insurance::No, Patient::Illness::Emergency, fee);

        add_patient(pat);
    }

    if ((gender == "male") && (insurance == "no") && (illness == "surgery"))
    {
        string fee = "1000$";

        Patient pat(name, age, Person::Gender::Male, phone_number, Patient::Insurance::No, Patient::Illness::Surgery, fee);

        add_patient(pat);
    }

    if ((gender == "female") && (insurance == "no") && (illness == "surface"))
    {
        string fee = "200$";

        Patient pat(name, age, Person::Gender::Female, phone_number, Patient::Insurance::No, Patient::Illness::Surface, fee);

        add_patient(pat);
    }

    if ((gender == "female") && (insurance == "no") && (illness == "emergency"))
    {
        string fee = "500$";

        Patient pat(name, age, Person::Gender::Female, phone_number, Patient::Insurance::No, Patient::Illness::Emergency, fee);

        add_patient(pat);
    }

    if ((gender == "female") && (insurance == "no") && (illness == "surgery"))
    {
        string fee = "1000$";

        Patient pat(name, age, Person::Gender::Female, phone_number, Patient::Insurance::No, Patient::Illness::Surgery, fee);

        add_patient(pat);
    }

    if ((gender == "male") && (insurance == "yes") && (illness == "surface"))
    {
        string fee = "100$";

        Patient pat(name, age, Person::Gender::Male, phone_number, Patient::Insurance::Yes, Patient::Illness::Surface, fee);

        add_patient(pat);
    }

    if ((gender == "male") && (insurance == "yes") && (illness == "emergency"))
    {
        string fee = "250$";

        Patient pat(name, age, Person::Gender::Male, phone_number, Patient::Insurance::Yes, Patient::Illness::Emergency, fee);

        add_patient(pat);
    }

    if ((gender == "male") && (insurance == "Yes") && (illness == "surgery"))
    {
        string fee = "500$";

        Patient pat(name, age, Person::Gender::Male, phone_number, Patient::Insurance::Yes, Patient::Illness::Surgery, fee);

        add_patient(pat);
    }

    if ((gender == "female") && (insurance == "Yes") && (illness == "surface"))
    {
        string fee = "100$";

        Patient pat(name, age, Person::Gender::Male, phone_number, Patient::Insurance::Yes, Patient::Illness::Surface, fee);

        add_patient(pat);
    }

    if ((gender == "female") && (insurance == "Yes") && (illness == "emergency"))
    {
        string fee = "250$";

        Patient pat(name, age, Person::Gender::Male, phone_number, Patient::Insurance::Yes, Patient::Illness::Emergency, fee);

        add_patient(pat);
    }

    if ((gender == "female") && (insurance == "Yes") && (illness == "surgery"))
    {
        string fee = "500$";

        Patient pat(name, age, Person::Gender::Male, phone_number, Patient::Insurance::Yes, Patient::Illness::Surgery, fee);

        add_patient(pat);
    }
}

void Hospital::increase_manager_xp(int xp)
{
    this->manager_xp += xp;
}

void Hospital::decrease_manager_xp(int xp)
{
    this->manager_xp -= xp;
}

int Hospital::get_manager_xp()
{
    return manager_xp;
}

void Hospital::increase_hospital_money(int money)
{
    this->hospital_money += money;
}

int Hospital::get_hospital_money()
{
    return hospital_money;
}

Doctor & Hospital::search_doctor(string name)
{
    for (size_t i = 0; i < doctors.size(); i++)
    {
        if (doctors[i].get_name() == name)
        {
            return doctors[i];
        }
    }
}

Patient & Hospital::search_patient(string name)
{
    for (size_t i = 0; i < patients.size(); i++)
    {
        if (patients[i].get_name() == name)
        {
            return patients[i];
        }
    }
}

int Hospital::get_doctors_size()
{
    int size = doctors.size();

    return size;
}

int Hospital::get_patients_size()
{
    int size = patients.size();

    return size;
}
