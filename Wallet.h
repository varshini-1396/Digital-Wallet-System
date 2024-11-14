#ifndef WALLET_H
#define WALLET_H

#include <string>
#include <vector>
#include "User.h"
using namespace std;

class Wallet
{
    vector<User> users;
    int transactionCount = 0;

public:
    Wallet(); // Constructor to load users from file
    void registerUser(const string &userID, const string &name, float amt);
    User *getUser(const string &userID);
    void addFunds(const string &userID, float amount);
    bool transferFunds(const string &senderID, const string &receiverID, float amount, const string &date);
    bool removeUser(const string &userID);
    void mergeAccounts(const string &userID1, const string &userID2);

private:
    void loadUsers(); // Load users from file
    void saveUsers(); // Save users to file
};

#endif
