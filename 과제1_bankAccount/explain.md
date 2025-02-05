은행 계좌 프로그램 보고서

1. 프로그램 개요
이 프로그램은 사용자가 은행 계좌 정보를 관리할 수 있도록 설계되었습니다. 사용자는 계좌 번호와 소유자 이름을 입력하고, 입금, 출금, 잔액 조회, 계좌 정보 출력, 거래 내역 조회 등의 작업을 수행할 수 있습니다. 또한, 이 프로그램은 세 번의 거래마다 잔액에 대한 이자를 자동으로 지급합니다.


2. 프로그램 구조
이 프로그램은 객체지향 프로그래밍기법을 활용하여 작성되었으며, 3개의 주요 파일로 구성됩니다:
1. 헤더 파일 (BankAccount.h): 클래스 정의와 멤버 함수의 선언을 포함합니다.
2. 클래스 파일 (BankAccount.cpp): BankAccount클래스의 세부 구현을 포함합니다.
3. 메인 파일 (main.cpp): 프로그램의 실행 흐름을 관리하는 메인 함수가 포함되어 있습니다.


3. 주요 클래스 및 함수 설명

3.1 BankAccount 클래스
BankAccount클래스는 계좌 정보를 저장하고 처리하는 역할을 합니다. 주요 멤버 변수와 함수는 다음과 같습니다.

3.1.1 멤버 변수
• std::string accountNumber: 계좌 번호를 저장하는 문자열.
• std::string accountName: 계좌 소유자의 이름을 저장하는 문자열.
• double balance: 계좌의 현재 잔액을 저장하는 변수. 초기화 시 잔액은 0으로 설정됩니다.
• int transactionCount: 총 거래 횟수를 기록하는 변수로, 이자 지급 시 사용됩니다.
• std::vector<std::string> history: 거래 내역을 저장하는 벡터로, 입금과 출금 기록을 남깁니다.
• 
3.1.2 멤버 함수
• void init(const std::string &accNumber, const std::string &accName): 계좌 번호와 소유자 이름을 초기화하고, 잔액을 0으로 설정한 후 계좌 정보를 출력합니다.
• void deposit(double amount): 입금된 금액을 잔액에 추가하고, 거래 내역에 기록을 남깁니다. 또한 거래 횟수에 따라 이자를 적용합니다.
• void withdraw(double amount): 출금할 금액이 잔액보다 크지 않은 경우 출금을 처리하고, 거래 내역에 기록을 남깁니다. 거래 횟수에 따라 이자를 적용합니다.
• double getBalance() const: 현재 잔액을 반환하는 함수로, 잔액 조회 시 사용됩니다.
• void displayAccountInfo() const: 계좌 번호, 소유자 이름, 잔액을 출력하는 함수입니다.
• void displayAccountHistory() const: 거래 내역을 출력하는 함수입니다.
• void applyInterest(): 거래 횟수가 3의 배수일 때, 잔액에 0.1%의 이자를 지급하는 함수입니다.



3.2 메뉴 시스템 (main.cpp)
main.cpp파일은 사용자 입력을 받아 프로그램을 제어하는 역할을 합니다.

3.2.1 계좌 정보 입력
// code 첨부함
std::cout << "계좌 번호를 입력하세요: ";
std::cin >> accNumber;
std::cout << "계좌 소유자 이름을 입력하세요: ";
std::cin >> accName;
account.init(accNumber, accName);

• 사용자가 프로그램 실행 후 계좌 번호와 소유자 이름을 입력합니다. 잔액은 따로 입력받지 않고 0원으로 초기화됩니다.

3.2.2 메뉴 출력
// code 첨부함
void displayMenu(){
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

• 이 함수는 사용자가 원하는 작업을 선택할 수 있도록 메뉴를 출력합니다.

3.2.3 입금 및 출금 처리
• 사용자가 입금을 선택하면 deposit()함수가 호출되어 금액이 잔액에 더해집니다.
• 사용자가 출금을 선택하면 withdraw()함수가 호출되어 금액이 잔액에서 차감됩니다. 잔액보다 많은 금액을 출금하려고 하면 오류 메시지가 출력됩니다.

// code 첨부함
case 1: {
    double depositAmount;
    std::cout << "입금할 금액을 입력하세요: ";
    std::cin >> depositAmount;
    account.deposit(depositAmount);
    break;
}
case 2: {
    double withdrawAmount;
    std::cout << "출금할 금액을 입력하세요: ";
    std::cin >> withdrawAmount;
    account.withdraw(withdrawAmount);
    break;
}

3.2.4 잔액 조회 및 계좌 정보 출력
• 사용자가 잔액조회를 선택하면 현재 잔액을 출력합니다.
• 사용자가 계좌정보 출력을 선택하면 계좌 번호, 소유자 이름, 잔액이 출력됩니다.

//code 첨부함
case 3: {
    std::cout << "현재 잔액: " << account.getBalance() << "원\n";
    break;
}
case 4: {
    account.displayAccountInfo();
    break;
}

3.2.5 거래 내역 조회
• 사용자가 거래내역 조회를 선택하면 입금 및 출금 내역이 기록된 대로 출력됩니다.
• 
// code 첨부함
case 5: {
    account.displayAccountHistory();
    break;
}