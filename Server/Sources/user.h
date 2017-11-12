#include <string>
#include <iostream>
using namespace std;

class user
{
     private:
     int id;
     int contact;
     int period;
  //   std:string name;
     public:
     void setId(int id);
     void setContact(int contact);
     void setPeriod(int period);
    // void setName(std:string name);
     int getId();
     int getContact();
     int getPeriod();
//	std:string getName();
};