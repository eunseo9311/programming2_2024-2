#include <iostream>
#include <string>
using namespace std;


// Base class: 은행계좌 클래스
class BankAccount {
protected:
    static int totalAccounts; // 총 계좌 수
    static double totalBalance; // 총 잔액
    string accountNumber; // 계좌번호
    string ownerName; // 소유주
    double balance; // 계좌잔액


public:
    BankAccount(string accNum, string owner, double bal)
        : accountNumber(accNum), ownerName(owner), balance(bal) {
        totalAccounts++;
        totalBalance += bal;
    }

    virtual ~BankAccount() {
        totalAccounts--;
        totalBalance -= balance;
    }

    // 입금 함수
    void deposit(double amount) {
        balance += amount;
        totalBalance += amount;
    }

    // 출금 함수
    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            totalBalance -= amount;
        }
        else {
            cout << "잔액이 부족합니다.\n";
        }
    }


    // 총 계좌 수 정보, 총 계좌 잔액 정보
    static void displayBankStats() {
        cout << "총 계좌 수: " << totalAccounts << ", 총 잔액: " << totalBalance << endl;
    }

    friend ostream& operator<<(ostream& os, const BankAccount& account) {
        os << "계좌 번호: " << account.accountNumber
            << "\n소유자: " << account.ownerName
            << "\n잔액: " << account.balance << endl;
        return os;
    }
};


int BankAccount::totalAccounts = 0;
double BankAccount::totalBalance = 0.0;

// 저축용 계좌 클래스 (자식 클래스)
class SavingsAccount : public BankAccount {
    double interestRate; // 저축 이자율

public:
    SavingsAccount(string accNum, string owner, double bal, double rate)
        : BankAccount(accNum, owner, bal), interestRate(rate) {}

    // 이자 적용 함수
    void applyInterest() {
        double interest = balance * interestRate;
        deposit(interest);
    }
};


// 마이너스 계좌 클래스
class MinusAccount : public BankAccount {
    double minusLimit; // 출금 한도 금액

public:
    MinusAccount(string accNum, string owner, double bal, double limit)
        : BankAccount(accNum, owner, bal), minusLimit(limit) {}

    void withdraw(double amount) override {
        if (balance - amount >= -minusLimit) {
            balance -= amount;
            totalBalance -= amount;
        }
        else {
            cout << "마이너스 한도를 초과했습니다.\n";
        }
    }
};


// 계좌 간 자금 이체 함수
void transferFunds(BankAccount& from, BankAccount& to, double amount) {
    from.withdraw(amount);
    to.deposit(amount);
}


int main() {
    // 계좌 생성
    SavingsAccount acc1("SA001", "홍길동", 1000, 0.05);
    MinusAccount acc2("MA001", "이순신", 500, 200);


    // 초기 은행 통계 출력
    cout << "초기 계좌 통계:\n";
    BankAccount::displayBankStats();

    // 입금 및 출금 테스트
    acc1.deposit(500);
    acc2.withdraw(600); // 초과 인출 허용

    // 이자 적용
    acc1.applyInterest();

    // 계좌 정보 출력
    cout << "\n계좌 정보:\n";
    cout << acc1;
    cout << acc2;

    // 자금 이체
    transferFunds(acc1, acc2, 200);

    // 최종 은행 통계 출력
    cout << "\n최종 계좌 통계:\n";
    BankAccount::displayBankStats();

    return 0;
}