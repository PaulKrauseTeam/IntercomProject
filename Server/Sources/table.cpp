#include "table.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

table::table()
{
	list<user> lUsers;
}
//Metodo para a listagem dos users da list
void table::listUsers()
{
    list<user>::iterator it;
	it = lUsers.begin();
	while(it != lUsers.end())
	{
 	   cout << "\nName: " << it ->getName() << endl;
 	   cout << "User id: " << it->getId() << endl;
       cout << "Phone number: " << it->getNum() << endl;
       cout << "E-mail" << it->getMail() << endl;
       cout << "Period: " << it->getPeriod() << endl;
       it++;	
	}
	
}
//Metodo para a inclusao de users

void table::includeUser(int id, int num, string mail, int period, string name)
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
		it->setName(name);
		it->setId(id);
		it->setNum(num);
		it->setMail(mail);
		it->setPeriod(period);
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
	
	while(it != lUsers.end())
	{
		if (id == it->getId())
		{
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
            cout << "Name: " << it->getName() << endl;
            cout << "Phone number: " << it->getNum() << endl;
            cout << "E-mail: " << it->getMail() <<endl;
            cout << "Period: " << it->getPeriod() << endl;
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
	int period_new;
	int num_new;
	string mail_new;
	
	while(it != lUsers.end())
	{
		if (id == it->getId())
		{
            found = true;
            cout << "User of name: " << it -> getName() << endl;
            cout << "New period: "; cin >> period_new;
            cout << "New phone number: "; cin >> num_new;
            cout << "New e-mail: ";
            cin.ignore();
            getline(cin,mail_new);
            it->setNum(num_new);
            it->setMail(mail_new);
            it->setPeriod(period_new);
		}
		it++;
	}
	if (!found)
	{
		cout << "User not found! Try again.\n\n";	
	} 
		
}