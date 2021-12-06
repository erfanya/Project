#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

#include <Hospital.hpp>

vector<unsigned int> Hospital::rooms;

Hospital::Hospital()
{}

Hospital::~Hospital()
{}

void Hospital::add_doctor(Doctor doctor)
{
     this->doctors.push_back(doctor);
}

void Hospital::add_patient(Patient patient)
{
     this->patients.push_back(patient);
}

unsigned int Hospital::set_room_for_visit()
{
     unsigned int temp;
     bool found = false;

     srand(time(0));
          
     while(!found)
     {
          found = true;
          temp = rand() % 50 + 1;

          for (size_t i = 0; i < rooms.size(); i++)
          {
               if (rooms[i] == temp)
               {
                    found = false;
               }
          }
     }

     this->rooms.push_back(temp);
     return temp;
}

void Hospital::set_visit(string doctor_name, string patient_name)
{    
     search_doctor(doctor_name);
     search_patient(patient_name);
     
     cout << "Patient : " << patient_name          << endl;
     cout << "Doctor :"   << doctor_name           << endl;
     cout << "Room : "     << set_room_for_visit() << endl;
     cout << "Visiting ..."                        << endl;
     cout << "Done"                                << endl;
     
     search_patient(patient_name).set_status(Patient::Status::Cured);
     
     cout << "    "                                << endl;
     cout << "Visit report"                        << endl;
     search_patient(patient_name).show_inf();
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
     throw out_of_range("Doctor with this name not found");
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
     throw out_of_range("Patient with this name not found");
}

void Hospital::show_hospital_information() const
{
     cout << "*********************" << endl;
     cout << "Hospital Information " << endl;
     cout << "Number of Doctors :  " << doctors.size()  << endl;
     cout << "Number of Patienrs : " << patients.size() << endl;
}
