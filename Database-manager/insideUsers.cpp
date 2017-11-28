#include <iostream>
#include <pqxx/pqxx>
#include <string>

using namespace std;

string insideUsers() {
  int lin;
  string users;

  pqxx::connection c("dbname=intercom user=guilherme-fonseca");
  pqxx::work txn(c);

  pqxx::result r = txn.exec(
    "SELECT id, phone_number "
    "FROM users "
    "WHERE status = '1'"
  );

  if (r.size() == 0) {
    cerr << "/* No user inside the room in the moment! */" << endl
              << "/* Please comeback later! */" << endl;
    return 0;
  }


  for (pqxx::result::const_iterator c = r.begin(); c != r.end(); ++c) {
    users += c[0].as<string>();
    users += ", ";
    users += c[1].as<string>();
    users += ", ";
  }


  cout << users << endl;

  return users;
}

int main() {
  insideUsers();

  return 0;
}
