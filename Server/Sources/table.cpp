#include "table.h"
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <string>
#include "newUser.cpp"
#include "newEntry.cpp"
#include "newExit.cpp"
#include "deleteUser.cpp"
#include "deleteEntry.cpp"
#include "deleteExit.cpp"
using namespace std;

table::table()
{
	list<user> lUsers;
}
//Metodo para a listagem dos users da table
void table::listUsers()
{
    list<user>::iterator it;
	it = lUsers.begin();
	while(it != lUsers.end())
	{
 	   cout << "\nUser id: " << it->getId() << endl;
       cout << "Phone number: " << it->getNum() << endl;
       cout << "Entrance on Monday: " << it->getMonEnter() << endl;
       cout << "Exit on Monday: " << it->getMonExit() << endl;
       cout << "Entrance on Tuesday: " << it->getTueEnter() << endl;
       cout << "Exit on Tuesday: " << it->getTueExit() << endl;
       cout << "Entrance on Wednesday: " << it->getWedEnter() << endl;
       cout << "Exit on Wednesday: " << it->getWedExit() << endl;
       cout << "Entrance on Thursday: " << it->getThuEnter() << endl;
       cout << "Exit on Thursday: " << it->getThuExit() << endl;
       cout << "Entrance on Friday: " << it->getFriEnter() << endl;
       cout << "Exit on Friday: " << it->getFriExit() << endl;
       cout << "Entrance on Saturday: " << it->getSatEnter() << endl;
       cout << "Exit on Saturday: " << it->getSatExit() << endl;
       cout << "Entrance on Sunday: " << it->getSunEnter() << endl;
       cout << "Exit on Sunday: " << it->getSunExit() << endl;
       it++;
	}
}
//Metodo para a inclusao de users

