#include "Transaction.h"

Transaction::Transaction(int id, float amt, const string &d, const string &sender, const string &receiver)
    : transactionID(id), amount(amt), date(d), senderID(sender), receiverID(receiver) {}

void Transaction::displayTransaction() const
{
    cout << "Transaction ID: " << transactionID << ", Amount: " << amount
         << ", Date: " << date << ", From: " << senderID << " to " << receiverID << endl;
}

int Transaction::getTransactionID() const { return transactionID; }

string Transaction::getSenderID() const { return senderID; }

string Transaction::getReceiverID() const { return receiverID; }
