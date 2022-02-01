#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include "Doctor.hpp"
#include "Patient.hpp"

#include <vector>
#include <string>

class Hospital
{
public:
    Hospital();
    //Destructor
    virtual ~Hospital();

    //adds
    void create_doctor(std::string name, int age, std::string gender, std::string phone_number, std::string specialization);
    void add_doctor(Doctor);

    void create_patient(std::string name, int age, std::string gender, std::string phone_number, std::string insurance, std::string illness);
    void add_patient(Patient);

    //manager xp
    void increase_manager_xp(int);
    void decrease_manager_xp(int);
    int get_manager_xp();

    //hospital money
    void increase_hospital_money(int);
    int get_hospital_money();

    //search
    Doctor & search_doctor(std::string);
    Patient & search_patient(std::string);

    int get_doctors_size();
    int get_patients_size();
private:
    //data members
    int manager_xp = 0;
    int hospital_money = 0;
    std::vector<Doctor> doctors;
    std::vector<Patient> patients;
};
#endif
