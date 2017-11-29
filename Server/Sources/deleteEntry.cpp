#include <string>
#include <stdlib.h>
#include <iostream>
#include <pqxx/pqxx>

using namespace std;

bool delete_entry(string str) {
  pqxx::connection c("dbname=intercomdb user=guilherme-fonseca");
  pqxx::work txn(c);

  try
  {
    pqxx::result r = txn.exec(
      "DELETE FROM entry_permission "
      "WHERE user_id = " + str
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
