#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>

#include "person.hpp"

class Patient : public Person
{	
	public:
          //enum
          enum Insurance {No, Yes};
          enum Illness {Surface, Emergency, Surgery};
          enum Status {Waiting, Cured};
          
          // Constructor
          Patient(std::string name, std::string age, Gender gender, std::string phone_number, Insurance insturance, Illness illness);
     
          //Destructor
		virtual ~Patient();

          //set functions
          void set_status(Status);
          void set_illness(Illness);
          void set_insurance(Insurance);

          //get functions
          Status get_status() const;
          Illness get_illness() const;
          Insurance get_insurance() const;

          // show information
          virtual void show_inf() const;
      
     private:
          //Data members      
          Status status; // vaziyat mariz
          Illness illness; // bimari
          Insurance insurance; // bime
};
#endif