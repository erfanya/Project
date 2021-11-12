#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include <string>

class Doctor
{	
	public:
          // enum
          enum Specialization {General, Expert, Surgeon, Unknown};
          
          // Constructor
          Doctor(int id = 0, Specialization specialization = {Unknown});
          Doctor(const Doctor&);//coppy constructor

          //Destructor
		~Doctor();

          //set and get functions
          void set_id(int);
		void set_specialization(Specialization);
        
	     int get_id() const;
          Specialization get_specialization() const;
        
     private:
          //Data members      
          int id; 
          Specialization specialization;// takhasos 
};

#endif
