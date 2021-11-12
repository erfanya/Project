#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>

#include "person.hpp"

class Patient
{	
	public:
          //enum
          enum Blood_types {A,B,AB,O,Unknown};
          enum Insurance {Yes, No, Unknown_Insurance};
          enum Illness {Emergency, Calm, Unknown_Illness};
          
          // Constructor
          Patient(Blood_types blood_type = {Unknown}, Illness illness = {Unknown_Illness}, Insurance insturance = {Unknown_Insurance});
          Patient(const Patient&);//coppy constructor

          //Destructor
		~Patient();

          //set and get functions
          void set_blood_type(Blood_types);
          void set_illness(Illness);
          void set_insurance(Insurance);
      
		Blood_types get_blood_type() const;
          Illness get_illness() const;
          Insurance get_insurance() const;
      
     private:
          //Data members      
          Blood_types blood_type; // goroh khooni
          Illness illness; // bimari
          Insurance insurance; // bime
};

#endif
