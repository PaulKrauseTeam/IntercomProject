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
    void includeUser(int id, int num, string mail, int period, string name);
    void excludeUser(int id);
    void consultUser(int id);
    void alterUser(int id);
    void listUsers();
    //void setUserHistory();
    //int? getUserHistory();
};