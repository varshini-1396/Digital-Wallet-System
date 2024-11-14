#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>
using namespace std;

class Transaction
{
private:
    int transactionID;
    float amount;
    string date;
    string senderID;
    string receiverID;

public:
    Transaction(int id = 0, float amt = 0.0f, const string &d = "", const string &sender = "", const string &receiver = "");
    void displayTransaction() const;

    int getTransactionID() const;
    string getSenderID() const;
    string getReceiverID() const;
};

#endif
