#ifndef BACKEND_HPP
#define BACKEND_HPP

#include "../Hospital Management/header/Hospital.hpp"
#include <vector>
#include <QDebug>
#include <QObject>
#include <QString>
#include <QtQuick>


class Backend : public QObject
{
    Q_OBJECT

private:
    Hospital hospital;

public:


signals:

public slots:
    bool add_doc(QString fname, QString lname, QString age, QString gender, QString phonenumber, QString spelization);

    bool add_pat(QString fname, QString lname, QString age, QString gender, QString phonenumber, QString insurance, QString illness);

    bool setvisit(QString doc_fname, QString doc_lname, QString pat_fname, QString pat_lname);

    QString get_doc_name(QString fname, QString lname);
    int get_doc_age(QString fname, QString lname);
    QString get_doc_gender(QString fname, QString lname);
    QString get_doc_phonenumber(QString fname, QString lname);
    QString get_doc_spelization(QString fname, QString lname);

    QString get_pat_name(QString fname, QString lname);
    int get_pat_age(QString fname, QString lname);
    QString get_pat_gender(QString fname, QString lname);
    QString get_pat_phonenumber(QString fname, QString lname);
    QString get_pat_insurance(QString fname, QString lname);
    QString get_pat_illness(QString fname, QString lname);
    QString get_pat_status(QString fname, QString lname);
    QString get_pat_fee(QString fname, QString lname);

    int get_doc_numbers();
    int get_pat_numbers();
    int get_manager_xp();
    int get_hos_money();
};

#endif // BACKEND_HPP
