#include <iostream>
#include <string>
#include <random>
#include <ctime>

#include "person.hpp"
#include "doctor.hpp"

using namespace std;

std::vector<unsigned int> Doctor::id_list;

Doctor::Doctor(std::string name, unsigned int age, Gender gender, std::string phone_number, Specialization specialization):Person(name, age, gender, phone_number)
{
     make_id();
     set_specialization(specialization);
}

Doctor::~Doctor()
{}

void Doctor::make_id()
{
     unsigned int temp;
     bool found = false;

     srand(time(0));
          
     while(!found)
     {
          found = true;
          temp = rand() % 100 + 1;

          for (size_t i = 0; i < id_list.size(); i++)
          {
               if (id_list[i] == temp)
               {
                    found = false;
               }
          }
     }

     this->id_list.push_back(temp);
     set_id(temp);
}

void Doctor::set_id(unsigned int id)
{
     this->id = id;
}

void Doctor::set_specialization(Specialization specialization)
{
     this->specialization = specialization;
}

unsigned int Doctor::get_id() const
{
     return id;
}

Doctor::Specialization Doctor::get_specialization() const
{
     return specialization;
}

void Doctor::show_inf() const
{
     Person::show_inf();

     cout << "ID : " << get_id() << endl;

     switch (get_specialization())
     {
     case 0:
          cout << "Specialization : General Doctor" << endl;
          break;
     case 1:
          cout << "Specialization : Expert Doctor"  << endl;
          break;
     case 2:
          cout << "Specialization : Surgeon Doctor" << endl;
     default:
          break;
     }
}