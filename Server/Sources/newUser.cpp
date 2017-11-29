#include <string>
#include <stdlib.h>
#include <iostream>
#include <pqxx/pqxx>

using namespace std;

bool new_user(string str) {
  pqxx::connection c("dbname=intercomdb user=guilherme-fonseca");
  pqxx::work txn(c);

  try
  {
    pqxx::result r = txn.exec(
      "INSERT INTO users (id, phone_number, status) "
      "VALUES (" + str + ", false)"
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
