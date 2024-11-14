#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Transaction.h"
using namespace std;

class User
{
    string userID;
    string name;
    float balance;
    vector<Transaction> transactions;

public:
    User(string id, string nm, float initialBalance);
    User &operator+=(float amount); // Overloaded operator for adding balance
    bool deductBalance(float amount);
    void addTransaction(const Transaction &transaction);
    void showBalance() const;
    void showTransactionHistory() const;
    string getUserID() const { return userID; }
    friend ostream &operator<<(ostream &os, const User &user);
    friend istream &operator>>(istream &is, User &user);
    User operator+(const User &other) const;
    float getBalance() const { return balance; }
};

#endif
