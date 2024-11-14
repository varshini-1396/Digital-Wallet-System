#include "User.h"
#include <iostream>
using namespace std;

User::User(string id, string nm, float initialBalance)
    : userID(id), name(nm), balance(initialBalance) {}

User &User::operator+=(float amount)
{
    balance += amount;
    return *this;
}

bool User::deductBalance(float amount)
{
    if (amount > balance)
        return false;
    balance -= amount;
    return true;
}

void User::addTransaction(const Transaction &transaction)
{
    transactions.push_back(transaction);
}

void User::showBalance() const
{
    cout << "User: " << name << " (ID: " << userID << ") Balance: " << balance << endl;
}

void User::showTransactionHistory() const
{
    cout << "Transaction History for " << name << ":" << endl;
    for (const auto &t : transactions)
    {
        t.displayTransaction();
    }
}

ostream &operator<<(ostream &os, const User &user)
{
    os << user.userID << " " << user.name << " " << user.balance << "\n";
    return os;
}

istream &operator>>(istream &is, User &user)
{
    is >> user.userID >> user.name >> user.balance;
    return is;
}

User User::operator+(const User &other) const
{
    User mergedUser(this->userID + "+" + other.userID, this->name + " & " + other.name, this->balance + other.balance);
    mergedUser.transactions = this->transactions;
    mergedUser.transactions.insert(mergedUser.transactions.end(), other.transactions.begin(), other.transactions.end());
    return mergedUser;
}
