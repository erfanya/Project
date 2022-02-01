#include "backend.hpp"

#include <QDebug>
#include <iostream>

using namespace std;

bool Backend::add_doc(QString fname, QString lname,QString age, QString gender, QString phonenumber, QString spelization)
{
    int doc_age = age.toInt();

    if (doc_age < 18 || doc_age > 60)
    {
        return false;
    }

    string first_name = fname.toStdString();
    string last_name = lname.toStdString();

    string full_name = first_name + " " + last_name;

    string doc_gender = gender.toStdString();

    if (doc_gender == "Male" || doc_gender == "MALE" || doc_gender == "male")
    {
        doc_gender = "male";
    }
    else if(doc_gender == "Female" || doc_gender == "FEMALE" || doc_gender == "female")
    {
        doc_gender = "female";
    }
    else
    {
        return false;
    }

    string doc_phonenumber = phonenumber.toStdString();

    if (doc_phonenumber.length() != 11)
    {
        return false;
    }

    string doc_spelization = spelization.toStdString();

    if (doc_spelization == "General" || doc_spelization == "GENERAL" || doc_spelization == "general")
    {
        doc_spelization = "general";
    }
    else if(doc_spelization == "Expert" || doc_spelization == "EXPERT" || doc_spelization == "expert")
    {
        doc_spelization = "expert";

        if (hospital.get_manager_xp() < 20)
        {
            return false;
        }
    }
    else if(doc_spelization == "Surgeon" || doc_spelization == "SURGEON" || doc_spelization == "surgeon")
    {
        doc_spelization = "surgeon";

        if (hospital.get_manager_xp() < 50)
        {
            return false;
        }
    }
    else
    {
        return false;
    }

    hospital.create_doctor(full_name, doc_age, doc_gender, doc_phonenumber, doc_spelization);

    return true;
}

bool Backend::add_pat(QString fname, QString lname, QString age, QString gender, QString phonenumber, QString insurance, QString illness)
{
    int pat_age = age.toInt();

    if (pat_age < 1 || pat_age > 120)
    {
        return false;
    }

    string first_name = fname.toStdString();
    string last_name = lname.toStdString();

    string full_name = first_name + " " + last_name;

    string pat_gender = gender.toStdString();

    if (pat_gender == "Male" || pat_gender == "MALE" || pat_gender == "male")
    {
        pat_gender = "male";
    }
    else if(pat_gender == "Female" || pat_gender == "FEMALE" || pat_gender == "female")
    {
        pat_gender = "female";
    }
    else
    {
        return false;
    }

    string pat_phonenumber = phonenumber.toStdString();

    if (pat_phonenumber.length() != 11)
    {
        return false;
    }

    string pat_insurance = insurance.toStdString();

    if (pat_insurance == "YES" || pat_insurance == "Yes" || pat_insurance == "yes")
    {
        pat_insurance = "yes";
    }
    else if (pat_insurance == "NO" || pat_insurance == "No" || pat_insurance == "no")
    {
        pat_insurance = "no";
    }
    else
    {
        return false;
    }

    string pat_illness = illness.toStdString();

    if (pat_illness == "Surface" || pat_illness == "SURFACE" || pat_illness == "surface")
    {
        pat_illness = "surface";
    }
    else if(pat_illness == "Emergency" || pat_illness == "EMERGENCY" || pat_illness == "emergency")
    {
        pat_illness = "emergency";
    }
    else if(pat_illness == "Surgery" || pat_illness == "SURGERY" || pat_illness == "surgery")
    {
        pat_illness = "surgery";
    }
    else
    {
        return false;
    }

    hospital.create_patient(full_name, pat_age, pat_gender, pat_phonenumber, pat_insurance, pat_illness);

    return true;
}

bool Backend::setvisit(QString doc_fname, QString doc_lname, QString pat_fname, QString pat_lname)
{
    string doc_fullname = doc_fname.toStdString() + " " + doc_lname.toStdString();

    string pat_fullname = pat_fname.toStdString() + " " + pat_lname.toStdString();


    if (hospital.search_patient(pat_fullname).get_illness() == 0)
    {
        if(hospital.search_patient(pat_fullname).get_status() == 1)
        {
            hospital.decrease_manager_xp(5);
            return false;
        }

        if (hospital.search_doctor(doc_fullname).get_specialization() == 1)
        {
            if (get_manager_xp() >= 10)
            {
                hospital.decrease_manager_xp(10);
            }
            return false;
        }

        if (hospital.search_doctor(doc_fullname).get_specialization() == 2)
        {
            if (get_manager_xp() >= 20)
            {
                hospital.decrease_manager_xp(20);
            }
            return false;
        }

        hospital.search_patient(pat_fullname).set_status(Patient::Status::Cured);
        hospital.increase_manager_xp(10);

        if (hospital.search_patient(pat_fullname).get_insurance() == 0)
        {
            hospital.increase_hospital_money(200);
            return true;
        }

        if (hospital.search_patient(pat_fullname).get_insurance() == 1)
        {
            hospital.increase_hospital_money(100);
            return true;
        }
    }

    if (hospital.search_patient(pat_fullname).get_illness() == 1)
    {
        if(hospital.search_patient(pat_fullname).get_status() == 1)
        {
            hospital.decrease_manager_xp(5);
            return false;
        }

        if (hospital.search_doctor(doc_fullname).get_specialization() == 0)
        {
            if (get_manager_xp() >= 20)
            {
                hospital.decrease_manager_xp(20);
            }
            return false;
        }

        if (hospital.search_doctor(doc_fullname).get_specialization() == 2)
        {
            if (get_manager_xp() >= 10)
            {
                hospital.decrease_manager_xp(10);
            }
            return false;
        }

        hospital.search_patient(pat_fullname).set_status(Patient::Status::Cured);
        hospital.increase_manager_xp(20);

        if (hospital.search_patient(pat_fullname).get_insurance() == 0)
        {
            hospital.increase_hospital_money(500);
            return true;
        }

        if (hospital.search_patient(pat_fullname).get_insurance() == 1)
        {
            hospital.increase_hospital_money(250);
            return true;
        }
    }

    if (hospital.search_patient(pat_fullname).get_illness() == 2)
    {
        if(hospital.search_patient(pat_fullname).get_status() == 1)
        {
            hospital.decrease_manager_xp(5);
            return false;
        }

        if (hospital.search_doctor(doc_fullname).get_specialization() == 0)
        {
            if (get_manager_xp() >= 30)
            {
                hospital.decrease_manager_xp(30);
            }
            return false;
        }

        if (hospital.search_doctor(doc_fullname).get_specialization() == 1)
        {
            if (get_manager_xp() >= 20)
            {
                hospital.decrease_manager_xp(20);
            }
            return false;
        }

        hospital.search_patient(pat_fullname).set_status(Patient::Status::Cured);
        hospital.increase_manager_xp(30);

        if (hospital.search_patient(pat_fullname).get_insurance() == 0)
        {
            hospital.increase_hospital_money(1000);
            return true;
        }

        if (hospital.search_patient(pat_fullname).get_insurance() == 1)
        {
            hospital.increase_hospital_money(500);
            return true;
        }
    }
    return  false;
}

