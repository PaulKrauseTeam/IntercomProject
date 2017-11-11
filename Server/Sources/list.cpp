#include "list.cpp"
#include "ClockCalendar.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

list::list()
{
	list<user> lUsers;
	ClockCalendar c;
}
//Metodo para a listagem dos users da list
void list::listUsers()
{
    list<user>::iterator it;
	it = lUsers.begin();
	while(it != lUsers.end())
	{
 	   cout << "User Name: " << it->getName() << endl << endl;
       cout << "User Id: " << it->getId() << endl;
       cout << "User Contact: " << it->getContact() << endl;
       cout << "User Period: " << it->getPeriod() << endl;
       it->readClock();
       it->readCalendar(); 
	   it++;	
	}
	
}
//Metodo para a inclusao de users

void list::includeUser(int id, int contact, int period, string name)
{
	list<user>::iterator it;
	it = lUsers.begin();
	bool termina = false;
	
	while(it != lUsers.end())
	{
		if (id == it->getId())
		{
			cout << "Repeated Id! Error!" << endl;
			termina = true;
		}
		it++;
	}
		
	if (!termina)
	{
		it->setId(id);
		it->setContact(contact);
		it->setPeriod(period);
		it->setName(name);
		lUsers.push_front(*it);
		cout << "User registered with sucess!" << endl;
		c.advance();
	}
    
}
//Metodo para a exclusao de um user. Caso a matricula digitada for correta, libera-se a escrita atraves
//do vetor de controle 'valido'
void list::excludeUser(int id)
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
//Metodo para consulta de apenas um id
void list::consultUser(int id)
{
 	list<user>::iterator it;
	it = lUsers.begin();
	bool found = false;
	
	while(it != lUsers.end())
	{
		if (id == it->getid())
		{
            found = true;
            cout << "Name: " << it->getName() << endl;
            cout << "Period: " << it->getPeriod() << endl;
            cout << "Contact: " << it->getContact() << endl << endl;
    	}
		it++;
	}
	if (!found)
	{
		cout << "User not found! Try again.\n\n";	
	} 
	
	
}
//Alteracao do período de um determinado usuario
void list::alterUser(int id)
{
    list<user>::iterator it;
	it = lUsers.begin();
	bool found = false;
	int period_new;
	
	while(it != lUsers.end())
	{
		if (id == it->getid())
		{
            found = true;
            cout << "Type new period "; cin >> period_new;
            it->setPeriod(period_new);
        }
		it++;
	}
	if (!found)
	{
		cout << "User not found! Try again.\n\n";	
	} 
		
}