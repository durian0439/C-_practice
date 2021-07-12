#include <iostream>

using namespace std;

int main() {

	int num = 12;
	int* ptr = &num;
	int** dptr = &ptr;
	int *ptr = &num;

	int& ref = num;
	int* (&pref) = ptr;
	int** (&dpref) = dptr;

	/*cout << ref << endl;
	cout << *pref << endl;
	cout << **dpref << endl;*/


	cout << num << endl;
	cout << *ptr << endl;
	cout << **dptr << endl;
    
}
// ptr의 개념이 흔들린다.
//내가하는 포인터는 ptr = &num이고, *ptr = num인데 왜 이렇게 되는거지