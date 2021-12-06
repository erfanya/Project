#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>

#include "person.hpp"

class Patient : public Person
{	
	public:
          //enum
          enum Blood_types {A, B, AB, O, Unknown};
          enum Insurance {No, Yes};
          enum Illness {Emergency, Calm, Unknown_Illness};
          enum Status {Waiting, Cured};
          
          // Constructor
          Patient(std::string name, unsigned int age, Gender gender, std::string phone_number, Blood_types blood_type, Insurance insturance, Illness illness);
     
          //Destructor
		virtual ~Patient();

          //set and get functions
          void set_status(Status);
          void set_blood_type(Blood_types);
          void set_illness(Illness);
          void set_insurance(Insurance);
      
          Status get_status() const;
		Blood_types get_blood_type() const;
          Illness get_illness() const;
          Insurance get_insurance() const;

          // show information
          virtual void show_inf() const;
      
     private:
          //Data members      
          Status status = Waiting; // vaziyat mariz
          Blood_types blood_type = Unknown; // goroh khooni
          Illness illness = Unknown_Illness; // bimari
          Insurance insurance = No; // bime
};
#endif