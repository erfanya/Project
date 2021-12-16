#include<iostream>
#include<string>

#include "Patient.hpp"
#include "Doctor.hpp"
#include "Hospital.hpp"

using namespace std;

void to_lower(string & temp)
{
     for (size_t i = 0; i < temp.length(); i++)
     {
          temp[i] = tolower(temp[i]);
     }
}

void help()
{
     system("clear");
     cout << "------------------------" << endl;
     cout << "1 : Add a Doctor        " << endl;
     cout << "2 : Add a Patient       " << endl;
     cout << "3 : Set a Visit         " << endl;
     cout << "4 : Doctor information  " << endl;
     cout << "5 : Patient information " << endl;
     cout << "6 : Hospital information" << endl;
     cout << "7 : Exit                " << endl;
     cout << "------------------------" << endl;
}

void sec_help()
{
     cout << "------------------------"                   << endl;
     cout << "-General Doctors are for surface Patients"  << endl;
     cout << "-Expert Doctors are for emergency Patients" << endl;
     cout << "-Surgeon Doctors are for surgery Patients"  << endl;
     cout << "------------------------"                   << endl;
}

int main()
{
     system("clear");
     help();

     Hospital hospital;         
     string choice;

     while (1)
     {
          try
          {
               if (hospital.get_manager_xp() > 250)
               {
                    system("clear");
                    cout << "Victory"                                                    << endl;
                    cout << "You can go and try to manage a real hospital right now ;)"  << endl;
                    break;
               }
               
               cout << " "                                     << endl;
               cout << "--Enter (help) for more information--" << endl;
               cout << " "                                     << endl;
               cout << "Enter your choice : ";
               cin >> choice;    

               if (choice == "1")
               {
                    string name;
                    string first_name;
                    string last_name;
                    string age;
                    string gender;
                    string phone_number;
                    string specialization;
                    bool add = false;

                    system("clear");

                    cout << "--Add a Doctor" << endl;

                    cout << "Enter Doctor first name : ";
                    cin >> first_name;

                    cout << "Enter Doctor last name : ";
                    cin >> last_name;

                    name = first_name + " " + last_name;

                    cout << "Enter Doctor age (+18) : ";
                    cin >> age;

                    if (stoi(age) < 18)
                    {
                         throw out_of_range("We only accept doctors with +18 age");
                    }
                    
                    cout << "Enter Doctor gender (Male or Female) : ";
                    cin >> gender;

                    cout << "Enter Doctor phone number : ";
                    cin >> phone_number;

                    cout << "Enter Doctor specialization (General or Expert or Surgeon) : ";
                    cin >> specialization;
                    
                    to_lower(gender);
                    to_lower(specialization);

               if ((gender == "male") && (specialization == "general"))
                    {
                         Doctor doc(name, age, Person::Gender::Male, phone_number, Doctor::Specialization::General);

                         hospital.add_doctor(doc);

                         add = true;
                         
                         system("clear");

                         cout << "Doctor Aded" << endl;
                    }
                    
                    if ((gender == "male") && (specialization == "expert"))
                    {
                         if (hospital.get_manager_xp() <= 50)
                         {
                              throw out_of_range("Your XP must be higher than 50");
                         }
                         
                         Doctor doc(name, age, Person::Gender::Male, phone_number, Doctor::Specialization::Expert);

                         hospital.add_doctor(doc);

                         add = true;

                         system("clear");

                         cout << "Doctor Aded" << endl;
                    }

                    if ((gender == "male") && (specialization == "surgeon"))
                    {
                         if (hospital.get_manager_xp() <= 100)
                         {
                              throw out_of_range("Your XP must be higher than 100");
                         }

                         Doctor doc(name, age, Person::Gender::Male, phone_number, Doctor::Specialization::Surgeon);

                         hospital.add_doctor(doc);

                         add = true;

                         system("clear");

                         cout << "Doctor Aded" << endl;
                    }

                    if ((gender == "female") && (specialization == "general"))
                    {
                         Doctor doc(name, age, Person::Gender::Female, phone_number, Doctor::Specialization::General);

                         hospital.add_doctor(doc);

                         add = true;

                         system("clear");

                         cout << "Doctor Aded" << endl;
                    }
                    
                    if ((gender == "female") && (specialization == "expert"))
                    {
                         if (hospital.get_manager_xp() <= 50)
                         {
                              throw out_of_range("Your XP must be higher than 50");
                         }

                         Doctor doc(name, age, Person::Gender::Female, phone_number, Doctor::Specialization::Expert);

                         hospital.add_doctor(doc);

                         add = true;

                         system("clear");

                         cout << "Doctor Aded" << endl;
                    }

                    if ((gender == "female") && (specialization == "surgeon"))
                    {
                         if (hospital.get_manager_xp() <= 100)
                         {
                              throw out_of_range("Your XP must be higher than 100");
                         }

                         Doctor doc(name, age, Person::Gender::Female, phone_number, Doctor::Specialization::Surgeon);

                         hospital.add_doctor(doc);

                         add = true;

                         system("clear");
                         
                         cout << "Doctor Aded" << endl;
                    }

                    if (add == false)
                    {
                         cout << "Error --> Enter valid arguments" << endl;
                    }
               }

               if (choice == "2")
               {
                    string name;
                    string first_name;
                    string last_name;
                    string age;
                    string gender;
                    string phone_number;
                    string insurance;
                    string illness;
                    bool add = false;

                    
                    system("clear");

                    cout << "--Add a Patient" << endl;

                    cout << "Enter Patient first name : ";
                    cin >> first_name;

                    cout << "Enter Patient last name : ";
                    cin >> last_name;

                    name = first_name + " " + last_name;

                    cout << "Enter Patient age : ";
                    cin >> age;

                    cout << "Enter Patient gender (Male or Female) : ";
                    cin >> gender;

                    cout << "Enter Patient phone number : ";
                    cin >> phone_number;

                    cout << "Enter Patient insurance (Yes or No) : ";
                    cin >> insurance;

                    cout << "Enter Patient illness (Surface or Emergency or Surgery): ";
                    cin >> illness;

                    to_lower(gender);
                    to_lower(insurance);
                    to_lower(illness);

                    if ((gender == "male") && (insurance == "no") && (illness == "surface"))
                    {
                         Patient pat(name, age, Person::Gender::Male, phone_number, Patient::Insurance::No, Patient::Illness::Surface);

                         hospital.add_patient(pat);

                         add = true;

                         system("clear");

                         cout << "Patient Aded to list" << endl;
                    }

                    if ((gender == "male") &&  (insurance == "no") && (illness == "emergency"))
                    {
                         Patient pat(name, age, Person::Gender::Male, phone_number, Patient::Insurance::No, Patient::Illness::Emergency);

                         hospital.add_patient(pat);

                         add = true;

                         system("clear");

                         cout << "Patient Aded to list" << endl;
                    }
                    
                    if ((gender == "male") && (insurance == "no") && (illness == "surgery"))
                    {
                         Patient pat(name, age, Person::Gender::Male, phone_number, Patient::Insurance::No, Patient::Illness::Surgery);

                         hospital.add_patient(pat);

                         add = true;

                         system("clear");

                         cout << "Patient Aded to list" << endl;
                    }

                    if ((gender == "female") && (insurance == "no") && (illness == "surface"))
                    {
                         Patient pat(name, age, Person::Gender::Female, phone_number, Patient::Insurance::No, Patient::Illness::Surface);

                         hospital.add_patient(pat);

                         add = true;

                         system("clear");

                         cout << "Patient Aded to list" << endl;
                    }

                    if ((gender == "female") &&  (insurance == "no") && (illness == "emergency"))
                    {
                         Patient pat(name, age, Person::Gender::Female, phone_number, Patient::Insurance::No, Patient::Illness::Emergency);

                         hospital.add_patient(pat);

                         add = true;

                         system("clear");

                         cout << "Patient Aded to list" << endl;
                    }
                    
                    if ((gender == "female") && (insurance == "no") && (illness == "surgery"))
                    {
                         Patient pat(name, age, Person::Gender::Female, phone_number, Patient::Insurance::No, Patient::Illness::Surgery);

                         hospital.add_patient(pat);

                         add = true;

                         system("clear");

                         cout << "Patient Aded to list" << endl;
                    }

                    if ((gender == "male") && (insurance == "yes") && (illness == "surface"))
                    {
                         Patient pat(name, age, Person::Gender::Male, phone_number, Patient::Insurance::Yes, Patient::Illness::Surface);

                         hospital.add_patient(pat);

                         add = true;

                         system("clear");

                         cout << "Patient Aded to list" << endl;
                    }

                    if ((gender == "male") &&  (insurance == "yes") && (illness == "emergency"))
                    {
                         Patient pat(name, age, Person::Gender::Male, phone_number, Patient::Insurance::Yes, Patient::Illness::Emergency);

                         hospital.add_patient(pat);

                         add = true;

                         system("clear");

                         cout << "Patient Aded to list" << endl;
                    }
                    
                    if ((gender == "male") && (insurance == "Yes") && (illness == "surgery"))
                    {
                         Patient pat(name, age, Person::Gender::Male, phone_number, Patient::Insurance::Yes, Patient::Illness::Surgery);

                         hospital.add_patient(pat);

                         add = true;

                         system("clear");

                         cout << "Patient Aded to list" << endl;
                    }

                    if ((gender == "female") && (insurance == "Yes") && (illness == "surface"))
                    {
                         Patient pat(name, age, Person::Gender::Male, phone_number, Patient::Insurance::Yes, Patient::Illness::Surface);

                         hospital.add_patient(pat);

                         add = true;

                         system("clear");

                         cout << "Patient Aded to list" << endl;
                    }

                    if ((gender == "female") &&  (insurance == "Yes") && (illness == "emergency"))
                    {
                         Patient pat(name, age, Person::Gender::Male, phone_number, Patient::Insurance::Yes, Patient::Illness::Emergency);

                         hospital.add_patient(pat);

                         add = true;

                         system("clear");

                         cout << "Patient Aded to list" << endl;
                    }
                    
                    if ((gender == "female") && (insurance == "Yes") && (illness == "surgery"))
                    {
                         Patient pat(name, age, Person::Gender::Male, phone_number, Patient::Insurance::Yes, Patient::Illness::Surgery);

                         hospital.add_patient(pat);

                         add = true;

                         system("clear");

                         cout << "Patient Aded to list" << endl;
                    }              

                    if (add == false)
                    {
                         cout << "Error --> Enter valid arguments" << endl;
                    }
               }

               if (choice == "3")
               {
                    system("clear");

                    if (hospital.get_manager_xp() < 10)
                    {
                         sec_help();
                    }
                    
                    cout << "--Set Visit" << endl;
                    cout << " "           << endl;

                    string doctor_name;
                    string doctor_first_name;
                    string doctor_last_name;

                    string patient_name;
                    string patient_first_name;
                    string patient_last_name;

                    cout << "Enter Patient first name : ";
                    cin >> patient_first_name;

                    cout << "Enter Patient last name : ";
                    cin >> patient_last_name;
                    
                    patient_name = patient_first_name + " " + patient_last_name;

                    cout << " " << endl;
                    cout << "Enter Doctor first name : ";
                    cin >> doctor_first_name;

                    cout << "Enter Doctor last name : ";
                    cin >> doctor_last_name;
                    
                    doctor_name = doctor_first_name + " " + doctor_last_name;

                    to_lower(doctor_name);
                    to_lower(patient_name);

                    if (hospital.search_patient(patient_name).get_status() == 1)
                    {
                         system("clear");
                         throw out_of_range("Patient already visited");
                    }
          
                    hospital.set_visit(doctor_name, patient_name);
               }

               if (choice == "4")
               {    
                    system("clear");
                    cout << "--Doctor Information" << endl;
                    cout << " "                    << endl;
                    string name;
                    string first_name;
                    string last_name;

                    cout << "Enter a Doctor First name : ";
                    cin >> first_name;
                    
                    cout << "Enter last name : ";
                    cin >> last_name;

                    name = first_name + " " + last_name;
                    
                    cout << " " << endl;
                    hospital.search_doctor(name).show_inf();
               }
               
               if (choice == "5")
               {
                    system("clear");
                    cout << "--Patient Information" << endl;
                    cout << " "                     << endl;
                    
                    string name;
                    string first_name;
                    string last_name;

                    cout << "Enter a Patient First name : ";
                    cin >> first_name;
                    
                    cout << "Enter last name : ";
                    cin >> last_name;

                    name = first_name + " " + last_name;

                    cout << " " << endl;
                    hospital.search_patient(name).show_inf();               
               }

               if (choice == "6")
               {
                    hospital.show_inf();
               }
               
               if (choice == "help")
               {
                    help();
                    sec_help();
               }

               if (choice == "7")
               {
                    system("clear");
                    cout << "Have a nice day ;)" << endl;
                    break;
               }
          }
          catch(const std::exception& e)
          {
               std::cerr << e.what() << '\n';
          }
     }

     return 0;
}
