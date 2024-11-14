#ifndef WALLET_H
#define WALLET_H

#include <string>
#include <vector>
#include "User.h"
using namespace std;

class Wallet
{
private:
    vector<User> users;
    int transactionCount;

public:
    Wallet();

    void registerUser(const string &username, const string &password, const string &name, float amt);
    User *getUser(const string &username, const string &password);

    bool addFunds(const string &username, float amount);
    bool deductFunds(const string &username, float amount);

    bool transferFunds(const string &senderID, const string &receiverID, float amount, const string &date);

    bool removeUser(const string &username);
    void mergeAccounts(const string &username1, const string &username2);

    void loadUsers();
    void saveUsers();
};

#endif
