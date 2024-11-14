#include "Transaction.h"
#include <iostream>
using namespace std;

Transaction::Transaction(int id, float amt, string d, string sID, string rID)
    : transactionID(id), amount(amt), date(d), senderID(sID), receiverID(rID) {}

void Transaction::displayTransaction() const
{
    cout << "Transaction ID: " << transactionID
         << " | Amount: " << amount
         << " | Date: " << date
         << " | Sender: " << senderID
         << " | Receiver: " << receiverID << endl;
}

ostream &operator<<(ostream &os, const Transaction &transaction) {
    os << transaction.transactionID << " " << transaction.amount << " "
       << transaction.date << " " << transaction.senderID << " " << transaction.receiverID << "\n";
    return os;
}
