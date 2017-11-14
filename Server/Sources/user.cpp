#include "user.h"
#include <string>
#include <iostream>
using namespace std;

void user::setId(int id_par)
{
    id = id_par;
}
void user::setNum(int num_par)
{
    num = num_par;
}
void user::setMail(string mail_par)
{
	mail = mail_par;
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
int user::getNum()
{
    return num;
}
string user::getMail()
{
	return mail;
}
int user::getPeriod()
{
    return period;
}
string user::getName()
{
    return name;
}