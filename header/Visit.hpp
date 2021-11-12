#ifndef VISIT_HPP
#define VISIT_HPP

#include <string>

class Visit
{	
	public:
          //enum
          enum Visit_Time {Morning, Noon, Afternoon, Evening, Night};
          enum Cost {Expensive, Cheap, Free};

          // Constructor
          Visit(Visit_Time visit_time = {Morning}, int room = 1, Cost cost = {Expensive});
          Visit(const Visit&);// coppy constructor

          //Destructor
		~Visit();

          // set and get fucntions
          void set_visit_time(Visit_Time);
          void set_room(int);
          //void set_doctor();
          //void set_patient();
          void set_cost(Cost);

          Visit_Time get_visit_time() const;
          int get_room() const;
          //get_doctor() const;
          // get_patient() const;
          Cost get_cost() const;
     
     private:
          //Data members
          Visit_Time visit_time;
          int room;
          // doctor;
          // patient;
          Cost cost;
};

#endif
