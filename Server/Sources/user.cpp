#include "user.h"
#include <string.h>
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
//Set period in and out
void user::setMonEnter(int monEnter_par)
{
	monEnter = monEnter_par;
}
void user::setMonExit(int monExit_par)
{
	monExit = monExit_par;
}
void user::setTueEnter(int tueEnter_par)
{
	tueEnter = tueEnter_par;
}
void user::setTueExit(int tueExit_par)
{
	tueExit = tueExit_par;
}
void user::setWedEnter(int wedEnter_par)
{
	wedEnter = wedEnter_par;
}
void user::setWedExit(int wedExit_par)
{
	wedExit = wedExit_par;
}
void user::setThuEnter(int thuEnter_par)
{
	thuEnter = thuEnter_par;
}
void user::setThuExit(int thuExit_par)
{
	thuExit = thuExit_par;
}
void user::setFriEnter(int friEnter_par)
{
	friEnter = friEnter_par;
}
void user::setFriExit(int friExit_par)
{
	friExit = friExit_par;
}
void user::setSatEnter(int satEnter_par)
{
	satEnter = satEnter_par;
}
void user::setSatExit(int satExit_par)
{
	satExit = satExit_par;
}
void user::setSunEnter(int sunEnter_par)
{
	sunEnter = sunEnter_par;
}
void user::setSunExit(int sunExit_par)
{
	sunExit = sunExit_par;
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
//Get period in and out
int user::getMonEnter()
{
	return monEnter;
}
int user::getMonExit()
{
	return monExit;
}
int user::getTueEnter()
{
	return tueEnter;
}
int user::getTueExit()
{
	return tueExit;
}
int user::getWedEnter()
{
	return wedEnter;
}
int user::getWedExit()
{
	return wedExit;
}
int user::getThuEnter()
{
	return thuEnter;
}
int user::getThuExit()
{
	return thuExit;
}
int user::getFriEnter()
{
	return friEnter;
}
int user::getFriExit()
{
	return friExit;
}
int user::getSatEnter()
{
	return satEnter;
}
int user::getSatExit()
{
	return satExit;
}
int user::getSunEnter()
{
	return sunEnter;
}
int user::getSunExit()
{
	return sunExit;
}
string user::getName()
{
    return name;
}