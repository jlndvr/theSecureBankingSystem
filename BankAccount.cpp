#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <iostream>
#include <string>
#include "BankAccount.hpp"
using namespace std;

void BankAccount::Transaction::deposit(BankAccount &account, double amount) {
  if (amount > 0) { 
  account.set_balance(account.get_balance() + amount);
  cout << "New balance: " << account.get_balance() << endl;
  }
  else cout << "-No amount to deposit-" << endl;
  }

void BankAccount::Transaction::withdraw(BankAccount &account, double amount) {
if (account.get_balance() < amount) cout << "-Insufficient funds-" << endl;
else { 
  account.set_balance(account.get_balance() - amount);
  cout << "New balance: " << account.get_balance() << endl;
}
}

BankAccount::BankAccount(string _accountNumber, double _balance) : accountNumber (_accountNumber) , balance (_balance) {}

void BankAccount::set_accountNumber(string _accountNumber) {
  accountNumber = _accountNumber;
}

void BankAccount::set_balance(double _balance) {
  balance = _balance;
}

string BankAccount::get_accountNumber() {
  return accountNumber;
}

double BankAccount::get_balance() {
  return balance;
}

#endif
