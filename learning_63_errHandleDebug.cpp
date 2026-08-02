// BUGGED CODE---------------------------------------------------------

// #include <iostream>
// #include <stdexcept>

// void riskyNetworkWrite() {
//     throw std::runtime_error("Network Timeout!");
// }

// class BankAccount {
// public:
//     double balance = 1000.0;
//     double* dynamicLog = nullptr;

//     BankAccount() { dynamicLog = new double[5]{}; }
//     ~BankAccount() { delete[] dynamicLog; }

//     // BUGGED FUNCTION
//     void applyBonus(double bonusAmount) {
//         balance += bonusAmount; // State modified immediately
        
//         riskyNetworkWrite();    // If this throws...
        
//         dynamicLog[0] = bonusAmount; 
//     }
// };

// int main() {
//     BankAccount account;
//     try {
//         account.applyBonus(500.0);
//     } catch (...) {
//         std::cout << "Transaction failed!\n";
//         // CRITICAL CHECK: Did the account roll back or corrupt?
//         std::cout << "Account Balance: " << account.balance << "\n"; 
//     }
//     return 0;
// }

// FIXED CODE----------------------------------------------------------
#include <iostream>
#include <stdexcept>

void riskyNetworkWrite() {
    throw std::runtime_error("Network Timeout!");
}

class BankAccount {
public:
    double balance = 1000.0;
    double* dynamicLog = nullptr;

    BankAccount() { dynamicLog = new double[5]{}; }
    ~BankAccount() { delete[] dynamicLog; }

    // BUGGED FUNCTION
    // explanation: this function directly modifies balance before realising its bugged, thus the banking logic breaks
    //for strong exception garuntee, we should override variables after the exceptional case
    // void applyBonus(double bonusAmount) {
    //     balance += bonusAmount; // State modified immediately
        
    //     riskyNetworkWrite();    // If this throws...
        
    //     dynamicLog[0] = bonusAmount; 
    // }

    void applyBonus(double bonusAmount) {
        double tbalance = this->balance;
        tbalance += bonusAmount; // State modified immediately
        
        riskyNetworkWrite();
        this->balance = tbalance;    // If this throws...
        
        *(this->dynamicLog)= bonusAmount; 
    }
};

int main() {
    BankAccount account;
    try {
        account.applyBonus(500.0);
    } catch (...) {
        std::cout << "Transaction failed!\n";
        // CRITICAL CHECK: Did the account roll back or corrupt?
        std::cout << "Account Balance: " << account.balance << "\n"; 
    }
    return 0;
}
