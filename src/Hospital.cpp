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

void Hospital::increase_manager_xp(unsigned int xp)
{
     this->manager_xp += xp;
}

void Hospital::decrease_manager_xp(unsigned int xp)
{
     this->manager_xp -= xp;
}

unsigned int Hospital::get_manager_xp()
{
     return manager_xp;
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
     if (search_patient(patient_name).get_illness() == 0)
     {
          if (search_doctor(doctor_name).get_specialization() == 1)
          {
               if (get_manager_xp() >= 10)
               {
                    decrease_manager_xp(10);
               }
               throw invalid_argument("Bad choice --> -10xp");
          }
          
          if (search_doctor(doctor_name).get_specialization() == 2)
          {
               if (get_manager_xp() >= 20)
               {
                    decrease_manager_xp(20);
               }
               throw invalid_argument("Bad choice --> -20xp");
          }

          system("clear");
          search_patient(patient_name).set_status(Patient::Status::Cured);
          increase_manager_xp(10);
          cout << "------------------------"                                                            << endl;
          cout << "--Visit report"                                                                      << endl;
          cout << " "                                                                                   << endl;
          cout << "Doctor : " << doctor_name << " | " << "ID : " << search_doctor(doctor_name).get_id() << endl;
          cout << "Patient : " << patient_name                                                          << endl;
          cout << "Room : "     << set_room_for_visit()                                                 << endl;
          if (search_patient(patient_name).get_insurance() == 0 )
          {
               cout << "Cost = 150$"                                                                    << endl;
          }
          if (search_patient(patient_name).get_insurance() == 1 )
          {
               cout << "Cost = 75$"                                                                     << endl;
          }
          cout << "Done"                                                                                << endl;
          cout << "------------------------"                                                            << endl;
     }
     
     if (search_patient(patient_name).get_illness() == 1)
     {
          if (search_doctor(doctor_name).get_specialization() == 0)
          {
               if (get_manager_xp() >= 20)
               {
                    decrease_manager_xp(20);
               }
               throw invalid_argument("Bad choice --> -10xp");
          }
          
          if (search_doctor(doctor_name).get_specialization() == 2)
          {
               if (get_manager_xp() >= 10)
               {
                    decrease_manager_xp(10);
               }
               throw invalid_argument("Bad choice --> -20xp");
          }

          system("clear");
          search_patient(patient_name).set_status(Patient::Status::Cured);
          increase_manager_xp(20);
          cout << "------------------------"                                                            << endl;
          cout << "--Visit report"                                                                      << endl;
          cout << " "                                                                                   << endl;
          cout << "Doctor : " << doctor_name << " | " << "ID : " << search_doctor(doctor_name).get_id() << endl;
          cout << "Patient : " << patient_name                                                          << endl;
          cout << "Room : "     << set_room_for_visit()                                                 << endl;
          if (search_patient(patient_name).get_insurance() == 0 )
          {
               cout << "Cost = 300$"                                                                    << endl;
          }
          if (search_patient(patient_name).get_insurance() == 1 )
          {
               cout << "Cost = 150$"                                                                    << endl;
          }
          cout << "Done"                                                                                << endl;
          cout << "------------------------"                                                            << endl;
     }

     if (search_patient(patient_name).get_illness() == 2)
     {
          if (search_doctor(doctor_name).get_specialization() == 0)
          {
               if (get_manager_xp() >= 30)
               {
                    decrease_manager_xp(30);
               }
               throw invalid_argument("Bad choice --> -10xp");
          }
          
          if (search_doctor(doctor_name).get_specialization() == 1)
          {
               if (get_manager_xp() >= 20)
               {
                    decrease_manager_xp(20);
               }
               throw invalid_argument("Bad choice --> -20xp");
          }

          system("clear");
          search_patient(patient_name).set_status(Patient::Status::Cured);
          increase_manager_xp(30);
          cout << "------------------------"                                                            << endl; 
          cout << "--Visit report"                                                                      << endl;
          cout << " "                                                                                   << endl;
          cout << "Doctor : " << doctor_name << " | " << "ID : " << search_doctor(doctor_name).get_id() << endl;
          cout << "Patient : " << patient_name                                                          << endl;
          cout << "Room : "     << set_room_for_visit()                                                 << endl;
          if (search_patient(patient_name).get_insurance() == 0 )
          {
               cout << "Cost = 2000$"                                                                   << endl;
          }
          if (search_patient(patient_name).get_insurance() == 1 )
          {
               cout << "Cost = 1000$"                                                                   << endl;
          }
          cout << "Done"                                                                                << endl;
          cout << "------------------------"                                                            << endl;
     }
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

void Hospital::show_inf() 
{
     system("clear");
     cout << "------------------------"                    << endl;
     cout << "--Hospital Information"                      << endl;
     cout << "Number of Doctors : "    << doctors.size()   << endl;
     cout << "Number of Patients : "   << patients.size()  << endl;
     cout << "Number of rooms : "      << 50               << endl;
     cout << "Manager XP : "           << get_manager_xp() << endl;
     cout << "------------------------"                    << endl;
}
