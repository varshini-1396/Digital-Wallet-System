#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Transaction.h"

using namespace std;

class User
{
private:
    string username;
    string password;
    string name;
    float balance;
    vector<Transaction> transactionHistory;

public:
    User(const string &username, const string &password, const string &name, float balance);

    const string &getUsername() const; // Return as const reference to avoid unnecessary copying
    const string &getPassword() const;
    const string &getName() const;
    float getBalance() const;
    bool matches(const string &username, const string &password) const; // Only one declaration of matches function

    void addFunds(float amount);
    bool deductFunds(float amount);
    void addTransaction(const Transaction &transaction);
    void showTransactionHistory() const; // Show transaction history
    void showBalance() const;
};

#endif
