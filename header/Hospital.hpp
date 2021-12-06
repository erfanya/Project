#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include <Doctor.hpp>
#include <Patient.hpp>

#include <vector>
#include <string>

class Hospital
{
     public:
          Hospital();
          virtual ~Hospital();

          void add_doctor(Doctor);
          void add_patient(Patient);
          void set_visit(std::string, std::string);          
          unsigned int set_room_for_visit();

          Doctor & search_doctor(std::string);
          Patient & search_patient(std::string);
          
          virtual void show_hospital_information() const;          
     private:
          std::vector<Doctor> doctors;
          std::vector<Patient> patients;
          static std::vector<unsigned int> rooms;
};
#endif