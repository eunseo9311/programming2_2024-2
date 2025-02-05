1. 프로그램 개요
이 코드는 은행 계좌 시스템을 모델링한 C++ 프로그램입니다. BankAccount라는 기본 클래스를 중심으로, SavingsAccount와 MinusAccount라는 두 개의 파생 클래스가 각각 저축 계좌와 마이너스 계좌의 특징을 구현합니다.프로그램은 은행 계좌 생성, 입출금, 이자 계산, 자금 이체 등의 기능을 포함하며, 총 계좌 수와 총 잔액을 관리 및 출력하는 기능도 제공합니다.


2. 클래스 설명
BankAccount클래스 (기본 클래스)

주요 변수
static int totalAccounts: 총 계좌 수를 저장합니다.
static double totalBalance: 은행의 총 잔액을 저장합니다.
string accountNumber: 계좌 번호를 저장합니다.
string ownerName: 계좌 소유자의 이름을 저장합니다.
double balance: 계좌의 현재 잔액을 저장합니다.

주요 기능
생성자 (BankAccount): 계좌 생성 시, totalAccounts와 totalBalance를 갱신합니다.
소멸자 (~BankAccount): 계좌 삭제 시, totalAccounts와 totalBalance를 감소시킵니다.
deposit(double amount): 계좌에 입금된 금액을 잔액과 totalBalance에 반영합니다.
withdraw(double amount): 잔액이 충분할 경우, 출금을 처리하며 totalBalance를 갱신합니다. 잔액이 부족할 경우 경고 메시지를 출력합니다.
static displayBankStats(): 총 계좌 수와 총 잔액을 출력합니다.
operator<<: 계좌 정보를 출력하기 위해 연산자를 오버로딩합니다.


SavingsAccount클래스 (저축 계좌)
추가 변수
double interestRate: 저축 계좌의 이자율을 저장합니다.

추가 기능
생성자 (SavingsAccount): BankAccount의 생성자를 호출하여 기본 정보를 초기화하고, 이자율을 설정합니다.
applyInterest(): 잔액에 이자율을 곱해 계산된 이자를 deposit()을 통해 잔액에 반영합니다.


MinusAccount클래스 (마이너스 계좌)
추가 변수
double minusLimit: 마이너스 계좌의 한도 금액을 저장합니다.
추가 기능
생성자 (MinusAccount): BankAccount의 생성자를 호출하여 기본 정보를 초기화하고, 마이너스 한도를 설정합니다.
withdraw(double amount): 출금 시 잔액이 마이너스 한도를 초과하지 않을 경우에만 출금을 허용합니다. 초과 시 경고 메시지를 출력합니다.


3. 주요 기능 설명
입출금
deposit(double amount): 계좌에 입금된 금액을 잔액과 총 잔액에 반영합니다.
withdraw(double amount): 잔액 확인 후, 출금을 처리하거나 부족 시 경고 메시지를 출력합니다.

이자 계산
applyInterest(): 저축 계좌의 잔액에 이자율을 곱하여 이자를 계산한 후, 해당 금액을 계좌에 추가합니다.

자금 이체
transferFunds(BankAccount& from, BankAccount& to, double amount): 출금 계좌에서 금액을 인출하고, 입금 계좌에 해당 금액을 추가합니다.

은행 통계
static displayBankStats(): 총 계좌 수와 총 잔액을 출력하는 정적 메서드입니다.


4. 코드 실행 흐름
계좌 생성
SavingsAccount와 MinusAccount객체를 생성하여 총 계좌 수와 총 잔액을 증가시킵니다.
초기 은행 통계 출력
displayBankStats()를 호출하여 초기 상태를 확인합니다.

입출금 및 이자 적용
저축 계좌에 500원을 입금하고(deposit()), 마이너스 계좌에서 600원을 출금합니다(withdraw()).
저축 계좌의 이자를 계산하여 잔액에 추가합니다(applyInterest()).

계좌 정보 출력
operator<<를 통해 각 계좌 정보를 출력합니다.
자금 이체
transferFunds()를 호출하여 저축 계좌에서 마이너스 계좌로 200원을 이체합니다.
최종 은행 통계 출력
displayBankStats()를 호출하여 모든 작업 후의 은행 상태를 출력합니다.


5. 프로그램의 특징
객체 지향 설계: 상속, 다형성, 정적 멤버 변수 등을 활용하여 은행 시스템을 구조적으로 구현하였습니다.
코드 재사용성: 기본 클래스를 확장하여 다양한 계좌 유형을 손쉽게 구현할 수 있습니다.
출력 최적화: 연산자 오버로딩(operator<<)으로 계좌 정보를 간단하게 출력 가능합니다.
안전성 확보: 출금 시 잔액 초과 여부를 검사하여 안정적인 동작을 보장합니다.


6. 결론
이 프로그램은 객체 지향 프로그래밍의 개념을 활용하여 은행 계좌 시스템을 효과적으로 설계하였습니다. BankAccount클래스를 통해 계좌 관리의 기본 동작을 정의하고, 이를 상속하여 SavingsAccount와 MinusAccount클래스에서 각각 저축 및 마이너스 계좌의 특성을 구현하였습니다.이 프로그램은 확장 가능하며, 실용적인 은행 시스템을 시뮬레이션하기에 적합한 구조를 가지고 있습니다.