// Created by 송은서 on 24. 10. 16.
//
#include <iostream>
#include "BankAccount.h"

void displayMenu() {
    std::cout << "====== MENU =======\n";
    std::cout << "1: 입금\n";
    std::cout << "2: 출금\n";
    std::cout << "3: 잔액조회\n";
    std::cout << "4: 계좌정보 출력\n";
    std::cout << "5: 거래내역 조회\n";
    std::cout << "6: 종료\n";
    std::cout << "====================\n";
    std::cout << "원하시는 작업을 선택하세요: ";
}

int main() {
    BankAccount account;
    std::string accNumber, accName;

    std::cout << "계좌 번호를 입력하세요: ";
    std::cin >> accNumber;
    std::cout << "계좌 소유자 이름을 입력하세요: ";
    std::cin >> accName;

    // 초기 계좌 정보에서 현재 잔액은 0으로 설정
    account.init(accNumber, accName);

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int depositAmount;
                std::cout << "입금할 금액을 입력하세요: ";
                std::cin >> depositAmount;
                account.deposit(depositAmount);
                break;
            }
            case 2: {
                int withdrawAmount;
                std::cout << "출금할 금액을 입력하세요: ";
                std::cin >> withdrawAmount;
                account.withdraw(withdrawAmount);
                break;
            }
            case 3: {
                std::cout << "현재 잔액: " << account.displayBalance() << "원\n";
                break;
            }
            case 4: {
                account.displayAccountInfo();
                break;
            }
            case 5: {
                account.displayAccountHistory();
                break;
            }
            case 6: {
                std::cout << "프로그램을 종료합니다.\n";
                break;
            }
            default:
                std::cout << "잘못된 선택입니다. 다시 시도하세요.\n";
        }
    } while (choice != 6);

    return 0;
}
