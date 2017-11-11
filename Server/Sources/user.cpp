#include "Aluno.cpp"
#include "ClockCalendar.cpp"
#include <string>
#include <iostream>
using namespace std;

void user::setId(int id_par)
{
    id = id_par;
}
void user::setContact(int contact_par)
{
    contact = contact_par;
}
void user::setPeriod(int period_par)
{
    period = period_par;
}
void user::setName(string name_par)
{
    name = name_par;
}

int user::getId()
{
    return id;
}
int user::getContact()
{
    return contact;
}
int user::getPeriod()
{
    return period;
}
std:string user::getName()
{
    return name;
}