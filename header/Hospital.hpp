#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include <Doctor.hpp>
#include <Patient.hpp>

#include <vector>
#include <string>

class Hospital
{
     public:
          //Constructor
          Hospital();

          //Destructor
          virtual ~Hospital();

          //adds
          void add_doctor(Doctor);
          void add_patient(Patient);

          //manager xp
          void increase_manager_xp(unsigned int);
          void decrease_manager_xp(unsigned int);
          unsigned int get_manager_xp();

          //visit
          void set_visit(std::string, std::string);          
          unsigned int set_room_for_visit();

          //search 
          Doctor & search_doctor(std::string);
          Patient & search_patient(std::string);
          
          //show inf
          virtual void show_inf();

     private:
          //data members
          unsigned int manager_xp = 0;
          std::vector<Doctor> doctors;
          std::vector<Patient> patients;
          static std::vector<unsigned int> rooms;
};
#endif