QString Backend::get_doc_name(QString fname, QString lname)
{
    string doc_name = fname.toStdString() + " " + lname.toStdString();

    return QString::fromStdString(hospital.search_doctor(doc_name).get_name());
}

int Backend::get_doc_age(QString fname, QString lname)
{
    string doc_name = fname.toStdString() + " " + lname.toStdString();

    return hospital.search_doctor(doc_name).get_age();
}

QString Backend::get_doc_gender(QString fname, QString lname)
{
    string doc_name = fname.toStdString() + " " + lname.toStdString();

    QString doc_gen;

    switch (hospital.search_doctor(doc_name).get_gender()) {
    case 0:
        doc_gen = "male";
        break;
    case 1:
        doc_gen = "female";
        break;
    }

    return doc_gen;
}

QString Backend::get_doc_phonenumber(QString fname, QString lname)
{
    string doc_name = fname.toStdString() + " " + lname.toStdString();

    return QString::fromStdString(hospital.search_doctor(doc_name).get_phone());
}

QString Backend::get_doc_spelization(QString fname, QString lname)
{
    string doc_name = fname.toStdString() + " " + lname.toStdString();

    QString doc_spe;

    switch (hospital.search_doctor(doc_name).get_specialization()) {
    case 0:
        doc_spe = "general";
        break;
    case 1:
        doc_spe = "expert";
        break;
    case 2:
        doc_spe = "surgeon";
        break;
    }

    return doc_spe;
}

QString Backend::get_pat_name(QString fname, QString lname)
{
    string pat_name = fname.toStdString() + " " + lname.toStdString();

    return QString::fromStdString(hospital.search_patient(pat_name).get_name());
}

int Backend::get_pat_age(QString fname, QString lname)
{
    string pat_name = fname.toStdString() + " " + lname.toStdString();

    return hospital.search_patient(pat_name).get_age();
}

QString Backend::get_pat_gender(QString fname, QString lname)
{
    string pat_name = fname.toStdString() + " " + lname.toStdString();

    QString pat_gen;

    switch (hospital.search_patient(pat_name).get_gender()) {
    case 0:
        pat_gen = "male";
        break;
    case 1:
        pat_gen = "female";
        break;
    }

    return pat_gen;
}

QString Backend::get_pat_phonenumber(QString fname, QString lname)
{
    string pat_name = fname.toStdString() + " " + lname.toStdString();

    return QString::fromStdString(hospital.search_patient(pat_name).get_phone());
}

QString Backend::get_pat_insurance(QString fname, QString lname)
{
    string pat_name = fname.toStdString() + " " + lname.toStdString();

    QString pat_ins;

    switch (hospital.search_patient(pat_name).get_insurance()) {
    case 0:
        pat_ins = "no";
        break;
    case 1:
        pat_ins = "yes";
        break;
    }

    return pat_ins;
}

QString Backend::get_pat_illness(QString fname, QString lname)
{
    string pat_name = fname.toStdString() + " " + lname.toStdString();

    QString pat_ill;

    switch (hospital.search_patient(pat_name).get_illness()) {
    case 0:
        pat_ill = "surface";
        break;
    case 1:
        pat_ill = "emergency";
        break;
    case 2:
        pat_ill = "surgery";
        break;
    }

    return pat_ill;
}

QString Backend::get_pat_status(QString fname, QString lname)
{
    string pat_name = fname.toStdString() + " " + lname.toStdString();

    QString pat_stat;

    switch (hospital.search_patient(pat_name).get_status()) {
    case 0:
        pat_stat = "Waiting";
        break;
    case 1:
        pat_stat = "Cured";
        break;
    }

    return pat_stat;
}

QString Backend::get_pat_fee(QString fname, QString lname)
{
    string pat_name = fname.toStdString() + " " + lname.toStdString();

    return QString::fromStdString(hospital.search_patient(pat_name).get_fee());
}

int Backend::get_doc_numbers()
{
    return hospital.get_doctors_size();
}

int Backend::get_pat_numbers()
{
    return hospital.get_patients_size();
}

int Backend::get_manager_xp()
{
    return hospital.get_manager_xp();
}

int Backend::get_hos_money()
{
    return hospital.get_hospital_money();
}
