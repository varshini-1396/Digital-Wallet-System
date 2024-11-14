#include "Wallet.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm> // Added for std::remove
using namespace std;

Wallet::Wallet()
{
    loadUsers();
}

void Wallet::loadUsers()
{
    ifstream file("users.txt");
    if (!file)
        return; // No file found, skip loading

    User user("", "", 0.0f);
    while (file >> user)
    {
        users.push_back(user);
    }
    file.close();
}

void Wallet::saveUsers()
{
    ofstream file("users.txt", ios::trunc);
    for (const auto &user : users)
    {
        file << user;
    }
    file.close();
}

void Wallet::registerUser(const string &userID, const string &name, float amt)
{
    if (getUser(userID) != nullptr)
    {
        cout << "User ID " << userID << " already exists. Please use a unique User ID." << endl;
        return;
    }
    users.push_back(User(userID, name, amt));
    cout << "User " << name << " registered successfully with ID: " << userID << endl;
    saveUsers();
}

User *Wallet::getUser(const string &userID)
{
    for (auto &user : users)
    {
        if (user.getUserID() == userID)
            return &user;
    }
    return nullptr;
}

void Wallet::addFunds(const string &userID, float amount)
{
    User *user = getUser(userID);
    if (user)
    {
        *user += amount;
        cout << "Added " << amount << " to " << userID << "'s wallet." << endl;
        saveUsers();
    }
    else
    {
        cout << "User not found!" << endl;
    }
}

bool Wallet::transferFunds(const string &senderID, const string &receiverID, float amount, const string &date)
{
    User *sender = getUser(senderID);
    User *receiver = getUser(receiverID);

    if (!sender || !receiver)
    {
        cout << "Sender or receiver not found!" << endl;
        return false;
    }

    if (!sender->deductBalance(amount))
    {
        cout << "Insufficient balance in " << senderID << "'s wallet!" << endl;
        return false;
    }

    *receiver += amount;

    transactionCount++;
    Transaction transaction(transactionCount, amount, date, senderID, receiverID);
    sender->addTransaction(transaction);
    receiver->addTransaction(transaction);

    cout << "Transfer successful from " << senderID << " to " << receiverID << " for amount " << amount << endl;
    saveUsers();
    return true;
}

bool Wallet::removeUser(const string &userID)
{
    auto it = remove_if(users.begin(), users.end(), [&](const User &u)
                        { return u.getUserID() == userID; });
    if (it != users.end())
    {
        users.erase(it, users.end());
        cout << "User with ID " << userID << " has been removed.\n";
        saveUsers();
        return true;
    }
    cout << "User with ID " << userID << " not found.\n";
    return false;
}

void Wallet::mergeAccounts(const string &userID1, const string &userID2)
{
    User *user1 = getUser(userID1);
    User *user2 = getUser(userID2);

    if (!user1 || !user2)
    {
        cout << "One or both users not found!" << endl;
        return;
    }

    User mergedUser = *user1 + *user2;
    users.erase(remove_if(users.begin(), users.end(), [&](const User &u)
                          { return u.getUserID() == userID1 || u.getUserID() == userID2; }),
                users.end());

    users.push_back(mergedUser);

    cout << "Accounts merged successfully:\n"
         << mergedUser;
    saveUsers();
}
