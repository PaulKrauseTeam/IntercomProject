//#include "user.cpp"
#include "table.cpp"
#include <string>
//#include <vector>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	bool Exit = false;
	int option, id;
	int num;
    int monEnter, monExit;
    int tueEnter, tueExit;
    int wedEnter, wedExit;
    int thuEnter, thuExit;
    int friEnter, friExit;
    int satEnter, satExit;
    int sunEnter, sunExit;
	string name;
    string mail;
	table regUser;
	cout << "Program for registration of users of the room - EEL 510232 - UFSC 2017";
    do
     {
         //Mostra todas as opções
         cout << "\n1. Register user" << endl;
         cout << "2. Consult user" << endl;
         cout << "3. List users" << endl;
         cout << "4. Exclude user" << endl;
         cout << "5. Alter user" << endl;
         cout << "6. Exit" << endl;
         cout << "Type the desired option: ";
         cin >> option;
         //Switch para direcionar a escolha aos metodos da classe CadAlunos
         switch (option)
         {
             case 1:
                 cout << "\nType the name: ";
                 cin.ignore();
                 getline(cin,name);
                 cout << "Type the Id: "; cin >> id;
                 cout << "Type the phone number: "; cin >> num;
                 cout << "Type the e-mail: "; cin >> mail;
                 //cin.ignore();
                 //getline(cin,mail);
                 cout << "Type the entry time of monday: "; cin >> monEnter;
                 cout << "Type the exit time of monday: "; cin >> monExit;
                 cout << "Type the entry time of tuesday: "; cin >> tueEnter;
                 cout << "Type the exit time of tuesday: "; cin >> tueExit;
                 cout << "Type the entry time of wednesday: "; cin >> wedEnter;
                 cout << "Type the exit time of wednesday: "; cin >> wedExit;
                 cout << "Type the entry time of thursday: "; cin >> thuEnter;
                 cout << "Type the exit time of thursday: "; cin >> thuExit;
                 cout << "Type the entry time of friday: "; cin >> friEnter;
                 cout << "Type the exit time of friday: "; cin >> friExit;
                 cout << "Type the entry time of saturday: "; cin >> satEnter;
                 cout << "Type the exit time of saturday: "; cin >> satExit;
                 cout << "Type the entry time of sunday: "; cin >> friEnter;
                 cout << "Type the exit time of sunday: "; cin >> friExit;
                 regUser.includeUser(id,num,mail, monEnter, monExit,
                                                  tueEnter, tueExit,
                                                  wedEnter, wedExit,
                                                  thuEnter, thuExit,
                                                  friEnter, friExit,
                                                  satEnter, satExit,
                                                  sunEnter, sunExit, name);
                 break;
             case 2:
                cout << "\nType the Id of the user you wish to consult: "; cin >> id;
                regUser.consultUser(id);
                break;
             case 3:
                cout << "\nList users option, listing:\n";
                regUser.listUsers();
                break;
             case 4:
                cout << "\nType the Id of the user you wish to exclude: "; cin >> id;
                regUser.excludeUser(id);
                break;
             case 5:
                cout << "\nType the Id of the user you wish to alter: "; cin >> id;
                regUser.alterUser(id);
                break;
             case 6:
                Exit = true;
                break;
             default:
                cout << "\nThe chosen option doesn't exist! Try again! \n\n";
         }
     } while(!Exit);
   return 0;
}