void table::includeUser(int id, int num, int monEnter, int monExit,
                                         int tueEnter, int tueExit,
                                         int wedEnter, int wedExit,
                                         int thuEnter, int thuExit,
                                         int friEnter, int friExit,
                                         int satEnter, int satExit,
                                         int sunEnter, int sunExit)
{
	list<user>::iterator it;
	it = lUsers.begin();
	bool termina = false;

	while(it != lUsers.end())
	{
		if (id == it->getId())
		{
			cout << "Doubled Id! Error" << endl;
			termina = true;
		}
		it++;
	}

	if (!termina)
	{
		it->setId(id);
		it->setNum(num);
		it->setMonEnter(monEnter);
		it->setMonExit(monExit);
		it->setTueEnter(tueEnter);
		it->setTueExit(tueExit);
		it->setWedEnter(wedEnter);
		it->setWedExit(wedExit);
		it->setThuEnter(thuEnter);
		it->setThuExit(thuExit);
		it->setFriEnter(friEnter);
		it->setFriExit(friExit);
		it->setSatEnter(satEnter);
		it->setSatExit(satExit);
		it->setSunEnter(sunEnter);
		it->setSunExit(sunExit);
		lUsers.push_front(*it);
		cout << "User registered!" << endl;
	}
}
//Exclusao do user
void table::excludeUser(int id)
{
	list<user>::iterator it;
	it = lUsers.begin();
	bool found = false;
	stringstream sendUser;

	while(it != lUsers.end())
	{
		if (id == it->getId())
		{
			userId<<id;
			cout << sendUser.str() << endl;
			lUsers.erase(it);
            cout << "User excluded!\n\n";
            found = true;
            break;
		}
		it++;
	}
	if (!found)
	{
		cout << "User not found! Try again.\n\n";
	}

  cout << delete_entry(userId.str()) << endl;
  cout << delete_exit(userId.str()) << endl;
  cout << delete_user(userId.str()) << endl;

}
//Consultar por id
void table::consultUser(int id)
{
 	list<user>::iterator it;
	it = lUsers.begin();
	bool found = false;

	while(it != lUsers.end())
	{
		if (id == it->getId())
		{
            found = true;
            cout << "Phone number: " << it->getNum() << endl;
            cout << "Entrance on Monday: " << it->getMonEnter() << endl;
            cout << "Exit on Monday: " << it->getMonExit() << endl;
            cout << "Entrance on Tuesday: " << it->getTueEnter() << endl;
            cout << "Exit on Tuesday: " << it->getTueExit() << endl;
            cout << "Entrance on Wednesday: " << it->getWedEnter() << endl;
            cout << "Exit on Wednesday: " << it->getWedExit() << endl;
            cout << "Entrance on Thursday: " << it->getThuEnter() << endl;
            cout << "Exit on Thursday: " << it->getThuExit() << endl;
            cout << "Entrance on Friday: " << it->getFriEnter() << endl;
            cout << "Exit on Friday: " << it->getFriExit() << endl;
            cout << "Entrance on Saturday: " << it->getSatEnter() << endl;
            cout << "Exit on Saturday: " << it->getSatExit() << endl;
            cout << "Entrance on Sunday: " << it->getSunEnter() << endl;
            cout << "Exit on Sunday: " << it->getSunExit() << endl;

        }
		it++;
	}
	if (!found)
	{
		cout << "User not found! Try again.\n\n";
	}
}
//Alteracao do periodo e do contato
void table::alterUser(int id)
{
    list<user>::iterator it;
	it = lUsers.begin();
	bool found = false;
	int monEnter_new, monExit_new;
	int tueEnter_new, tueExit_new;
	int wedEnter_new, wedExit_new;
	int thuEnter_new, thuExit_new;
	int friEnter_new, friExit_new;
	int satEnter_new, satExit_new;
	int sunEnter_new, sunExit_new;
	int num_new;
	stringstream sendUser;
  stringstream sendEnter;
  stringstream sendExit;
  stringstream userId;


	while(it != lUsers.end())
	{
		if (id == it->getId())
		{
            found = true;
            cout << "New entrance on monday: "; cin >> monEnter_new;
            cout << "New exit on monday: "; cin >> monExit_new;
            cout << "New entrance on tuesday: "; cin >> tueEnter_new;
            cout << "New exit on tuesday: "; cin >> tueExit_new;
            cout << "New entrance on wednesday: "; cin >> wedEnter_new;
            cout << "New exit on wednesday: "; cin >> wedExit_new;
            cout << "New entrance on thursday: "; cin >> thuEnter_new;
            cout << "New exit on thursday: "; cin >> thuExit_new;
            cout << "New entrance on friday: "; cin >> friEnter_new;
            cout << "New exit on friday: "; cin >> friExit_new;
            cout << "New entrance on saturday: "; cin >> satEnter_new;
            cout << "New exit on saturday: "; cin >> satExit_new;
            cout << "New entrance on sunday: "; cin >> sunEnter_new;
            cout << "New exit on sunday: "; cin >> sunExit_new;
            cout << "New phone number: "; cin >> num_new;

            it->setNum(num_new);
            it->setMonEnter(monEnter_new);
            it->setMonExit(monExit_new);
            it->setTueEnter(tueEnter_new);
            it->setTueExit(tueExit_new);
            it->setWedEnter(wedEnter_new);
            it->setWedExit(wedExit_new);
            it->setThuEnter(thuEnter_new);
            it->setThuExit(thuExit_new);
            it->setFriEnter(friEnter_new);
            it->setFriExit(friExit_new);
            it->setSatEnter(satEnter_new);
            it->setSatExit(satExit_new);
            it->setSunEnter(sunEnter_new);
            it->setSunExit(sunExit_new);

            userId<<id;
            sendUser<<id<<", "<<num_new;
            sendEnter<<id<<", "<<monEnter_new<<", "<<tueEnter_new<<", "
            		 <<wedEnter_new<<", "<<thuEnter_new<<", "
                     <<friEnter_new<<", "<<satEnter_new<<", "<<sunEnter_new;
            sendExit<<id<<", "<<monExit_new<<", "<<tueExit_new<<", "
            		<<wedExit_new<<", "<<thuExit_new<<", "
                    <<friExit_new<<", "<<satExit_new<<", "<<sunExit_new;
            cout << sendUser.str() << endl;
            cout << sendEnter.str() << endl;
            cout << sendExit.str() << endl;

            cout << delete_entry(userId.str()) << endl;
            cout << delete_exit(userId.str()) << endl;
            cout << delete_user(userId.str()) << endl;

            cout << new_entry(sendEnter.str()) << endl;
            cout << new_exit(sendExit.str()) << endl;
            cout << new_user(sendUser.str()) << endl;

		}
		it++;
	}
	if (!found)
	{
		cout << "User not found! Try again.\n\n";
	}

}
