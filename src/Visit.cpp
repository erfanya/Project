#include <iostream>
#include <string>

#include "visit.hpp"
#include "person.hpp"
#include "patient.hpp"
#include "doctor.hpp"

using namespace std;

Visit::~Visit()
{}

void Visit::set_visit_time(Visit_Time visit_time)
{
     this->visit_time = visit_time;
}

void Visit::set_room(int room)
{
     this->room = room;
}

//void Visit::set_doctor()
//{}

//void Visit::set_patient()
//{}

void Visit::set_cost(Cost cost)
{
     this->cost = cost;
}

Visit::Visit_Time Visit::get_visit_time() const
{
     return visit_time;
}

int Visit::get_room() const
{
     return room;
}

//Visit::get_doctor() const
//{}

//Visit::get_patient() const
//{}

Visit::Cost Visit::get_cost() const
{
     return cost;
}
