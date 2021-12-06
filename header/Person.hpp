#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person
{	
	public:
		//Enum
		enum Gender{Male, Female};

		//Constructor
		Person(std::string name , unsigned int age , Gender gender , std::string phone); 
		
		//Destructor
		virtual ~Person();
	
		//Set and get functions
		void set_name(std::string);
		void set_age(unsigned int);
		void set_gender(Gender);
		void set_phone(std::string);

		std::string get_name() const;
		unsigned int get_age() const;
		Gender get_gender() const;
		std::string get_phone() const;

		// show information
		virtual void show_inf() const;

     private:
		// Data member
		std::string name;
		unsigned int age;
		Gender gender;
		std::string phone_number;
};
#endif