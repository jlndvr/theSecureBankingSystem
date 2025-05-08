#include <iostream>
#include "Bank.hpp"
using namespace std;

int main() {
  /*
  1 indicates the transfer was successful.
  2 indicates that one or both of the accounts involved in the transfer were not found.
  3 indicates that there are insufficient funds in the source account for the transfer.
  */
    // 1. Test BankAccount Transactions directly
    cout << "=== Testing BankAccount Transactions ===" << endl;
    BankAccount testAcc("TEST001", 1000.0);
    BankAccount::Transaction testTrans;
    
    cout << "Initial balance: " << testAcc.get_balance() << endl;
    
    // Test deposit
    testTrans.deposit(testAcc, 500.0);
    cout << "After deposit: " << testAcc.get_balance() << endl;
    
    // Test withdrawal
    testTrans.withdraw(testAcc, 200.0);
    cout << "After withdrawal: " << testAcc.get_balance() << endl;
    
    // Test failed withdrawal
    testTrans.withdraw(testAcc, 2000.0);
    cout << "After failed withdrawal: " << testAcc.get_balance() << endl;

    // 2. Test Bank Operations
    cout << "\n=== Testing Bank Operations ===" << endl;
    Bank myBank;
    
    // Create accounts
    myBank.createAccount("ACC1001", 5000.0);
    myBank.createAccount("ACC1002", 3000.0);
    
    // Access accounts
    BankAccount* acc1 = myBank.findAccount("ACC1001");
    BankAccount* acc2 = myBank.findAccount("ACC1002");
    
    // Test transfers
    cout << "\nInitial balances:" << endl;
    cout << "ACC1001: " << acc1->get_balance() << endl;
    cout << "ACC1002: " << acc2->get_balance() << endl;
    
    cout << "\nTransferring $1000 from ACC1001 to ACC1002:" << endl;
    int result = myBank.transferMoney("ACC1001", "ACC1002", 1000.0);
    if (result == 1) {
        cout << "Transfer successful!" << endl;
        cout << "New balances:" << endl;
        cout << "ACC1001: " << acc1->get_balance() << endl;
        cout << "ACC1002: " << acc2->get_balance() << endl;
    }
    
    // Test failed transfer (non-existent account)
    cout << "\nTesting failed transfer:" << endl;
    result = myBank.transferMoney("ACC1001", "NONEXISTENT", 500.0);
    if (result == 2) cout << "Correctly failed: Account not found" << endl;
    
    // Test failed transfer (insufficient funds)
    result = myBank.transferMoney("ACC1002", "ACC1001", 5000.0);
    if (result == 3) cout << "Correctly failed: Insufficient funds" << endl;

    return 0;
    
}
