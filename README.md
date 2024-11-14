
# Digital Wallet Management System

This project is made by Team xx, a simple Digital Wallet Management System implemented in C++ that allows users to create accounts, transfer funds, view transaction history, and manage wallet balances. The system is designed to be a basic simulation of a wallet system with features such as user registration, money transfers, account merging, and transaction tracking.

## Features

- **User Registration**: Allows users to register with a unique ID, name, and an initial balance.
- **Fund Transfer**: Users can send funds from their wallet to another user's wallet. The system tracks each transaction with an ID, date, sender, and receiver.
- **Transaction History**: Users can view their past transactions.
- **Balance Management**: Users can view their current balance, add funds, or deduct balances.
- **Account Merging**: Two users' accounts can be merged into one, combining their balances and transactions.
- **Data Persistence**: User data and transactions are saved to a file (`users.txt`), ensuring that the data is persistent across sessions.

## Files in the Project

- **Transaction.h / Transaction.cpp**: Contains the `Transaction` class, which defines the structure and functionality of a transaction (ID, amount, sender, receiver, and date).
- **User.h / User.cpp**: Contains the `User` class, which defines a user, their balance, transactions, and associated methods (e.g., adding funds, viewing balance, transaction history).
- **Wallet.h / Wallet.cpp**: Contains the `Wallet` class, which manages the entire system of users, allowing for registration, fund transfers, user removal, and account merging.
- **Makefile**: A build file used for compiling the project. It specifies compiler flags, object files, and build targets.

## Compilation and Usage

### Prerequisites

Ensure that you have a C++ compiler installed (e.g., `g++` for Linux or macOS). The code has been tested with C++11 standard, so make sure to compile with at least this version.

### Building the Project

1. Open a terminal and navigate to the directory containing the project files.
2. Run the following command to compile the project:

   ```bash
   make
   ```

   This will generate the executable `DigitalWalletSystem`.

### Running the Program

Once the build is complete, you can run the program by typing:

```bash
./DigitalWalletSystem
```

This will start the wallet management system, allowing you to register users, add funds, transfer money, and perform other actions.

### Makefile Commands

- **Build**: `make` - Compiles the source code and generates the executable.
- **Clean**: `make clean` - Removes object files and the executable.

### Data Persistence

The project uses a file named `users.txt` to store user data and transactions. This file is created when the program is run for the first time and is automatically updated when users are added or transactions are made.

## Example Usage

Here’s an example of how the wallet system works:

1. **Register Users**:
   ```cpp
   wallet.registerUser("user1", "Alice", 100.0);
   wallet.registerUser("user2", "Bob", 50.0);
   ```

2. **Add Funds**:
   ```cpp
   wallet.addFunds("user1", 20.0);
   ```

3. **Transfer Funds**:
   ```cpp
   wallet.transferFunds("user1", "user2", 30.0, "2024-11-14");
   ```

4. **Show Transaction History**:
   ```cpp
   user1.showTransactionHistory();
   user2.showTransactionHistory();
   ```

5. **Merge Accounts**:
   ```cpp
   wallet.mergeAccounts("user1", "user2");
   ```

## Structure and Classes

### `Transaction` Class

Represents a transaction with the following attributes:

- `transactionID`: Unique identifier for the transaction.
- `date`: Date of the transaction.
- `senderID`: ID of the user sending the money.
- `receiverID`: ID of the user receiving the money.
- `amount`: The amount of money transferred.

Methods:
- `displayTransaction()`: Prints the transaction details.
- Overloaded `<<` operator to write transactions to a file.

### `User` Class

Represents a user with the following attributes:

- `userID`: Unique identifier for the user.
- `name`: The user's name.
- `balance`: The user's current balance.
- `transactions`: A list of transactions the user has made or received.

Methods:
- `operator+=()`: Overloaded operator to add funds to the user’s balance.
- `deductBalance()`: Deducts an amount from the user’s balance if sufficient funds exist.
- `addTransaction()`: Adds a transaction to the user's history.
- `showBalance()`: Displays the user's current balance.
- `showTransactionHistory()`: Displays the user's transaction history.
- `operator+()`: Merges the account of two users.

### `Wallet` Class

Manages all users and their transactions:

- `registerUser()`: Registers a new user.
- `getUser()`: Retrieves a user by their ID.
- `addFunds()`: Adds funds to a user's wallet.
- `transferFunds()`: Transfers funds between two users.
- `removeUser()`: Removes a user from the system.
- `mergeAccounts()`: Merges two user accounts into one.

## Contributing

Feel free to fork the repository and submit pull requests for improvements or new features. If you find any bugs, please report them in the Issues section.

## License

This project is open-source.

## Contact

For any questions or suggestions, please contact the project maintainer at cs23b1015@iiitdm.ac.in.
