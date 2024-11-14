#include "Wallet.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm> // This header is required for remove_if
using namespace std;

Wallet::Wallet() : transactionCount(0)
{
    loadUsers();
}

void Wallet::loadUsers()
{
    ifstream file("users.txt");
    string username, password, name;
    float balance;

    while (file >> username >> password >> name >> balance)
    {
        users.push_back(User(username, password, name, balance));
    }
}

void Wallet::saveUsers()
{
    ofstream file("users.txt");
    for (const auto &user : users)
    {
        file << user.getUsername() << " "
             << user.getPassword() << " "
             << user.getName() << " "
             << user.getBalance() << endl;
    }
}

void Wallet::registerUser(const string &username, const string &password, const string &name, float amt)
{
    users.push_back(User(username, password, name, amt));
    saveUsers();
}

User *Wallet::getUser(const string &username, const string &password)
{
    for (auto &user : users)
    {
        if (user.matches(username, password))
        {
            return &user;
        }
    }
    return nullptr;
}

bool Wallet::addFunds(const string &username, float amount)
{
    for (auto &user : users)
    {
        if (user.getUsername() == username)
        {
            user.addFunds(amount);
            saveUsers(); // Ensure the file is updated after adding funds
            return true;
        }
    }
    return false;
}

bool Wallet::deductFunds(const string &username, float amount)
{
    for (auto &user : users)
    {
        if (user.getUsername() == username)
        {
            bool result = user.deductFunds(amount);
            if (result)
            {
                saveUsers(); // Ensure the file is updated after deducting funds
            }
            return result;
        }
    }
    return false;
}

bool Wallet::transferFunds(const string &senderID, const string &receiverID, float amount, const string &date)
{
    User *sender = nullptr, *receiver = nullptr;

    for (auto &user : users)
    {
        if (user.getUsername() == senderID)
        {
            sender = &user;
        }
        else if (user.getUsername() == receiverID)
        {
            receiver = &user;
        }
    }

    if (sender && receiver && sender->deductFunds(amount))
    {
        // Add funds to the receiver's account
        receiver->addFunds(amount);

        // Create and log the transaction for both sender and receiver
        Transaction transaction(transactionCount++, amount, date, senderID, receiverID);
        sender->addTransaction(transaction);
        receiver->addTransaction(transaction);

        saveUsers(); // Ensure the file is updated after the transfer
        return true;
    }

    return false;
}

bool Wallet::removeUser(const string &username)
{
    auto it = remove_if(users.begin(), users.end(), [&](const User &user)
                        { return user.getUsername() == username; });
    if (it != users.end())
    {
        users.erase(it, users.end());
        saveUsers(); // Ensure the file is updated after removing a user
        return true;
    }
    return false;
}

void Wallet::mergeAccounts(const string &username1, const string &username2)
{
    User *user1 = nullptr, *user2 = nullptr;

    for (auto &user : users)
    {
        if (user.getUsername() == username1)
            user1 = &user;
        if (user.getUsername() == username2)
            user2 = &user;
    }

    if (user1 && user2)
    {
        user1->addFunds(user2->getBalance());
        user1->showBalance();
        removeUser(username2); // Remove the second account after merging
    }
}
