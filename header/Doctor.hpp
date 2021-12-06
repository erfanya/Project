#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include "Person.hpp"

#include <string>
#include <vector>

class Doctor : public Person
{	
	public:
          // enum
          enum Specialization {General, Expert, Surgeon};
          
          // Constructor
          Doctor(std::string name, unsigned int age, Gender gender, std::string phone_number, Specialization specialization);
         
          //Destructor
		virtual ~Doctor();

          // make id by system
          void make_id();
          //set and get functions
          void set_id(unsigned int);
		void set_specialization(Specialization);
        
	     unsigned int get_id() const;
          Specialization get_specialization() const;

          // show information
          virtual void show_inf() const;
     private:
          //Data members      
          unsigned int id; // id
          Specialization specialization = General;// takhasos 
          static std::vector<unsigned int> id_list;
};
#endif