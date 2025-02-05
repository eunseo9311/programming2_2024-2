//
// Created by 송은서 on 24. 10. 16.
//

#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount() : balance(0.0), transactionCount(0) {}

void BankAccount::init(const std::string &accNumber, const std::string &accName) {
    accountNumber = accNumber;
    accountName = accName;
    balance = 0.0; // 초기 잔액을 0으로 설정
    std::cout << "==== 계좌 정보 ====\n";
    std::cout << "계좌 번호: " << accountNumber << "\n";
    std::cout << "계좌 소유자: " << accountName << "\n";
    std::cout << "현재 잔액: 0원\n";
    std::cout << "===================\n";
}

void BankAccount::deposit(int amount) {
    balance += amount;
    transactionCount++;
    addTransactionToHistory(std::to_string(amount) + "원이 입금되었습니다.");
    applyInterest();
}

void BankAccount::withdraw(int amount) {
    if (amount > balance) {
        std::cout << "잔액이 부족하여 출금할 수 없습니다.\n";
        return;
    }
    balance -= amount;
    transactionCount++;
    addTransactionToHistory(std::to_string(amount) + "원이 출금되었습니다.");
    applyInterest();
}

int BankAccount::displayBalance() const {
    return balance;
}

void BankAccount::displayAccountInfo() const {
    std::cout << "==== 계좌 정보 ====\n";
    std::cout << "계좌 번호: " << accountNumber << "\n";
    std::cout << "계좌 소유자: " << accountName << "\n";
    std::cout << "현재 잔액: " << balance << "원\n";
    std::cout << "===================\n";
}

void BankAccount::displayAccountHistory() const {
    std::cout << "==== 거래 내역 ====\n";
    for (const auto &entry : history) {
        std::cout << entry << "\n";
    }
    std::cout << "===================\n";
}

void BankAccount::addTransactionToHistory(const std::string &transaction) {
    history.push_back(transaction);
}

void BankAccount::applyInterest() {
    if (transactionCount % 3 == 0) {
        int interest = balance * 0.001;
        balance += interest;
        std::cout << "이자가 지급되었습니다: " << interest << "원\n";
    }
}
