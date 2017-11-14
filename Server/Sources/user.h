#include <string>
#include <iostream>
using namespace std;

class user
{
     private:
     int id;
     int num;
     string mail;
     int period;
     string name;
     public:
     void setId(int id);
     void setNum(int num);
     void setMail(string mail);
     void setPeriod(int period);
     void setName(string name);
     int getId();
     int getNum();
     string getMail();
     int getPeriod();
	 string getName();
};