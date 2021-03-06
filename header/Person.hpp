#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person
{	
public:
    //Enum
    enum Gender{Male, Female};

    //Constructor
    Person(std::string name , int age , Gender gender , std::string phone);

    //Destructor
    virtual ~Person();

    //Set and get functions
    void set_name(std::string);
    void check_name(std::string);
    void set_age(int);
    void set_gender(Gender);
    void set_phone(std::string);

    std::string get_name() const;
    int get_age() const;
    Gender get_gender() const;
    std::string get_phone() const;

private:
    // Data member
    std::string name;
    int age;
    Gender gender;
    std::string phone_number;
};
#endif
