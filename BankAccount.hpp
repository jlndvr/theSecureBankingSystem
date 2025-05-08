#include <iostream>
#include <string>
using namespace std;

class BankAccount {
  private:
  string accountNumber;
  double balance;
  public:
  class Transaction {
    public:
    void deposit(BankAccount &account, double amount);
    void withdraw(BankAccount &account, double amount);
  };
  BankAccount(string _accountNumber, double _balance);
  void set_accountNumber(string _accountNumber);
  void set_balance(double _balance);
  string get_accountNumber();
  double get_balance();
};
