#ifndef NUMBERBOOK_HPP
#define NUMBERBOOK_HPP

#include <fstream>
#include <iostream>
#include <vector>
using std::ifstream;
using std::istream;
using std::ofstream;
using std::ostream;
using std::string;
using std::vector;
namespace NumberBook {

class Account {
private:
  string name, email, number;

public:
  Account() = default;
  Account(string n, string e, string nu) : name(n), email(e), number(nu){};
  friend class FileHandler;
  friend class Book;
  friend ofstream &operator<<(ofstream &os, const Account &a);
  friend ifstream &operator>>(ifstream &is, Account &a);
  friend ostream &operator<<(ostream &os, const Account &a);
};

class FileHandler {
private:
  ofstream os;
  ifstream is;
  string file_name = "info.txt";

public:
  FileHandler() = default;
  friend class Book;
};

class Book {
private:
  vector<Account> vc;
  FileHandler fh;

public:
  Book() : vc(), fh(){};
  void add_account(Account &a);
  bool has_account(const Account &a);
  void list_all();
  void search_account(string name);
  void delete_account(string name);

  void read_file();
  void write_file();

  friend class Account;
};

ofstream &operator<<(ofstream &os, const Account &a);
ifstream &operator>>(ifstream &is, Account &a);
ostream &operator<<(ostream &os, const Account &a);
}; // namespace NumberBook

#endif // NUMBERBOOK_HPP