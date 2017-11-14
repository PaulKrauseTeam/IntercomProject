#include <string.h>
#include <iostream>
using namespace std;

class user
{
     private:
     int id;
     int num;
     string mail;
     //Days:
     int monEnter;
     int monExit;
     int tueEnter;
     int tueExit;
     int wedEnter;
     int wedExit;
     int thuEnter;
     int thuExit;
     int friEnter;
     int friExit;
     int satEnter;
     int satExit;
     int sunEnter;
     int sunExit;

     string name;
     public:
     void setId(int id);
     void setNum(int num);
     void setMail(string mail);
     //Set period in and out
     void setMonEnter(int monEnter);
     void setMonExit(int monExit);
     void setTueEnter(int tueEnter);
     void setTueExit(int tueExit);
     void setWedEnter(int wedEnter);
     void setWedExit(int wedExit);
     void setThuEnter(int thuEnter);
     void setThuExit(int thuExit);
     void setFriEnter(int friEnter);
     void setFriExit(int friExit);
     void setSatEnter(int satEnter);
     void setSatExit(int satExit);
     void setSunEnter(int sunEnter);
     void setSunExit(int sunExit);
     
     void setName(string name);
     int getId();
     int getNum();
     string getMail();
     //Get period in and out
     int getMonEnter();
     int getMonExit();
     int getTueEnter();
     int getTueExit();
     int getWedEnter();
     int getWedExit();
     int getThuEnter();
     int getThuExit();
     int getFriEnter();
     int getFriExit();
     int getSatEnter();
     int getSatExit();
     int getSunEnter();
     int getSunExit();
     
     string getName();
};