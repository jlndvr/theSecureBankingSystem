#include <iostream>
#include <vector>
#include <string>
#include "BankAccount.hpp"
using namespace std;

class Bank {
  private:
  vector<BankAccount> accounts;
  string accountNumber;
  double initialBalance;
  
  public:
  void createAccount(string accountNumber, double initialBalance);
  BankAccount* findAccount(const string& accountNumber);
  int transferMoney(const string& sourceAccountNumber, const string& targetAccountNumber, double amount);
};
