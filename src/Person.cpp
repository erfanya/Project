#include <iostream>
#include <string>

#include "../header/Person.hpp"

using namespace std;

Person::Person(string name, int age, Gender gender, string phone_number)
{
    check_name(name);
    set_age(age);
    set_gender(gender);
    set_phone(phone_number);
}

Person::~Person()
{}

void Person::set_name(string name)
{
    this->name = name;
}

void Person::check_name(string name)
{
    set_name(name);
}

void Person::set_age(int age)
{
    this->age = age;
}

void Person::set_gender(Gender gender)
{
    this->gender = gender;
}

void Person::set_phone(string phone_number)
{
    this->phone_number = phone_number;
}

string Person::get_name() const
{
    return name;
}

int Person::get_age() const
{
    return age;
}

Person::Gender Person::get_gender() const
{
    return gender;
}

string Person::get_phone() const
{
    return phone_number;
}
