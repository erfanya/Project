#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>

#include "Person.hpp"

class Patient : public Person
{	
public:
    //enum
    enum Insurance {No, Yes};
    enum Illness {Surface, Emergency, Surgery};
    enum Status {Waiting, Cured};

    // Constructor
    Patient(std::string name, int age, Gender gender, std::string phone_number, Insurance insturance, Illness illness, std::string fee);

    //Destructor
    virtual ~Patient();

    //set functions
    void set_status(Status);
    void set_illness(Illness);
    void set_insurance(Insurance);
    void set_fee(std::string);

    //get functions
    Status get_status() const;
    Illness get_illness() const;
    Insurance get_insurance() const;
    std::string get_fee();

private:
    //Data members
    Status status; // vaziyat mariz
    Illness illness; // bimari
    Insurance insurance; // bime
    std::string fee;
};
#endif
