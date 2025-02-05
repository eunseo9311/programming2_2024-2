//
// Created by 송은서 on 24. 10. 16.
//

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <vector>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountName;
    int balance;
    int transactionCount;
    std::vector<std::string> history;

    void addTransactionToHistory(const std::string &transaction);

public:
    BankAccount();
    void init(const std::string &accNumber, const std::string &accName);
    void deposit(int amount);
    void withdraw(int amount);
    int displayBalance() const;
    void displayAccountInfo() const;
    void displayAccountHistory() const;
    void applyInterest();
};

#endif
