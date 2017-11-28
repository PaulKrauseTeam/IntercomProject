#include <ctime>
#include <iostream>
#include <pqxx/pqxx>
#include <string>
#include <typeinfo>

using namespace std;

string getUserTime(string str) {
    string user_time;

    pqxx::connection c("dbname=intercomdb user=guilherme-fonseca");
    pqxx::work txn(c);

    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

    const string DAY[] = {"sun", "mon", "tue"  , "wed", "thu", "fri", "sat"};

    pqxx::result en = txn.exec(
      "SELECT * "
      "FROM entry_permission "
      "WHERE user_id = " + str
    );

    pqxx::result ex = txn.exec(
      "SELECT * "
      "FROM exit_permission "
      "WHERE user_id = " + str
    );

    for (pqxx::result::const_iterator c = en.begin(); c != en.end(); ++c) {
      user_time += c[DAY[now->tm_wday]].as<string>();
    }

    for (pqxx::result::const_iterator c = ex.begin(); c != ex.end(); ++c) {
      user_time += ", ";
      user_time += c[DAY[now->tm_wday]].as<string>();
    }

    // cout << user_time << endl;

    return user_time;
}

int main(int, char* argv[]) {
  cout << getUserTime(argv[1]) << endl;

  return 0;
}
