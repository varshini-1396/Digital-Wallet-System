#include "User.h"
#include <iostream>

User::User(const string &username, const string &password, const string &name, float balance)
    : username(username), password(password), name(name), balance(balance) {}

const string &User::getUsername() const
{
    return username;
}

const string &User::getPassword() const
{
    return password;
}

const string &User::getName() const
{
    return name;
}

float User::getBalance() const
{
    return balance;
}

bool User::matches(const string &username, const string &password) const
{
    return this->username == username && this->password == password;
}

void User::addFunds(float amount)
{
    balance += amount;
}

bool User::deductFunds(float amount)
{
    if (balance >= amount)
    {
        balance -= amount;
        return true;
    }
    return false;
}

void User::addTransaction(const Transaction &transaction)
{
    transactionHistory.push_back(transaction);
}

void User::showTransactionHistory() const
{
    cout << "Transaction History for " << username << ":\n";
    for (const auto &transaction : transactionHistory)
    {
        transaction.displayTransaction();
    }
}

void User::showBalance() const
{
    cout << "Balance for " << username << ": " << balance << endl;
}
