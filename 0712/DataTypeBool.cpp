#include <iostream>

using namespace std;

bool IsPositive(int num) {
	if (num <= 0) {
		return false;
	}
	else
		return true;
}

int main() {

	bool isPos;
	int num;
	cout << "input Num : ";
	cin >> num;

	isPos = IsPositive(num);
	if (isPos)
		cout << "Positive number" << endl;
	else
		cout << "Negative Number" << endl;



}