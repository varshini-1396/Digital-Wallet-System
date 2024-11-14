#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>
using namespace std;

class Transaction
{
    int transactionID;
    string date;
    string senderID;
    string receiverID;
    float amount;

    friend ostream &operator<<(ostream &os, const Transaction &transaction);

public:
    Transaction(int id, float amt, string d, string sID, string rID);
    void displayTransaction() const;
};

#endif
