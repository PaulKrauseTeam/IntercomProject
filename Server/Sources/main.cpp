//#include "user.cpp"
#include "table.cpp"
//#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	bool Exit = false;
	int option, id;
	int period, contact;
	//std:string name;
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
                 cout << "\nType the Id: "; cin >> id;
                 cout << "Type the period: "; cin >> period;
                 cout << "Type the contact: "; cin >> contact;
                 /*cout << "Type the name: ";
                 getline (cin, name);
                 */regUser.includeUser(id,period,contact/*,name*/);
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
