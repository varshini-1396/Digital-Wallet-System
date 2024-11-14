#include <iostream>
#include "Wallet.h"
using namespace std;

int main()
{
    Wallet wallet;
    int choice;

    do
    {
        cout << "\n--- Digital Wallet Menu ---\n";
        cout << "1. Register User\n";
        cout << "2. Add Funds\n";
        cout << "3. Deduct Funds\n";
        cout << "4. Transfer Funds\n";
        cout << "5. Show Balance\n";
        cout << "6. Show Transaction History\n";
        cout << "7. Merge Accounts\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string userID, userID2, name, date;
        float amount;

        switch (choice)
        {
        case 1:
            cout << "Enter User ID: ";
            cin >> userID;
            cout << "Enter Name: ";
            cin >> ws;
            getline(cin, name);
            cout << "Enter Initial Balance: ";
            cin >> amount;
            wallet.registerUser(userID, name, amount);
            break;

        case 2: // Add Funds
            cout << "Enter User ID: ";
            cin >> userID;
            cout << "Enter Amount to Add: ";
            cin >> amount;
            wallet.addFunds(userID, amount);
            break;

        case 3: // Deduct Funds
            cout << "Enter User ID: ";
            cin >> userID;
            cout << "Enter Amount to Deduct: ";
            cin >> amount;
            if (wallet.getUser(userID) && wallet.getUser(userID)->deductBalance(amount))
            {
                cout << "Deducted " << amount << " from " << userID << "'s wallet.\n";
                wallet.getUser(userID)->showBalance();
            }
            else
            {
                cout << "Insufficient balance or user not found.\n";
            }
            break;

        case 4: // Transfer Funds
            cout << "Enter Sender User ID: ";
            cin >> userID;
            cout << "Enter Receiver User ID: ";
            cin >> userID2;
            cout << "Enter Amount to Transfer: ";
            cin >> amount;
            cout << "Enter Date: ";
            cin >> ws;
            getline(cin, date);
            wallet.transferFunds(userID, userID2, amount, date);
            break;

        case 5: // Show Balance
            cout << "Enter User ID: ";
            cin >> userID;
            if (wallet.getUser(userID))
            {
                wallet.getUser(userID)->showBalance();
            }
            else
            {
                cout << "User not found.\n";
            }
            break;

        case 6: // Show Transaction History
            cout << "Enter User ID: ";
            cin >> userID;
            if (wallet.getUser(userID))
            {
                wallet.getUser(userID)->showTransactionHistory();
            }
            else
            {
                cout << "User not found.\n";
            }
            break;

        case 7: // Merge Accounts
            cout << "Enter First User ID: ";
            cin >> userID;
            cout << "Enter Second User ID: ";
            cin >> userID2;
            wallet.mergeAccounts(userID, userID2);
            break;

        case 0:
            cout << "Exiting Digital Wallet. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
