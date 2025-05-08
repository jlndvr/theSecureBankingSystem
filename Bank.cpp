#include <iostream>
#include <vector>
#include <string>
#include "Bank.hpp"
using namespace std;

void Bank::createAccount(string accountNumber, double initialBalance) {
  BankAccount newAccount(accountNumber, initialBalance);
  accounts.push_back(newAccount);
}
BankAccount* Bank::findAccount(const string &accountNumber) {
  for (auto &account : accounts ) {
    if (account.get_accountNumber() == accountNumber) return &account;
  }
    cout << "-Account not found-" << endl;
    return nullptr;
}
int Bank::transferMoney(const string& sourceAccountNumber, const string& targetAccountNumber, double amount) {
  BankAccount* sourceAccount = findAccount(sourceAccountNumber);
  BankAccount* targetAccount = findAccount(targetAccountNumber);

  if (sourceAccount == nullptr || targetAccount == nullptr) return 2;  
  if (sourceAccount->get_balance() < amount) return 3;
  
  sourceAccount->set_balance(sourceAccount->get_balance() - amount);
  targetAccount->set_balance(targetAccount->get_balance() + amount);
  return 1;
}
