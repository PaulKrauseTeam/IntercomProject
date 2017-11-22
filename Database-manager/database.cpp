#include <iostream>
#include <pqxx/pqxx>

int main(int, char *argv[])
{
  pqxx::connection c("dbname=intercom user=guilherme-fonseca");
  pqxx::work txn(c);

  pqxx::result r = txn.exec(
    "SELECT * "
    "FROM users "
    // "WHERE name =" + txn.quote(argv[1]));

    if (r.size() != 1)
  {
    std::cerr
      << "Expected 1 user with name " << argv[1] << ", "
      << "but found " << r.size() << std::endl;
    return 1;
  }

  int id = r[0][0].as<int>();
  std::cout << "Updating employee #" << id << std::endl;
  std::cout << "Whole String" << r[1][0] << std::endl;



  txn.exec(
    "UPDATE users "
    "SET status = false "
    "WHERE id = " + txn.quote(id));

  txn.commit();
}
