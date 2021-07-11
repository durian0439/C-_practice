#include <iostream>
#include <cstring>
#include <string>

using namespace std;
const int NAME_LEN = 20;


void ShowMenu(); //메뉴출력
void MakeAccount(); // 계좌 생성
void DepositMoney(); // 입금
void WithDrawMoney();// 출금
void ShowAllAccInfo(); // 잔액조회

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

struct Account {
	int accID; //계좌번호
	int balance; //잔액
	char cusName[NAME_LEN]; // 고객 이름
};

Account accArr[100]; // Account 저장을 위한 배열
int accNum = 0; //고객번호


int main() {

	int choice;

	while (true) {
		ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch(choice) {
			case MAKE:
				MakeAccount();
				break;
			case DEPOSIT:
				DepositMoney();
				break;
			case WITHDRAW:
				WithDrawMoney();
				break;
			case INQUIRE:
				ShowAllAccInfo();
				break;
			case EXIT:
				return 0;
			default:
				cout << "Illegal selection.." << endl;
		}
	}
}

void ShowMenu() {
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌 계설" << endl;
	cout <<"2. 입금" << endl;
	cout <<"3. 출금" << endl;
	cout <<"4. 계좌 정보" << endl;
	cout <<"5. 프로그램 종료" << endl;
}

void MakeAccount(){
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌계설]" << endl;
	cout << "계좌 ID"; cin >> id;
	cout << "이름"; cin >> name;
	cout << "입금액"; cin >> balance;
	cout << endl;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy_s(accArr[accNum].cusName, name);
	accNum++;
}

void DepositMoney() {
	int money;
	int id;
	cout << "[입금]" << endl;
	cout << "계좌 ID"; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i << accNum; i++) {
		if (accArr[i].accID == id) {
			accArr[i].balance += money;
			cout << "입금 완료" << endl<< endl;
			return;
		}
	}
}

void WithDrawMoney() {

	int money, id;

	cout << "출금" << endl;
	cout << "계좌 ID"; cin >> id;
	cout << "출금액"; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			if (accArr[i].balance < money) {
				cout << " 잔액이 부족합니다." << endl << endl;
				return;
			}
			accArr[i].balance -= money;
			cout << "출금완료" << endl << endl;
			return;
		}
		cout << "유효하지 않은 ID 입니다." << endl << endl;
	}
}

void ShowAllAccInfo() {
	for (int i = 0; i < accNum; i++) {
		cout << "계좌ID: " << accArr[i].accID << endl;
		cout << "이름: " << accArr[i].cusName << endl;
		cout << "잔액: " << accArr[i].balance << endl;
	}
}