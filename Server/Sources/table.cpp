#include "table.h"
#include <iostream>
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
 	   cout << "User id: " << it->getId() << endl;
       cout << "Contact: " << it->getContact() << endl;
       cout << "Period: " << it->getPeriod() << endl;
       it++;	
	}
	
}
//Metodo para a inclusao de users

void table::includeUser(int id, int contact, int period)
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
		it->setContact(contact);
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
            cout << "Contact: " << it->getContact() << endl;
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
	int contact_new;
	
	while(it != lUsers.end())
	{
		if (id == it->getId())
		{
            found = true;
            cout << "New period: "; cin >> period_new;
            cout << "\nNew contact: "; cin >> contact_new;
            it->setContact(contact_new);
            it->setPeriod(period_new);
		}
		it++;
	}
	if (!found)
	{
		cout << "User not found! Try again.\n\n";	
	} 
		
}