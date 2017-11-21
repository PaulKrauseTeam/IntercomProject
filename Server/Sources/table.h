#include <string>
#include <vector>
#include <list>
#include "user.cpp"
using namespace std;

class table
{
   // private:
    public:
    table();
    list<user> lUsers;
    void includeUser(int id, int num,/* string mail,*/ int monEnter, int monExit,
                                                   int tueEnter, int tueExit,
                                                   int wedEnter, int wedExit,
                                                   int thuEnter, int thuExit,
                                                   int friEnter, int friExit,
                                                   int satEnter, int satExit,
                                                   int sunEnter, int sunExit, std::string name);
    void excludeUser(int id);
    void consultUser(int id);
    void alterUser(int id);
    void listUsers();
    //void setUserHistory();
    //int? getUserHistory();
};