#include "NumberBook.hpp"
#include <fstream>
#include <iostream>
using std::cout;
using std::endl;
using std::ofstream;
using std::string;

void NumberBook::Book::add_account(Account &a) {
  vc.push_back(a);
  write_file();
}

bool NumberBook::Book::has_account(const Account &a) {
  for (Account aa : vc) {
    if (aa.name == a.name)
      return true;
  }
  return false;
}
void NumberBook::Book::list_all() {
  cout << "==============List=============\n";
  for (Account a : vc)
    cout << a << "--\n";
  cout << endl;
}

void NumberBook::Book::search_account(string name) {
  for (Account a : vc) {
    if (a.name == name) {
      cout << "Found!" << endl;
      cout << a;
      return;
    }
  }
  cout << name << " Not Found!" << endl;
}

void NumberBook::Book::delete_account(string name) {
  vector<Account>::iterator it = vc.begin();
  for (int i = 0; i < vc.size(); ++i, ++it) {
    if (vc.at(i).name == name) {
      vc.erase(it);
      write_file();
      cout << name << " Deleted!" << endl;
      return;
    }
  }
  cout << name << " Not Found!\n";
}

void NumberBook::Book::write_file() {
  fh.os.open(fh.file_name, ofstream::out);
  for (Account a : vc)
    fh.os << a;
  fh.os.close();
}

void NumberBook::Book::read_file() {
  fh.is.open(fh.file_name);
  vc.clear();
  Account tmp;
  while (fh.is >> tmp) {
    vc.push_back(tmp);
  }
}

ostream &NumberBook::operator<<(ostream &os, const Account &a) {
  os << a.name << endl;
  os << a.email << endl;
  os << a.number << endl;
  return os;
}

ofstream &NumberBook::operator<<(ofstream &os, const Account &a) {
  os << a.name << endl;
  os << a.email << endl;
  os << a.number << endl;
  return os;
}
ifstream &NumberBook::operator>>(ifstream &is, Account &a) {
  is >> a.name;
  is >> a.email;
  is >> a.number;
  return is;
}