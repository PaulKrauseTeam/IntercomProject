#include <string>
#include <vector>
#include<list>
#include "user.h"
using namespace std;

class list
{
   // private:
    public:
    list();
    list<user> lUsers;
    void includeUser(int id, int contact, int period, string name);
    void excludeUser(int id);
    void consultUser(int id);
    void alterUser(int id);
    void listUsers();
    //void setUserHistory();
    //int? getUserHistory();
};