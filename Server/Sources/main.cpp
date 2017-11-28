#include "table.cpp"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>


using namespace std;

int main()
{
	bool Exit = false;
	int option, id;
	int num, status;
    int monEnter, monExit;
    int tueEnter, tueExit;
    int wedEnter, wedExit;
    int thuEnter, thuExit;
    int friEnter, friExit;
    int satEnter, satExit;
    int sunEnter, sunExit;
    stringstream sendUser;
    stringstream sendEnter;
    stringstream sendExit;


	table regUser;
	cout << "Program for registration of users of the room - EEL 510232 - UFSC 2017";
    do
     {
         //Show all options
         cout << "\n1. Register user" << endl;
         cout << "2. Consult user" << endl;
         cout << "3. List users" << endl;
         cout << "4. Exclude user" << endl;
         cout << "5. Alter user" << endl;
         cout << "6. Exit" << endl;
         cout << "Type the desired option: ";
         cin >> option;

         //Switch to chose between the options
         switch (option)
         {
             case 1:

                 cout << "\nType the Id: "; cin >> id;
                 cout << "Type the phone number: "; cin >> num;
                 cout << "Type the user's status (default 0): "; cin >> status;
                 cout << "\nNext section is the period\nEnter all like in the example:\n13h30 = 1330" << endl;
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
                 cout << "Type the entry time of sunday: "; cin >> sunEnter;
                 cout << "Type the exit time of sunday: "; cin >> sunExit;

                 regUser.includeUser(id,num, status, monEnter, monExit,
                                                     tueEnter, tueExit,
                                                     wedEnter, wedExit,
                                                     thuEnter, thuExit,
                                                     friEnter, friExit,
                                                     satEnter, satExit,
                                                     sunEnter, sunExit);
                 //String a ser enviada: sendUser.str()
                 sendUser<<id<<","<<num<<","<<status<<",";
                 sendEnter<<monEnter<<","<<tueEnter<<","<<wedEnter<<","<<thuEnter<<","
                          <<friEnter<<","<<satEnter<<","<<sunEnter<<",";
                 sendExit<<monExit<<","<<tueExit<<","<<wedExit<<","<<thuExit<<","
                         <<friExit<<","<<satExit<<","<<sunExit<<",";
                 cout << sendUser.str() << endl;
                 cout << sendEnter.str() << endl;
                 cout << sendExit.str() << endl;

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
     } while(Exit==0);
   return 0;
}
