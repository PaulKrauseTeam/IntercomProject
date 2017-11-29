#include <string>
#include <stdlib.h>
#include <iostream>
#include <pqxx/pqxx>

using namespace std;

bool new_entry(string str) {
  pqxx::connection c("dbname=intercomdb user=guilherme-fonseca");
  pqxx::work txn(c);

  try
  {
    pqxx::result r = txn.exec(
      "INSERT INTO entry_permission (user_id, mon, tue, wed, thu, fri, sat, sun) "
      "VALUES (" + str + ")"
    );
    txn.commit();

    return true;
  }
  catch (const std::exception &e)
  {
    cout << e.what() << std::endl;

    return false;
  }
}
