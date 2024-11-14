#include <iostream>
#include <string>
#include "Wallet.h"
#include "Transaction.h"
using namespace std;

int main()
{
    Wallet wallet;
    string username, password, name, date;
    float amount;

    while (true)
    {
        cout << "1. Login\n2. Register a new user\n3.Exit\nChoose an option: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            User *currentUser = wallet.getUser(username, password);
            if (currentUser)
            {
                cout << "Login successful! Welcome, " << currentUser->getName() << "." << endl;
                while (true)
                {
                    cout << "1. Add funds\n2. Deduct funds\n3. Transfer funds\n4. Show balance\n5. Show transaction history\n6. Merge accounts\n7. Logout\nChoose an option: ";
                    cin >> choice;

                    if (choice == 1)
                    {
                        cout << "Enter amount to add: ";
                        cin >> amount;
                        wallet.addFunds(username, amount);
                    }
                    else if (choice == 2)
                    {
                        cout << "Enter amount to deduct: ";
                        cin >> amount;
                        if (wallet.deductFunds(username, amount))
                        {
                            cout << "Deduction successful!" << endl;
                        }
                        else
                        {
                            cout << "Insufficient funds!" << endl;
                        }
                    }
                    else if (choice == 3)
                    {
                        string receiver;
                        cout << "Enter receiver username: ";
                        cin >> receiver;
                        cout << "Enter amount to transfer: ";
                        cin >> amount;
                        if (amount < 0)
                            cout << "Enter correct amount " << endl;
                        cout << "Enter date (YYYY-MM-DD): ";
                        cin >> date;

                        if (wallet.transferFunds(username, receiver, amount, date))
                        {
                            cout << "Transfer successful!" << endl;
                        }
                        else
                        {
                            cout << "Transfer failed!" << endl;
                        }
                    }
                    else if (choice == 4)
                    {
                        currentUser->showBalance();
                    }
                    else if (choice == 5)
                    {
                        currentUser->showTransactionHistory();
                    }
                    else if (choice == 6)
                    {
                        string username2;
                        cout << "Enter the username of the account to merge: ";
                        cin >> username2;
                        wallet.mergeAccounts(username, username2);
                    }
                    else if (choice == 7)
                    {
                        break;
                    }
                }
            }
            else
            {
                cout << "Invalid username or password.\n";
            }
        }
        else if (choice == 2)
        {
            cout << "Enter new username: ";
            cin >> username;
            cout << "Enter new password: ";
            cin >> password;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter initial balance: ";
            cin >> amount;
            wallet.registerUser(username, password, name, amount);
        }
        else
        {
            break;
        }
    }

    return 0;
}
