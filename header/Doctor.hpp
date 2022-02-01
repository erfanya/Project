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
    Doctor(std::string name, int age, Gender gender, std::string phone_number, Specialization specialization);

    //Destructor
    virtual ~Doctor();

    //set and get functions
    void set_specialization(Specialization);
    Specialization get_specialization() const;

private:
    //Data members
    Specialization specialization;// takhasos
};
#endif
