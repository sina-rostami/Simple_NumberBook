#include "NumberBook.cpp"
#include <fstream>
#include <iostream>
#include <vector>
using NumberBook::Account;
using NumberBook::Book;
using std::cin;
using std::cout;

void menu() {
  cout << "=============Welcome============\n"
       << "1.add account\n"
       << "2.delete account\n"
       << "3.search in accounts\n"
       << "4.list all accounts\n"
       << "5.exit\n"
       << "enter the number of your choice : ";
}

void handle_add(Book &book) {
  string name, email, number;
  cout << "Enter Full Name : ";
  cin >> name;
  cout << "Enter Email Address : ";
  cin >> email;
  cout << "Enter Phone Number : ";
  cin >> number;
  Account tmp(name, email, number);
  if (!book.has_account(tmp)) {
    book.add_account(tmp);
    cout << "Added!\n";
  } else {
    cout << name << " is already in number book\n";
  }
}

void handle_delete(Book &book) {
  string name;
  cout << "Enter Full Name : ";
  cin >> name;
  book.delete_account(name);
}

void handle_search(Book &book) {
  string name;
  cout << "Enter Full Name : ";
  cin >> name;
  book.search_account(name);
}

int main() {
  char choice;
  Book my_book;
  my_book.read_file();
  while (true) {
    menu();
    cin >> choice;
    switch (choice) {
    case '1':
      handle_add(my_book);
      break;
    case '2':
      handle_delete(my_book);
      break;
    case '3':
      handle_search(my_book);
      break;
    case '4':
      my_book.list_all();
      break;
    case '5':
      return 0;
      break;
    default:
      cout << "Oops! wrong Input! try again!\n";
      break;
    }
  }

  return 0;
}